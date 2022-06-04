#include <stdio.h>

int rect(double w, double h, double* S, double* P);

int main(){
    double S, P;
    double w,h;
    while(1){
        if(scanf("%lf", &w) == EOF || scanf("%lf", &h) == EOF){
            break;
        }
        if(w <= 0 || h <= 0){
            fprintf(stderr, "Invalid input!\n");
            return -1;
        }
        else{
            rect(w,h, &S,&P);
            printf("S = %.2lf\nP = %.2lf\n", S, P);
        }
    }
    
}
int rect(double w, double h, double* S, double* P){
    *P = 2*(w+h);
    *S = w*h;
    return 0;
}