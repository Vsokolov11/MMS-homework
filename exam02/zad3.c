#include <stdio.h>

int main(){
    char num[500];
    scanf("%s", &num);
    printf("%s\n", num);
    int i = 0;
    while (num[i] != '\0')
    {
        if(i%2 == 0){
            int a = (int)num[i];
            num[i] = 'A' + a - 48;
        }
        else{
            switch (num[i])
            {
            case '0':
                num[i]='!';
                break;
            case '1':
                num[i]='#';
                break;
            case '2':
                num[i]='/';
                break;
            case '3':
                num[i]='~';
                break;
            case '4':
                num[i]='=';
                break;
            case '5':
                num[i]='\'';
                break;
            case '6':
                num[i]='\\';
                break;
            case '7':
                num[i]='>';
                break;
            case '8':
                num[i]='.';
                break;
            case '9':
                num[i]=',';
            default:
                break;
            }
        }
        i++;
    }
    printf("%s", num);
    return 0;
}