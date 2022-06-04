#include <stdio.h>

int main(){
    float a ,b, res;
    char c;
    while (1)
    {
        
        printf("Enter an expression without intervals  ");
        if(scanf("%f", &a) == EOF || scanf("%c", &c) == EOF || scanf("%f", &b) == EOF )
        {
            break;
        }
        //scanf("%f", &a);
        //scanf("%c", &c);
        //scanf("%f", &b);
        
        switch (c)
        {
        case '+':
            res = a+b;
            break;
        case '-':
            res = a-b;
            break;
        case 'x':
            res = a*b;
            break;
        case '/':
            res = a/b;
            break;
        default:
            printf("No such operation\n");
            break;
        } 
        printf("%.2f\n", res);
        
    }
}