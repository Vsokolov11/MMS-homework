#include <stdio.h>
#include <stdint.h>

//int, char, double, float, uint8_t, uint16_t, uint32_t, uint64_t.

#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TINT8 5
#define TINT16 6
#define TINT32 7
#define TINT64 8

void printValue(const void* valuePtr, uint8_t flag);
int main(){
    int a = 1010;
    uint16_t b = 45566;
    uint8_t c = 1;
    float d = 4.5;
    double e = 2.25;
    printValue(&a, TINT);
    printValue(&b, TINT16);
    printValue(&c, TINT8);
    printValue(&d, TFLOAT);
    printValue(&e, TDOUBLE);

    return 0;
}
void printValue(const void* valuePtr, uint8_t flag){
    switch (flag)
    {
    case 1:
        printf("%d\n", *(int *)valuePtr);
        break;
    case 2:
        printf("%c\n", *(char *)valuePtr);
        break;
    case 3:
        printf("%lf\n", *(double *)valuePtr);
        break;
    case 4:
        printf("%f\n", *(float *)valuePtr);
        break;
    case 5:
        printf("%u\n", *(uint8_t *)valuePtr);
        break;
    case 6:
        printf("%u\n", *(uint16_t *)valuePtr);
        break;
    case 7:
        printf("%lu\n", *(uint32_t *)valuePtr);
        break;
    case 8:
        printf("%lu\n", *(uint32_t *)valuePtr);
        break;
    default:
        break;
    }
}