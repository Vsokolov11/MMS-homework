#include <stdio.h>
#include <math.h>

int main(){
    float l,r,h,v;
    printf("Enter the radius of the cilynder: ");
    scanf("%f", &r);
    printf("Enter the height of the water in the cilynder: ");
    scanf("%f", &h);
    v = M_PI * pow(r,2) * h;
    printf("The volume of the water is %.2f cm3\n", v);
}//kompilira se s gcc zad2.c -o zad2 -lmcp zad