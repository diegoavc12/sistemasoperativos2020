#include <stdlib.h>
#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>

void signalHandler(int signum){
    int status;
   wait(&status);
   printf("Mi hijo termino con status %d", status);
}

int main(int argc, char*argv[]){
    signal(17,signalHandler);
    unsigned pid= fork();
    if(pid==0){
        sleep(5);
        printf("Soy el proceso hijo\n");
        //execve(argv[1], argumento, environ);
        return 0;
    }else{
        printf("Soy el proceso padre y mi hijo es %u\n",pid);
        while(1){
        sleep(2);
        printf("trabajando\n");
        }
    }
    printf("Hola mundo\n"); 
    return 0;
}