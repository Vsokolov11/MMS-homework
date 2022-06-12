#include <stdio.h>

int main(){
    float a;
    int* ptr;
    printf("Enter a real number: ");
    scanf("%f", &a);
    ptr = &a;
    for(int bit = 32; bit >= 0; bit--){
        printf("%d", !!(*ptr&(1<<bit)));
    }
    putchar('\n');
}