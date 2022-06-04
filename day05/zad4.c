#include<stdio.h>
#include<math.h>

int quadEd(double, double, double, double*, double*);

int main(){
    double a,b,c,x1,x2;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    if(quadEd(a,b,c,&x1,&x2) == 0){
        printf("%.2lf\n%.2lf\n", x1, x2);
    }
}
int quadEd(double a, double b, double c, double* X1, double* X2){
    
    double D;
    D = pow(b,2) - 4*a*c;
    if(D>=0){
        *X1 = (-b + sqrt(D))/2*a;
        *X2 = (-b - sqrt(D))/2*a;
        return 0;
    }
    else{
        fprintf(stderr, "No real roots.\n");
        return -1;
    }
}