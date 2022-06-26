#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>
#include<string.h>
#include<semaphore.h>
#include<time.h>
#include<signal.h>



typedef enum prtype{
    Apples,
    Bread,
    Milk,
    Butter,
    Almonds
}prtype;

typedef struct product{
    uint barcode;
    double price;
    prtype type;
}product;

product pr[10];


void rndPrice(product*);
void rndCode(product*);
void rndType(product*);
double randdbl(double,double);


void exitSig(int);

sem_t semSup, semBuy;
pthread_mutex_t mux;

void *supply(void* prod){
    int i = 0;
    while(1){
        sleep(1);

        product *prd = (product *)prod;
        prd->price = randdbl(1.50, 25.60);
        prd->type = rand() % 6;
        prd->barcode = rand() % 100000;
        if(-1 == pr[i].barcode)
        {
            sem_wait(&semBuy);
            pthread_mutex_lock(&mux);
            pr[i] = *prd;
            pthread_mutex_unlock(&mux);
            printf("Supplied space %2d with type: %3d, price: %5.2lf, barcode: %6d\n\n",i, pr[i].type, pr[i].price, pr[i].barcode);
            sem_post(&semSup);
        }
        i++;
        if(i == 10){
            i = 0;
        }
    }
}

void *buy(void *prod){
    int i = 0;
    while(1){

        sleep(3);

        i = rand() % 10;
        product *p = (product *)prod + i;
        if(-1 != p->barcode)
        {
            sem_wait(&semSup);
            printf("Bought from space: %2d %3d, price: %5.2lf, barcode: %6d\n\n",i, p->type, p->price, p->barcode);
            pthread_mutex_lock(&mux);
            p->barcode = -1;
            pthread_mutex_unlock(&mux);
            sem_post(&semBuy);
        }
        else{
            i = rand() % 10;
        }
    }
        
}


int main(int argc, char **argv){


    //SIGNAL HANDLER
    signal(SIGINT, exitSig);

    //SEEDING THE RAND
    srand(time(NULL));

    //SEMAPHORES
    sem_init(&semSup, 0, 0);
    sem_init(&semBuy, 0, 10);

    //MUTEX
    pthread_mutex_init(&mux, NULL);

    //SETUP
    int customers, suppliers;
    if(NULL == argv[1] || NULL == argv[2]){
        customers = 6;
        suppliers = 5;
    }
    else{
        customers = atoi(argv[1]);
        suppliers = atoi(argv[2]);
    }

    printf("%d  %d\n", customers, suppliers);

    //BARCODE -1 MEANS EMPTY
    for (size_t i = 0; i < 10; i++)
    {
        pr[i].barcode = -1;
    }
    

    //THREADS
    pthread_t ptCustomers[customers], ptSuppliers[suppliers];

    for (size_t i = 0; i < suppliers; i++)
    {
        product temp;
        //printf("%d %d %lf\n", temp.type, temp.barcode, temp.price);
        if(pthread_create(&ptSuppliers[i], NULL, supply, &temp)){
            perror("Create: ");
            return EXIT_FAILURE;
        }
    }
    for (size_t i = 0; i < customers; i++)
    {
        if(pthread_create(&ptCustomers[i], NULL, buy, &pr)){
            perror("Create: ");
            return EXIT_FAILURE;
        }
    }
    for (size_t i = 0; i < customers; i++)
    {
        pthread_join(ptCustomers[i], NULL);
    }
    for (size_t i = 0; i < suppliers; i++)
    {
        pthread_join(ptSuppliers[i], NULL);
    }
    
    
    //SEMAPHORES
    sem_destroy(&semSup);
    sem_destroy(&semBuy);
    //MUTEX
    pthread_mutex_destroy(&mux);

    

    return EXIT_SUCCESS;
}

double randdbl(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

void exitSig(int sig){
    printf("Saving results in a file...");
    raise(SIGINT);
    signal(SIGINT,SIG_DFL);
}