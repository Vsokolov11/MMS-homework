#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    
    int pipes[2];

    if (pipe(pipes) == -1) {
      fprintf(stderr, "Unable to create pipe\n");
      return EXIT_FAILURE;
    }
    for (size_t i = 1; i < argc; i++)
    {
        FILE* fptr;
        int pid = fork();
        if(0 == pid){
            
            
            if(NULL != fopen(argv[i], "r")){
                fptr = fopen(argv[i], "r");
                int n, totalCurr = 0;
                while (fscanf(fptr, "%d", &n) != EOF)
                {
                    totalCurr += n;
                }
                write(pipes[1], &totalCurr, sizeof(totalCurr));
                printf("In file \"%s\" the total sum is: %d\n", argv[i], totalCurr);
                fclose(fptr);
            }
            else{
                
                fprintf(stderr, "Error in file \"%s\"\n", argv[i]);
                exit(0);
            }
            exit(0);
            
        }
        else{
            //exit(0);
        }
    }
    int total = 0;
    for (size_t i = 1; i < argc; i++){
        int temp;
        read(pipes[0], &temp, sizeof(total));
        total += temp;
        wait(NULL);
    }
    printf("TOTAL: %d\n", total);
    return EXIT_SUCCESS;
}