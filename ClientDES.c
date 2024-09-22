#include <sys/types.h> 
#include <sys/socket.h> 
#include <netdb.h> 
#include <stdio.h> 
#include <string.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
 
int main(int argc, char **argv) { 
    int sockfd,n; 
    struct sockaddr_in servaddr; 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    bzero(&servaddr, sizeof servaddr); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(22000); 
    inet_pton(AF_INET, "127.0.0.1", &(servaddr.sin_addr)); 
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)); 
    char key[100]; 
    char pt[100]; 
    printf("Please enter the Plain Text: "); 
    scanf("%s", pt); 
    // Hex to binary conversion 
    int r = strlen(pt);
