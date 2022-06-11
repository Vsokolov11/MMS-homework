#include <stdio.h>
#include <stdlib.h>

int comp(const void*,const void*);

int main(){
    int arr[5] = {10,8,45,12,34};
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    qsort(arr, 5,sizeof(int), comp);
    printf("The second largest number is: %d\n", arr[1]);

    return 0;
    
}

int comp (const void* ptr1,const void* ptr2){
    int a = *(const int *)ptr1;
    int b = *(const int *)ptr2;
    //return a - b;
    if(a == b){
        return 0;
    }
    else if(a > b){
        return -1;
    }
    return 1;
}