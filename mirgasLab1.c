# include <stdio.h>

int main(){
int x;
printf("Please enter a numeric grade: \n");
if(scanf("%d",&x)==1){
    if(x<=60 && x>=0 )
        printf("Your grade is a F.\n");
    else if(x<=70 && x>60)
        printf("Your grade is a D.\n");
    else if(x<=80 && x>70)
        printf("Your grade is a C.\n");
    else if(x<=90 && x>80)
        printf("Your grade is a B.\n");
    else if(x<=100 && x>90)
        printf("Your grade is a A.\n");
    else
        printf("You entered an invalid value.\n");}
else{
    printf("Your input could not be interpreted as an integer value.\n");
    }
    return 0;
}
