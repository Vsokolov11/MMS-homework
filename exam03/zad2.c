#include<stdio.h>

int main(){
    char filetxt[20] = "textfile", filebin[20] = "binfile";
    int buffer[10];
    FILE* fptxt = fopen(filetxt, "r");
    FILE* fpbin = fopen(filebin, "wb+");
    fwrite(fpbin, 2, 10, fptxt);
    fread(buffer, 2, 10,fpbin);
    for (size_t i = 0; i < 10; i++)
    {
        printf("%u\n",buffer[i]);
    }
    fclose(fptxt);
    fclose(fpbin);
}
