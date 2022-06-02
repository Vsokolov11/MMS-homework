#include<stdio.h>

int xor(int a, int b){
    //ako dvete sa razlichni znachi zaduljitelno ednoto e =1 a drugoto =0
    if(a != b){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){

    int a,b;
    printf("Enter A(0 or 1):");
    scanf("%d", &a);
    printf("Enter B(0 or 1):");
    scanf("%d", &a);
    printf("%d\n", xor(a, b));
}