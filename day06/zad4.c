#include <stdio.h>
#include <stdarg.h>


unsigned bitsNCount(unsigned count, unsigned bitscnt, ...);


int main(){
    printf("%d\n",bitsNCount(5,1,1,2,4,9,17));

    return 0;
}

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...){
    va_list argl;
    int temp;
    int countOnes;
    int correct = 0;
    va_start(argl, bitscnt);
    for(int i = 0; i < count; i++){
        
        temp = va_arg(argl, int);
        for (int i = sizeof(temp) * count; i >= 0; i--)
        {
           if((temp&(1<<i))>>i == 1){
               countOnes++;
           }
        }
        if(countOnes == bitscnt){
            correct++;
        }
        countOnes = 0;
    }
    va_end(argl);
    return correct;
}