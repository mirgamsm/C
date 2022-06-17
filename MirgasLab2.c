#include "stdio.h"
#include "stdbool.h"

bool isNeg =false;
int fizzbuzz(int num);

int main(){
    printf("Please enter an integer:\n");
    int num;
    
    scanf("%d",&num);
    if(num<0){
        num *=-1;
        isNeg =true;
    }
    for(int count =0; count<= num; count++)
        fizzbuzz(count);

    return 0;
}
int fizzbuzz(int num){
        
        if(num%3 ==0 && num%5 ==0)
        printf("FizzBuzz\n");
        else if(num%3 ==0)
        printf("Fizz\n");
        else if(num%5 ==0)
        printf("Buzz\n");
        else{
            if(isNeg ==true)
        printf("%d\n",num*-1);
        else
        printf("%d\n",num);
        }
        return 0;
    
}