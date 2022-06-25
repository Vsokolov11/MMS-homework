#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>
#include<string.h>



typedef struct msg{
    char m[100];
    int id;
}MSG;

pthread_mutex_t mux;

void *routine(void *arg){
    //probvah 100 neshta, id stava samo 1 i 2
    MSG *msg = (MSG *)arg;
    pthread_mutex_lock(&mux);
    msg->id++;
    printf("%d\n", msg->id);
    pthread_mutex_unlock(&mux);
    
}


int main(int argc, char **argv){
    pthread_mutex_init(&mux, NULL);
    int p,t;
    p = atoi(argv[1]);
    t = atoi(argv[2]);
    MSG msg;
    msg.id = 0;
    strcpy(msg.m, argv[3]);

    pthread_t pth[t];

    printf("processes: %d\nthreads: %d\n\n", p, t);
    

    for (size_t i = 0; i < p; i++)
    {
        pid_t pid = fork();

        if(-1 == pid){
            perror("fork");
            return EXIT_FAILURE;
        }
        
        if(0 == pid){
            printf("This is process with id %d\n\n", getpid());
            
            for (size_t j = 0; j < t; j++)
            {
                pthread_create(&pth[i], NULL, routine, &msg);
                pthread_join(pth[i], NULL);
            }
            exit(EXIT_SUCCESS);
        }
        
    }
    for (size_t i = 0; i < p; i++)
    {
        wait(NULL);
    }

    pthread_mutex_destroy(&mux);
    return EXIT_SUCCESS;
}

