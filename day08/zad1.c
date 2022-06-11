#include <stdio.h>


int strleng(char*);
int strnleng(char*, size_t);
void strcopy(char*, const char*);
void strncopy(char*, const char*, int);
void strgcat(char*, const char*);
void strgncat(char*, const char*,int);

int main(){
    char b[31] = "abcde";
    char a[31] = "second string";
    char c[31] = "string to concat";
    printf("Copied: %s\n", a);
    printf("%d\n", strleng(a));
    printf("%d\n", strnleng(a, 8));
    printf("String A before strcopy: %s\n", a);
    strcopy(a,b);
    printf("String A after strcopy: %s\n", a);
    strncopy(a,b,3);
    printf("String A after strncopy(3): %s\n", a);
    strgcat(a,c);
    printf("String A after concat: %s\n", a);
    strcopy(a,b);
    printf("String A after strcopy: %s\n", a);
    strgncat(a,c, 6);
    printf("String A after N concat: %s\n", a);
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
void strgcat(char* str1, const char* str2){
    int i = 0;
    int j = 0;
    while (str1[i] != '\0')
    {
        i++;
    }
    while (str2[j]!='\0')
    {
        str1[i]=str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}
void strgncat(char* str1, const char* str2, int n){
    int i = 0;
    int j = 0;
    while (str1[i] != '\0')
    {
        i++;
    }
    while (j != n)
    {
        str1[i]=str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}