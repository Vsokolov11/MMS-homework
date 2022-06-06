#include <stdio.h>
#include<math.h>

int cylinder(double r, double h, double* V, double* S);

int main(){
    double r,h, S, V;
    while (1)
    {
        if(scanf("%lf", &r) == EOF || scanf("%lf", &h) == EOF){
            break;
        }
        
        if(r <= 0 || h <= 0){
            printf("Invalid input!");
        }
        else{
            cylinder(r,h,&S,&V);
            printf("V=%.2lf, S=%.2lf\n", V, S);
        } 
    }
}

int cylinder(double r, double h, double* V, double* S){
    *V = M_PI*pow(r ,2)*h;
    *S = 2*M_PI*r*h;
}