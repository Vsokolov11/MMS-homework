#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char *argv[]){
    int c;
    if(!strcmp(argv[1], "cat")){
        if(NULL == argv[2]){
            while(read(STDIN_FILENO, &c, 1)){
                write(STDOUT_FILENO, &c, 1);
            }
        }
        else{
            for (size_t i = 2; i <= argc - 1; i++)
            {
                int fr = open(argv[i], O_RDONLY);
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
        if(!strcmp(argv[2], "-c")){
            int count = atoi(argv[3]);
            int fr = open(argv[4], O_RDONLY);
            if(-1 == fr){
                perror("\nError while opening file: ");
                return EXIT_FAILURE;
            }
            while(count > 0){
                read(fr, &c, 1);
                write(STDOUT_FILENO, &c, 1);
                count--;
            }
            close(fr);
        }
        if(!strcmp(argv[2], "-n")){
            int lines = atoi(argv[3]);
            int fr = open(argv[4], O_RDONLY);
            if(-1 == fr){
                perror("\nError while opening file: ");
                return EXIT_FAILURE;
            }
            while(lines > 0){
                read(fr, &c, 1);
                write(STDOUT_FILENO, &c, 1);
                if(c == '\n'){
                    lines--;
                }
            }
            close(fr);
        }     
    }
    else if(!strcmp(argv[1], "tail")){
        FILE* fptr;
        fptr = fopen(argv[4], "r");
        if(!strcmp(argv[2], "-c")){
            int count = atoi(argv[3]);
            fseek(fptr, -count, SEEK_END);
            while ((c = fgetc(fptr))!=EOF)
            {
                putchar(c);
            }
        }
        if(!strcmp(argv[2], "-n")){
            
            int lines = atoi(argv[3]);
            int allLines = 0;

            rewind(fptr);
            while ((c = fgetc(fptr))!=EOF)
            {
                if(c=='\n'){
                    allLines++;
                }
            }
            //printf("%d", allLines);

            if(lines>allLines){
                perror("No such line");
                return EXIT_FAILURE;
            }
    
            rewind(fptr);
            int currline = 0;
            int desLine = allLines - lines;
            while (currline != desLine)
            {
                c = fgetc(fptr);
                if(c=='\n'){
                    currline++;
                }
            }
            while ((c = fgetc(fptr))!=EOF)
            {
                putchar(c);
            }
        }
    }
    else if(strcmp(argv[1], "ls")){

    }

}
