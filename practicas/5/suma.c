#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    char c;
    char buffer[20];
    unsigned total=0;
    unsigned i=0;
    while (read(STDIN_FILENO,&c,1)!=0) {
        if(c!=' '){
            buffer[i]=c;
            i++;
        }else{
            buffer[i]='\0';
            i=0;
            total+= atoi(buffer);

        }
        //write(STDOUT_FILENO,&c,1);
    }
     buffer[i]='\0';
     total+= atoi(buffer);
    printf("%u\n",total);
    return 0;
}