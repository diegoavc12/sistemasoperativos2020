#include <netinet/in.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
extern int h_errno;

int main(int argc, char **argv){
    char *hostName=argv[1];
    char c;
    struct sockaddr_in serverAddress;
    struct hostent *serverInfo=gethostbyname(hostName);
    /*printf("official name &s, ipaddress %s \n", hostInfo->h_name);
    for(int i=0; i<hostInfo->h_length;i++){
        printf("%c",hostInfo->h_addr[i]);
    }*/
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family=AF_INET;
    serverAddress.sin_port=htons(2727);
    bcopy((char*)serverInfo->h_addr, (char *)&serverAddress.sin_addr.s_addr, serverInfo->h_length);
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(connect(sockfd, &serverAddress, sizeof(serverAddress))){
        printf("Error\n");
    }
    char *message="GET /otro HTTP/1.0\r\n\n";
    write(sockfd, message, strlen(message));
    while(read(sockfd,&c,1)){
        printf("%c",c);
    }
    printf("\n");
    close(sockfd);
    return 0;
}
