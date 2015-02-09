#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>

int main(void)
{
        int sockfd;
        struct sockaddr_in server;
        char msg[20]={0};
        
        sockfd = socket(AF_INET,SOCK_DGRAM,0);
        if (sockfd < 0) {
                perror("socket error!\n");
                exit(-1);
        }
        
        memset(&server,0,sizeof(server));
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr("192.168.1.1");
        server.sin_port = htons(7777);
        
        strncpy(msg,"hello",sizeof("hello"));
        
        printf("send message:%s\n",msg);
        
        if (sendto(sockfd,msg,20,0,(struct sockaddr *)&server,sizeof(server)) != 20) {
                perror("sendto error!\n");
                exit(-1);
        }        
 
        exit(0);
}
