#include<stdio.h>
#include<limits.h>

int main(){
    double a[3];
    double max = __DBL_MIN__;
    for(int i = 0; i < 3; i++){
        scanf("%lf", &a[i]);
        if(a[i] > max){
            max = a[i];
        }
    }
    printf("%.2lf\n", max);
    return 0;
}
//  ./zad1 < numbers.txt