#include <stdio.h>
#include <stdint.h>

int main(){
    uint16_t a;
    scanf("%hu", &a);
    printf("Before the swap: ");
    for(int bit = sizeof(uint16_t) * 8 - 1; bit >= 0; bit--){
        printf("%d", !!(a&(1<<bit)));
    }
    putchar('\n');
    
    int fbit, lbit;
    fbit = a&1;
    lbit = a&(1<<sizeof(uint16_t) * 8 - 1);
    if(fbit != lbit){
        a ^= 1;
        a ^= 1<<sizeof(uint16_t) * 8 - 1;
    }

    printf(" After the swap: ");
    for(int bit = sizeof(uint16_t) * 8 - 1; bit >= 0; bit--){
        printf("%d", !!(a&(1<<bit)));
    }
    putchar('\n');
}