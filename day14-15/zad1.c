#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define COUNT 5

typedef struct book{
    char title[21];
    char author[21];
    unsigned pages;
    double price;
}Book;

void randomName(char*);
void randomTitle(char*);
int randint(int, int);
double randdbl(double, double);

int main(){

    FILE* fptr;
    Book b_arr[COUNT];
    char name[50];
    scanf("%s", name);
    fptr = fopen(name, "w");
    srand(time(NULL));
    for (int i = 0; i < COUNT; i++)
    {
        randomTitle(b_arr[i].title);
        randomName(b_arr[i].author);
        b_arr[i].pages = randint(5, 2000);
        b_arr[i].price = randdbl(1.0, 100.0);
    }
    for (int i = 0; i < COUNT; i++)
    {
        printf("Title:%25s", b_arr[i].title);
        printf("  Author:%25s", b_arr[i].author);
        printf("  Pages:%5d", b_arr[i].pages);
        printf("  Price:%6.2lf ", b_arr[i].price);
        putchar('\n');
        fwrite(&b_arr[i], sizeof(b_arr), COUNT, fptr);
    }
    fclose(fptr);
    return 0;
}



void randomName(char* name){

    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(5, 9);
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index++] = ' ';
    n = randint(5, 10);
    name[index++] = randint('A', 'Z');
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index] = '\0';
}
void randomTitle(char* title){
    int n = randint(10, 19);
    unsigned index = 0;
    title[index++] = randint('A', 'Z');
    for (int i = 0; i < n; i++){
        title[index++] = randint('a', 'z');
    }
    title[index] = '\0';
}
int randint(int min, int max){
    return min + rand() % (max - min + 1);
}
double randdbl(double min, double max){
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}