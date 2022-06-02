#include <stdio.h>

int xor(int a, int b){
    //ako se vuvejdat samo 2 chisla programata moje da raboti i  s if(a != b){return true}
    if(!a && b ){
        return 1;
    }
    else if(a  && !b){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int a,b;
    printf("Enter A(0 or 1): ");
    scanf("%d", &a);
    printf("\nEnter B(0 or 1): ");
    scanf("%d", &b);
    printf("%d\n", xor(a,b));
}
//.zad2 < numbers.txt