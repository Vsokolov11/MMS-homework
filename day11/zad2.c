#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double randDouble(double, double);

int main(){
    int n,m,p;
    scanf("%d", &n);
    double* arr = malloc(sizeof(double) * n);
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = randDouble(0 ,1);
    }
    scanf("%d", &m);
    arr = realloc(arr, sizeof(double) * n + sizeof(double) * m);
    for (size_t i = 0; i < n; i++)
    {
        arr[i + n] = randDouble(1 ,2);
    }
    scanf("%d", &p);
    arr = realloc(arr, sizeof(double) * n + sizeof(double) * m + sizeof(double) * p);
    for (size_t i = 0; i < n; i++)
    {
        arr[i + n + m] = randDouble(2 ,3);
    }


    for (size_t i = 0; i < n + m + p; i++)
    {
        printf("%ld.%lf\n",i, arr[i]);
    }

    free(arr);
    return 0;
}

double randDouble(double min, double max){
    double range = (max - min); 
    double div = RAND_MAX / range;
    double num = min + (rand() / div);
    return num;

}