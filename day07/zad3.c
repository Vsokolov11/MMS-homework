#include <stdio.h>



int sumArr(int*,int);
void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int));


int main(){
    int arr[5] = {10,3,6,12,7};
    arrayEvaluate(arr, 5, sumArr);
}


int sumArr(int* arr, int size){
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum+=arr[i];
    }
    return sum;
}
void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int)){
    printf("%d\n", f(arr, n));

}