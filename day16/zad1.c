#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char *argv[]){

    FILE* fp;
    if(!strcmp(argv[1], "cat"))
    {
        if(NULL == argv[2]){
            while(read(STDIN_FILENO, &c, 1)){
                write(STDOUT_FILENO, &c, 1);
            }
        }
        else{

            for (size_t i = 2; i <= argc - 1; i++)
            {
                fr = open(argv[i], O_RDONLY);
                if(-1 == fr){
                    perror("\nError while opening file: ");
                    return EXIT_FAILURE;
                }
                while(read(fr, &c, 1)){
                    write(STDOUT_FILENO, &c, 1);
                }
                close(fr);
            }
        }
    }
    else if(!strcmp(argv[1], "head")){

        fr = open(argv[4], O_RDONLY);

        if(!strcmp(argv[2], "-c")){
            int count = atoi(argv[3]);
            for (size_t i = 0; i < count; i++)
            {
                read(fr, &c, 1);
                write(STDOUT_FILENO, &c, 1);
            }
        }

        if(!strcmp(argv[2], "-n")){
            int count = atoi(argv[3]);
            while (count > 0)
            {
                read(fr, &c, 1);
                if(c==10)
                {
                    count--;
                }
                write(STDOUT_FILENO, &c, 1);
                
            }
        }

        close(fr);
    }
    else if(!strcmp(argv[1], "tail")){

        fp = fopen(argv[4], 'r');
        
        if(!strcmp(argv[2], "-c")){
            int count = atoi(argv[3]);
            printf("%d", count);
            
        }

        if(!strcmp(argv[2], "-n")){
            int count = atoi(argv[3]);
            while (count > 0)
            {
                fgetc(fp);           
            }
            
        }

        fclose(fp);
    }
    else{
        fprintf(stderr, "%s is not a real command...\n", argv[1]);

        return EXIT_FAILURE;
    }
}
