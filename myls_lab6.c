// ls command implementation
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void do_ls(char[]);
void do_ls_a(char[]);
void do_ls_s(char[]);
void do_ls_r(char[]);
int myCompare (const void * a, const void * b );

int main(int ac, char *av[]){  
    if(ac == 1)
        do_ls(".");
    else if(!strncmp(av[1],"-a",2)){
            if(ac==2)
            do_ls_a(".");
            else
                while (--ac-1){
                    ++av;  //to avoid running -a as dir 
                    printf("%s:\n",*++av);
                    do_ls_a(*av);
                }          
        }
        else if(!strncmp(av[1],"-s",2)){
            printf("H1\n");
            if(ac==2)
            do_ls_s(".");
            else
                while (--ac-1){
                    printf("H2\n");
                    ++av;  //to avoid running -a as dir 
                    printf("%s:\n",*++av);
                    do_ls_s(*av);
                }          
        }
        else if(!strncmp(av[1],"-r",2)){
            printf("H1\n");
            if(ac==2)
            do_ls_r(".");
            else
                while (--ac-1){
                    printf("H2\n");
                    ++av;  //to avoid running -a as dir 
                    printf("%s:\n",*++av);
                    do_ls_r(*av);
                }          
        }
        else          
        while (--ac){
            printf("%s:\n",*++av);
            do_ls(*av);
        }    
}
void do_ls(char dirname[]){
    DIR              *dir_ptr;
    struct dirent   *direntp;
    if((dir_ptr =opendir(dirname))==NULL)
        fprintf(stderr,"myls: cannot open %s\n",dirname);
    else{
        while((direntp =readdir(dir_ptr))!=NULL)
            if(strncmp(direntp->d_name,".",1))           
            printf("%s\n",direntp->d_name);
        closedir(dir_ptr);
    }
}
void do_ls_s(char dirname[]){
    DIR              *dir_ptr;
    struct dirent   *direntp;
    int i=0;
    if((dir_ptr =opendir(dirname))==NULL)
        fprintf(stderr,"myls: cannot open %s\n",dirname);
    else{
        int size =0;
        while((direntp =readdir(dir_ptr))!=NULL)
        if(strncmp(direntp->d_name,".",1))
        size++;
        char* arr[size];
        closedir(dir_ptr);
        opendir(dirname);
        while((direntp =readdir(dir_ptr))!=NULL)
            if(strncmp(direntp->d_name,".",1)){
            arr[i] =direntp->d_name;
            i++; }
int stringLen = sizeof(arr) / sizeof(char *);            
        qsort(arr, stringLen, sizeof(char*),myCompare);   
        printf("H10\n"); 
        for(int j =0;j<i;j++)               
        printf("%s\n",arr[j]);
        closedir(dir_ptr);
    }
}
//this works >
void do_ls_a(char dirname[]){
    DIR              *dir_ptr;
    struct dirent   *direntp;
    
    if((dir_ptr =opendir(dirname))==NULL)
        fprintf(stderr,"myls: cannot open %s\n",dirname);
    else{
        while((direntp =readdir(dir_ptr))!=NULL)
            if(!strncmp(direntp->d_name,".",1))        
            printf("%s\n",direntp->d_name);
        closedir(dir_ptr);
    }
}
void do_ls_r(char dirname[]){
    DIR              *dir_ptr;
    struct dirent   *direntp;
    int i=0;
    if((dir_ptr =opendir(dirname))==NULL)
        fprintf(stderr,"myls: cannot open %s\n",dirname);
    else{
        int size =0;
        while((direntp =readdir(dir_ptr))!=NULL)
        if(strncmp(direntp->d_name,".",1))
        size++;
        char* arr[size];
        closedir(dir_ptr);
        opendir(dirname);
        while((direntp =readdir(dir_ptr))!=NULL)
            if(strncmp(direntp->d_name,".",1)){
            arr[i] =direntp->d_name;
            i++; }
int stringLen = sizeof(arr) / sizeof(char *);            
        qsort(arr, stringLen, sizeof(char*),myCompare);   
        printf("H10\n");
        int j =0; 
        while( j!=i)               
        printf("%s\n",arr[--i]);
        closedir(dir_ptr);
    }
}
int myCompare (const void * a, const void * b ) {
    const char *pa = *(const char**)a;
    const char *pb = *(const char**)b;

    return strcmp(pa,pb);
}