#include<stdio.h>


#define SETBIT(mask , bit)(printf("%d\n", (mask) |=1<<(bit)))
#define CLEARBIT(mask , bit)(printf("%d\n", (mask)&=~(1<<(bit))))
#define FLIPBIT(mask , bit)(printf("%d\n", (mask)^=1<<(bit)))
#define SWAP(a,b) int temp = a; a=b; b=temp
int main(){
    int a  = 10;
    int b = 7;
    printf("%d\n",a);
    CLEARBIT(a, 1);
    SETBIT(a, 5);
    FLIPBIT(a,5);
    SWAP(a,b);
    printf("%d, %d\n",a,b);
 }