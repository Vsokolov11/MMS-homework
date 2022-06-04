#include<stdio.h>
#include<stdint.h>

int main(){
    int32_t mask = 124564;
    int ones;
    for(int bit = sizeof(mask) * 8; bit >= 0; bit--)
    {
        int temp;
        temp = (mask&(1<<bit))>>bit;
        if(temp == 1){
            ones++;
        }
    }
    printf("The ones in the mask are %d\n", ones);

}