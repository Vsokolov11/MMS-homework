#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>


void myfprnt(FILE *fp, char *c){
    char s[1000];
    strcpy(s, c);
    int f  = fileno(fp);
    int i = 0;
    int l = strlen(s);
    printf("%d", l);
    for (size_t i = 0; i < l; i++)
    {
        char c = *(s+i);
        write(f, &c, 1);
    }
}

int main(){
    FILE *fp = fopen("zad2.txt", "w");

    myfprnt(fp, "Hello World!\nThis is my implementation of fprintf without formats");

    fclose(fp);
}