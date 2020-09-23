#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void signalHandler(int signum){
    printf("jajaja no me matas\n");
}

int main(){
    signal(2,signalHandler);
    while(1){
        sleep(2);
        printf("trabajando\n");
    }
    return 0;
}