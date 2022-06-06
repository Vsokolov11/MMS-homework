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
            return -1;
        }
        else{
            cylinder(r,h,&S,&V);
            printf("V=%.2lf, S=%.2lf\n", V, S);
            return 0;
        } 
    }
}

int cylinder(double r, double h, double* V, double* S){
    *S = M_PI*pow(r ,2)*h;
    *V = 2*M_PI*r*(r+h);
    //mislq che V i S trqbva da sa razmeneni no e taka po uslovie, zatova go ostavqm taka
}