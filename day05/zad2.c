#include <stdio.h>
#include <math.h>

int triangle(double a, double b, double c, double* S, double* P);

int main(){
    double S, P;
    double a,b,c;
    /*scanf("%lf", &a);
    scanf(" %lf", &b);
    scanf(" %lf", &c);*/
    while(1){
        if(scanf("%lf", &a) == EOF || scanf("%lf", &b) == EOF || scanf("%lf", &c) == EOF){
            break;
        }
        if(a <= 0 || b <= 0 || c <= 0){
            printf("Invalid input!\n");
        }
        else{
            triangle(a,b,c,&S,&P);
            printf("S = %.2lf\nP = %.2lf\n", S, P);
        }
    }
    
}
int triangle(double a, double b, double c, double* S, double* P){
    *P = a+b+c;
    double p = *P/2;
    *S = sqrt(p*(p - a)*(p - b)*(p - c));
}