#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include <sys/wait.h>
#include <pthread.h>


pthread_mutex_t mux;
int total = 0;

void *sum(void *argv){
    FILE* fptr;
    int n, totalCurr = 0;
    
    if(fopen(argv, "r") != NULL){
        fptr = fopen(argv, "r");
        while (fscanf(fptr, "%d", &n) != EOF)
        {
            pthread_mutex_lock(&mux);
            totalCurr += n;
            pthread_mutex_unlock(&mux);
        }
        printf("result in file \"%s\" is : %d\n", (char *)argv, totalCurr);
    }
    else{
        fprintf(stderr, "Error in file \"%s\"\n", (char *)argv);
    }
    total += totalCurr;
}

int main(int argc, char **argv){
    pthread_mutex_init(&mux, NULL);
    pthread_t pth[argc];
    for (size_t i = 0; i < argc-1; i++)
    {
        pthread_create(&pth[i], NULL, sum, argv[i+1]);
        //pthread_join(pth[i], NULL);
    }
    for (size_t i = 0; i < argc-1; i++)
    {
        pthread_join(pth[i], NULL);
    }
    printf("TOTAL: %d\n", total);

    pthread_mutex_destroy(&mux);
    return EXIT_SUCCESS;
}