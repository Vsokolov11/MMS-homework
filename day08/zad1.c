#include <stdio.h>


int strleng(char*);
int strnleng(char*, size_t);
void strcopy(char*, const char*);
void strncopy(char*, const char*, int);
void strcat(char*, const char*);

int main(){
    char b[35] = "abcdefghijklmn";
    char a[40] = "Pseudopseudohypoparathyroidism";
    printf("%d\n", strleng(a));
    printf("%d\n", strnleng(a, 15));
    printf("%s\n", a);
    strcopy(a,b);
    printf("%s\n", a);
    strncopy(a,b,5);
    printf("%s\n", a);
    return 0;
}

int strleng(char* c){
    int count = 0;
    int i = 0;
    while (c[i] !='\0')
    {
        i++;
        count++;
    }
    return count;
}
int strnleng(char* c, size_t n){
    int count = 0;
    int i = 0;
    while (c[i] != '\0')
    {
        i++;
        count++;
        if(i == n){
            break;
        }        
    }
    return count;
}
void strcopy(char* dest, const char* src){
    int i = 0;
    while (dest[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
void strncopy(char* dest, const char* src, int n){
    int i = 0;
    while (dest[i] != '\0')
    {
        dest[i] = src[i];
        i++;
        if(i == n){
            break;
        }
    }
    dest[i] = '\0';
}
void strcat(char* str1, const char* str2){
    int i = 0;
    while (str1[i] != '\0')
    {
        /* code */
    }
    
}