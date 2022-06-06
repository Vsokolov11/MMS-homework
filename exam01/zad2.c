#include <stdio.h>
#include<stdint.h>

unsigned bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4);
void flipOddBits(uint64_t*);
void mirrorBits(uint16_t* mask);

int main(){
    uint64_t mask = 0;
    //printf("The count of the ones int the masks : %d\n", bitsNCount(15234, 1200, 450, 190));
    flipOddBits(&mask);
    //mirrorBits(&mask);
    printf("\n");
}

unsigned bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4){
    int ones = 0;


    for(int bit = sizeof(mask1) * 8; bit > 0; bit--){
        int counter;
        counter = (mask1&(1<<bit))>>bit;
        if(counter == 1){
            ones++;
        }
    }

    for(int bit = sizeof(mask2) * 8; bit > 0; bit--){
        int counter;
        counter = (mask2&(1<<bit))>>bit;
        if(counter == 1){
            ones++;
        }
    }

    for(int bit = sizeof(mask3) * 8; bit > 0; bit--){
        int counter;
        counter = (mask3&(1<<bit))>>bit;
        if(counter == 1){
            ones++;
        }
    }

    for(int bit = sizeof(mask4) * 8; bit > 0; bit--){
        int counter;
        counter = (mask4&(1<<bit))>>bit;
        if(counter == 1){
            ones++;
        }
    }
    return ones;
}

void flipOddBits(uint64_t* mask){
    for(int bit = sizeof(*mask) * 8 - 1; bit >= 0; bit--){
        if(bit %2 !=0)
        {
            *mask ^= (uint64_t)1<<bit;
        }
        printf("%lu", (*mask&(1<<bit))>>bit);
    }
}
void mirrorBits(uint16_t* mask){
    for(int bit = sizeof(*mask) * 8 - 1; bit >= 0; bit--){
        *mask ^= 1<<bit;
    }
    for(int bit = sizeof(*mask) * 8 - 1; bit >= 0; bit--){
        printf("%d", (*mask&(1<<bit))>>bit);
    }
}