#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    char c;
    //char buffer[20];
    unsigned caracteres=0;
    unsigned i=0;
    unsigned palabras=0;
    unsigned lineas=0;
    while (read(STDIN_FILENO,&c,1)!=0) {
        caracteres++;
        if(c==' '){
            palabras++;
        }
        if (c=='\n') {
            lineas++;
            palabras++;
        }
    }
    printf("%d\n",lineas);
    printf("%d\n",palabras);
    printf("%d\n",caracteres);
    return 0;
}