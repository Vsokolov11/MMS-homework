#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



typedef struct car{
    char model[20];
    uint8_t max_speed;
    double price;
}Car;



void randomModel(char*);
int randint(int min, int max);
double randomPrice(double min, double max);
void printCars(Car*);

int compareModelASC(const void*, const void*);
int compareModelDESC(const void*, const void*);
int compareMaxSpeedASC(const void*, const void*);
int compareMaxSpeedDESC(const void*, const void*);
int comparePriceASC(const void*, const void*);
int comparePriceDESC(const void*, const void*);

int (*getComparator(int n))(const void*, const void*);

int main(){
    srand(time(NULL));
    Car Cars[10];

    for(int i = 0; i < 10; i++){
        randomModel(Cars[i].model);
        Cars[i].max_speed = randint(190, 280);
        Cars[i].price = randomPrice(10000,50000);
    }
    qsort(Cars, 10, sizeof(Car), getComparator(2));
    for(int i = 0; i < 10; i++){
        printCars(&Cars[i]);
    }
    return 0;
}

void randomModel(char* name){

    unsigned index = 0;
    name[index++] = (char)randint('A', 'Z');
    int n = randint(5, 10);
    for (int i = 0; i < n; i++){
        name[index++] = (char)randint('a', 'z');
    }
    name[index++] = (char)randint('0', '9');
    name[index] = '\0';
}

double randomPrice(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

void printCars(Car *b){
    printf("Model:%25s ", b->model);
    printf("Max Speed:%5u ", b->max_speed);
    printf("Price:%5.2lf ", b->price);
    putchar('\n');
}

int compareModelASC(const void* car1, const void* car2){
    Car* c1 = (Car*)car1;
    Car* c2 = (Car*)car2;
    return strcmp(c1->model, c2->model);
}
int compareModelDESC(const void* car1, const void* car2){
    Car* c1 = (Car*)car1;
    Car* c2 = (Car*)car2;
    return strcmp(c2->model, c1->model);
}
int compareMaxSpeedASC(const void* car1, const void* car2){
    Car* c1 = (Car*)car1;
    Car* c2 = (Car*)car2;
    return c1->max_speed-c2->max_speed;
}
int compareMaxSpeedDESC(const void* car1, const void* car2){
    Car* c1 = (Car*)car1;
    Car* c2 = (Car*)car2;
    return c2->max_speed-c1->max_speed;
}
int comparePriceASC(const void* car1, const void* car2){
    Car* c1 = (Car*)car1;
    Car* c2 = (Car*)car2;
    return c1->price-c2->price;
}
int comparePriceDESC(const void* car1, const void* car2){
    Car* c1 = (Car*)car1;
    Car* c2 = (Car*)car2;
    return c1->price-c2->price;
}
int (*getComparator(int n))(const void*, const void*){
    int* arr[6] = {compareMaxSpeedASC, compareMaxSpeedDESC,compareModelASC,compareModelDESC,comparePriceASC,comparePriceDESC};
    int (*a)(const void *, const void *);
    a = arr[n];
    return a;
}