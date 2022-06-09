#include <stdio.h>

int factorial(int);
double power(double,int);
double sine(double);

int main(){
    //printf("%lf, %d", power(2,3), factorial(6));
    printf("%lf", sine(20));
}

double power(double a,int x){
    double num = a;
    for (int i = 1; i < x; i++)
    {
        num *= a;
    }  
    return num;
    
}
int factorial(int a){
    int b=1;
    for(int i=1; i<=a; i++){
        b=b*i;
    }
    return b;
}

double sine(double xdegree){
    int x = xdegree / 180*3.141592; 
    double sin = x- (power(x, 3)/factorial(3))+(power(x, 5)/factorial(5))-(power(x,7)/factorial(7));

    return sin;
}