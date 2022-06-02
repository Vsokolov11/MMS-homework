#include<stdio.h>
#include<math.h>

int main(){
    float height, weight, bmi;
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    printf("Enter your weight in kg\'s: ");
    scanf("%f", &weight);
    bmi = 1.3 * (weight / pow(height, 2));
    printf("Your BMI is: %.2f\n", bmi);
}
//programata se kompilira s gcc zad1.c -lm