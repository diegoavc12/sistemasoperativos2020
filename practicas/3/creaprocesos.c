#include <stdlib.h>
#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
int main(int argc, char*argv[]){
    unsigned pid= fork();
    if(pid==0){
        char *argumento[]={NULL};
        char *environ[]={NULL};
        argumento[0]=argv[1];
        printf("Soy el proceso hijo\n");
        execve(argv[1], argumento, environ);
        return 0;
    }else{
        int status;
        printf("Soy el proceso padre y mi hijo es %u\n",pid);
        sleep(4);
        wait(&status);
        printf("terminando despues del hijo y estatus %d\n", status);
    }
    printf("Hola mundo\n"); 
    return 0;
}