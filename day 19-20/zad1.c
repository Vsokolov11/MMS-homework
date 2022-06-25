#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>


#define COUNT 10

void *routine(void* arg){
    sleep(1);
    printf("%d\n", rand() %15);
}

int main(){
    srand(time(NULL));
    pthread_t pth[COUNT];
    for (int i = 0; i < COUNT; i++){
        if(pthread_create(&pth[i], NULL, routine, NULL)){
            perror("create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < COUNT; i++){
        if(pthread_join(pth[i], NULL)){
            perror("join");
            exit(EXIT_FAILURE);
        }
    }
}