#include <stdio.h>


//Това направих без да гледам решения в интернет
int introot(int num){
    int r = 0;

    while(r * r != num){
        r++;
        if(r > num){
            fprintf(stderr, "there is no integer root...\n");
            return 0;
            break;
        }
    }
    return r;
}
double min(double a, double b){
    if(a - b < 0){
        return a;
    }
    else
    {
        return b;
    }
}
double max(double a, double b){
    if(a - b > 0){
        return a;
    }
    else
    {
        return b;
    }
}
//Това направих с помощ от интернет
double root(double num){
    double minNum = min(1, num), maxNum = max(1, num), mid;

    // Update the bounds to be off the target by a factor of 10
    while(100 * minNum * minNum < num){
        minNum *= 10;
    }
    while(0.01 * maxNum * maxNum > num){
        maxNum *= 0.1;
    } 

    for(int i = 0 ; i < 100 ; i++){

    mid = (minNum+maxNum)/2;

    if(mid*mid == num){
        return mid;
    } 
      
    if(mid*mid > num){
        maxNum = mid;
    } 
    else{
        minNum = mid;
    } 
    }
    return mid;
}


int main(){
    printf("%d\n", introot(36));
    printf("%.3lf\n", root(37));

    return 0;
}