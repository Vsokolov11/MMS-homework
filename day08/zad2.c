#include<stdio.h>

int* map(int* array, size_t n, int (*func)(int)){
    for (int i = 0; i < n; i++)
    {
        array[i] = (*func)(array[i]);
    }
    return array;
}
int pow2 (int a){
    return a*a;
}
int main(){

    int nums[] = {1,10,5,46};
    map(nums,5,pow2);
    for(int i = 0; i < 5; i++){
        printf("%d ", nums[i]);
    }
    putchar('\n');
    
    return 0;
}