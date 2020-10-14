#include <netinet/in.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
int main(){
    struct sockaddr_in serverAddress;
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_port=htons(44444);
    serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
    int sockfd =socket(AF_INET, SOCK_STREAM, 0);
    bind(sockfd, &serverAddress, sizeof(serverAddress));
    listen(sockfd,5);

    while (1) {
        struct sockaddr_in clientAddress;
        int clientSize= sizeof(clientAddress);
        int clientSocket=accept(sockfd, &clientAddress,&clientSize);
        char c;
        char *message="Hola desde goorm";
         write(clientSocket,message,strlen(message));
        close(clientSocket);
    
    }
}