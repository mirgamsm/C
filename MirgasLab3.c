#include <stdio.h>
#include <ctype.h>
int main(int argc, char *argv[]){
   for(int i =1; i<argc ;i++){
       int j =0;
        while(argv[i][j] !='\0'){
           // printf("\n");
            int z =0;    
                while(z<=j){
                    if(isalpha(argv[i][j]) ==0){z++;}
                    else{
                        if(z==j){
                    printf("%c\n",argv[i][z]);
                    }else
                    printf("%c",argv[i][z]);
                    z++;
                }
                }    
       j++;
       }
    }
    return 0;
    }