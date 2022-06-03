#include<stdio.h>
#include<math.h>

int toDec(int base, int num);
int fromDec(int base, int num);
int main(){
    int inBase,outBase;
    int initialNum, convertedNum;
    //printf("%d",toDec(10, 354));
    scanf("%d", &initialNum);
    scanf("%d", &inBase);
    scanf("%d", &outBase);
     if(inBase >= 2 && inBase <= 36 && outBase >= 2 && outBase <= 36){
        if(outBase == 16){
            printf("%X", initialNum);
        }
        else{
            int temp = toDec(inBase, initialNum);
            convertedNum = fromDec(outBase, temp);
        }
     }
    

}
int toDec(int base, int num){
    int res,pos = 0;
    int temp = num;
    int a = 0;
    while ( temp!=0)
    {
        res += (temp % 10) * pow(base, pos);
        temp/=10;
        pos++;
    }
    return(res);
    
}
int fromDec(int base, int num){
    //from decimal to others here :/
}