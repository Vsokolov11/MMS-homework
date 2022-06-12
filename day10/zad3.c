#include <stdio.h>
#include <stdint.h>

int clearBit(uint32_t*, size_t, size_t);
int setBit(uint32_t* , size_t, size_t);
int checkBit(uint32_t*, size_t, size_t);

int main(){
    uint32_t masks[10] = {15, 23, 43, 12, 76, 34, 96, 178, 2, 456};

    

    printf("Before any operations:\n");
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", *(masks + i));
    }
    putchar('\n');
    putchar('\n');
    

    printf("After clearBit:\n");
    clearBit(masks, 16, 1);
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", *(masks + i));
    }
    putchar('\n');
    putchar('\n');


    
    printf("After setBit:\n");
    setBit(masks, 10, 1);
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", *(masks + i));
    }
    putchar('\n');
    putchar('\n');

    checkBit(masks, 10, 1);

    return 0;

}


int clearBit(uint32_t* maskArr, size_t nitems, size_t bit){
    if(!*(maskArr + nitems)){
        printf("There is no %lu elements in the array...\n", nitems);
        return -1;
    }
    else{
        for (int i = 0; i < nitems; i++)
        {
        *(maskArr + i)&=~(1<<bit);
        }
    }
    
}

int setBit(uint32_t* maskArr, size_t nitems, size_t bit){
    if(!*(maskArr + nitems)){
        printf("There is no %lu elements in the array...\n", nitems);
        return -1;
    }
    else{
        for (int i = 0; i < nitems; i++)
        {
            *(maskArr + i)|=(1<<bit);
        }
    }
    return 0;
}

int checkBit(uint32_t* maskArr, size_t nitems, size_t bit){
    if(!*(maskArr + nitems)){
        printf("There is no %lu elements in the array...\n", nitems);
        return -1;
    }
    else{
        for (int i = 0; i < nitems; i++)
        {
            uint8_t b = !!(maskArr[i]&(1<<bit));
            return b;
        }
    }
}