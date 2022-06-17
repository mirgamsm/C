#include <stdio.h>
#include <time.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


#define SHOWHOST 
void show_info(struct utmp *utbufp);

int main(){
    struct utmp current_record;
    int utmpfp;
    int reclen =sizeof(current_record);

    if((utmpfp =open(UTMP_FILE, O_RDONLY))==-1){
        perror(UTMP_FILE);
        exit(1);
    }
    while(read(utmpfp, &current_record, reclen)==reclen){
        show_info(&current_record);
    }
    close(utmpfp);
    return 0;
}
char *ctime(const time_t *timer);
void show_info(struct utmp *utbufp){
if(utbufp->ut_type ==7){
    time_t temp =utbufp->ut_time;
    printf("%-8.8s", utbufp->ut_name);
    printf(" ");
    printf("%-8.8s", utbufp->ut_line);
    printf(" "); 
    printf("%s",ctime(&temp));
    printf(" ");  
  #ifdef SHOWHOST
    printf("(%s)",utbufp->ut_host);
  #endif
    printf(" ");}

}