#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 8000
#define BUFSIZE 1024

int main(void){
	//variables
    int sock;
    struct sockaddr_in target_addr;
    char recv_buffer[30];
    int recv_len;
    int addr_len;
    int choice;
    const char msg[1024];
    //buillding UDP socket
    if((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("socket ");
        return 1;
    }

 	//socket initialization
    memset(&target_addr, 0x00, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    target_addr.sin_port = htons(PORT);

    addr_len = sizeof(target_addr);

    //read data from address.txt
    char address_name[BUFSIZE];
    FILE *address = fopen("address.txt","r");
    printf("address.txt opened\n");
    fgets(address_name,sizeof(address_name),address);

    char *token;
    token = strtok(address_name,"\n");
    strcpy(address_name,token);
    printf("address_name: %s\n", address_name);

    sendto(sock, address_name, strlen(address_name)+1, 0, (struct sockaddr *)&target_addr, addr_len);

 	  printf("sent, now receiving...\n");
    recvfrom(sock, recv_buffer, sizeof(recv_buffer)+1, 0, (struct sockaddr *)&target_addr, &addr_len);

    printf("received ip address : %s\n",recv_buffer);

   fclose(address);
    close(sock);

    return 0;
}
