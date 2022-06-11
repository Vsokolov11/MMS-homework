#include <stdio.h>

int sumArr(const int*,int);

int main(){
    int arr[5] = {10,3,6,12,7};
    printf("%d\n", sumArr(arr, 5));

    return 0;
}
int sumArr(const int* arr, int size){
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum+=arr[i];
    }
    return sum;
}