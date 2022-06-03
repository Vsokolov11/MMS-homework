#include<stdio.h>
#include<stdlib.h>

int main(){
    float a = 1.200,b;
    for(int i = 0; i < 12; i++){
        b += 0.1;
    }
    if(a == b){
        printf("True 1\n");
    }
    else{
        printf("False1\n");
    }


    float epsilon;
    epsilon = 0.00001;
    if(abs(a-b)<epsilon){
        printf("True 2\n");
    }
    else{
        printf("False 2\n");
    }
    a = 1000;
    b = 3000;
    epsilon = (a+b)/10000;
    printf("%f\n", epsilon);
    if(abs(a-b)<epsilon){
        printf("True 3\n");
    }
    else{
        printf("False 3\n");
    }

}