#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8000
#define BUFSIZE 1024

int main(void){
    //variables
    int sock;
    struct sockaddr_in addr, client_addr;
    char recv_buffer[1024];
    char recv_buffer2[1024];
    int recv_len;
    int addr_len;
    
    int sd;
    char buf[BUFSIZE];
    char cbuf[BUFSIZE];
    int len;
    struct sockaddr_in serv_addr;



    //building socket
    if((sock = socket(AF_INET, SOCK_DGRAM, 0)) <0){
        perror("socket ");
        return 1;
    }

    //socket initialization on server side
    memset(&addr, 0x00, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORT);

    //part of initialization; binding the socket
    if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        perror("bind ");
        return 1;
    }

    printf("Local server opened\n");

    //receiving from the client
    addr_len = sizeof(client_addr);
    recvfrom(sock, recv_buffer, BUFSIZE, 0, (struct sockaddr *)&client_addr, &addr_len);

    //open the local_dns.txt file
    char local_dns[BUFSIZE];
    int l=0;

    //Reading the local_dns.txt file
    FILE *local_dns_ = fopen("local_dns.txt","r");
    fgets(local_dns,sizeof(local_dns),local_dns_);
    printf("local_dns.txt opened\n");
    printf("local_dns.txt: %s\n", local_dns);

    //tokenizing the data
    char *tokens;
    tokens = strtok(local_dns, " ");
    char site[20],ip_[30];
    strcpy(site, tokens);
    tokens = strtok(NULL,"\n");
    strcpy(ip_, tokens);

    //printf("strcmp value: %d\n",strcmp(site,recv_buffer));
    //send ip to client and exit if the data is in local server
    if(strcmp(site,recv_buffer) == 0)
    {
        printf("local dns has the data.\n");
        printf("sending the data..\n");
        printf("sending data = %s\n",ip_);
        sendto(sock,ip_,strlen(ip_)+1,0,(struct sockaddr*)&client_addr,addr_len);
        printf("sent data..\n");
        return 1;
    }

	//using tcp

    //building the socket for TCP/IP
      sd=socket(PF_INET, SOCK_STREAM, 0);
      if(sd == -1) perror("socket error ");

      memset(&serv_addr, 0, sizeof(serv_addr));
      serv_addr.sin_family=AF_INET;
      serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
      serv_addr.sin_port=htons(9000);
      printf("received address is NOT in the local server.\nconnecting to the global server...\n");

     

     //Connecting to the global server
      if( connect(sd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1 )
         perror("connection error ");
      printf("connected to the global server\n");

      //sending to the global server
      write(sd, recv_buffer, BUFSIZE);
      printf("sent message to the global server\nWating for the response from global server..\n");

      //reading from the global server
      char ip2[30];
      read(sd, ip2, sizeof(ip2));

      printf("Local server received the data from Global server.\nsending the data to the client..\n");
      printf("sending data = %s\n",ip2);
      sendto(sock,ip2,strlen(ip2)+1,0,(struct sockaddr*)&client_addr,addr_len);
      printf("sent data..\n");

	close(sock);
	fclose(local_dns_);
	return 0;



}
