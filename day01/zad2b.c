#include <stdio.h>
#include <math.h>

int main(){
    float l,r,h,v,a;
    printf("Enter the radius of the cilynder: ");
    scanf("%f", &r);
    printf("Enter the lenght of the cilynder: ");
    scanf("%f", &l);
    printf("Enter the height of the water in the cilynder: ");
    scanf("%f", &h);
    a = pow(cos((r - h)/r), -1)*pow(r, 2)-(r-h)*sqrt(2*r*h-pow(h,2));
    v = a*l;
    printf("The side area of the water is %f\nThe volume of the water is %.2f cm3\n",a,v);
}//kompilira se s gcc zad2.c -o zad2 -lmcp zad