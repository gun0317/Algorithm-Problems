#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <error.h>
#include <dirent.h>

#define BUFSIZE 100

void error_handling(char *message);

int main(int argc, char **argv)
{
    int serv_sd;
    int clnt_sd;
    int fd;
    char buf[BUFSIZE];
    char cbuf[BUFSIZE];
    char response[50];

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    int clnt_addr_size;
    int len;

    //initializing dir to show the list of file that server has.

    serv_sd=socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sd == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port=htons(9000);

    if( bind(serv_sd, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1 )
        error_handling("bind() error");
    printf("Global server opened\n");
    if( listen(serv_sd, 5)==-1 )
        error_handling("listen() error");
    clnt_addr_size=sizeof(clnt_addr);
    clnt_sd=accept(serv_sd, (struct sockaddr*)&clnt_addr,&clnt_addr_size);

    if(clnt_sd==-1)
        error_handling("accept() error");

    printf("connected to the global dns server\n");

    //get the address from the local server
    read(clnt_sd, cbuf, BUFSIZE);
    printf("received address : %s\n\n",cbuf);

    //for global_edu_dns file
    char global_edu_dns_site1[30];
    char global_edu_dns_address1[30];
    char global_edu_dns_site2[30];
    char global_edu_dns_address2[30];
    //reading the global_edu_dns.txt and global_com_dns.txt
    FILE *global_edu_dns_ = fopen("global_edu_dns.txt","r");
    int size;
    char *global_edu_dns;
    fseek(global_edu_dns_,0,SEEK_END);
    size = ftell(global_edu_dns_);

    global_edu_dns = malloc(size+1);
    memset(global_edu_dns,0,size+1);

    fseek(global_edu_dns_,0,SEEK_SET);
    fread(global_edu_dns,size,1,global_edu_dns_);
    printf("*global_edu_dns.txt opened\n");

    //tokenizing for site1
    char *tokens;
    tokens = strtok(global_edu_dns, " ");
    strcpy(global_edu_dns_site1, tokens);
    tokens = strtok(NULL,"\n");
    strcpy(global_edu_dns_address1, tokens);
    //tokenizing for site2
    tokens = strtok(NULL, " ");
    strcpy(global_edu_dns_site2, tokens);
    tokens = strtok(NULL,"\n");
    strcpy(global_edu_dns_address2, tokens);

    printf("site: %s, ip: %s\nsite: %s, ip: %s\n\n", global_edu_dns_site1,global_edu_dns_address1,global_edu_dns_site2,global_edu_dns_address2);

    //for global_com_dns file
    char global_com_dns_site1[30];
    char global_com_dns_address1[30];
    char global_com_dns_site2[30];
    char global_com_dns_address2[30];
    //reading the global_com_dns.txt and global_com_dns.txt
    FILE *global_com_dns_ = fopen("global_com_dns.txt","r");
    char *global_com_dns;
    fseek(global_com_dns_,0,SEEK_END);
    size = ftell(global_com_dns_);

    global_com_dns = malloc(size+1);
    memset(global_com_dns,0,size+1);

    fseek(global_com_dns_,0,SEEK_SET);
    fread(global_com_dns,size,1,global_com_dns_);
    printf("*global_com_dns.txt opened\n");

    //tokenizing for site1
    char *token;
    token = strtok(global_com_dns, " ");
    strcpy(global_com_dns_site1, token);
    token = strtok(NULL,"\n");
    strcpy(global_com_dns_address1, token);
    //tokenizing for site2
    token = strtok(NULL, " ");
    strcpy(global_com_dns_site2, token);
    token = strtok(NULL,"\n");
    strcpy(global_com_dns_address2, token);

    printf("site: %s, ip: %s\nsite: %s, ip: %s\n\n", global_com_dns_site1,global_com_dns_address1,global_com_dns_site2,global_com_dns_address2);

    char sending[30];

    if(strcmp(cbuf,global_com_dns_site1)==0) strcpy(sending,global_com_dns_address1);
    else if(strcmp(cbuf,global_com_dns_site2)==0) strcpy(sending,global_com_dns_address2);
    else if(strcmp(cbuf,global_edu_dns_site1)==0) strcpy(sending,global_edu_dns_address1);
    else if(strcmp(cbuf,global_edu_dns_site2)==0) strcpy(sending,global_edu_dns_address2);
    else strcpy(sending, "not found");
    printf("Sending ip from global to local: %s\n",sending);
    write(clnt_sd,sending,sizeof(sending));
    //Closing a part of the socket
    if( shutdown(clnt_sd, SHUT_WR) == -1 )
        error_handling("shutdown error");




       close(fd);
       close(clnt_sd);
       return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
