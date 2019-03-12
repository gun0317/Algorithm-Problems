#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <error.h>

#define BUFSIZE 100

void error_handling(char *message);
int calculate_expression(char *s);
char* itochar(int i);
int x=5,y=5;

int main(int argc, char **argv)
{
    int serv_sd;
    int clnt_sd;
    int fd;
    char buf[BUFSIZE]={0,};
    char cbuf[BUFSIZE]={0,};

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    int clnt_addr_size;
    int len;

    if(argc!=2){
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sd=socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sd == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port=htons(atoi(argv[1]));

    if( bind(serv_sd, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1 ) error_handling("bind() error");

    if( listen(serv_sd, 5)==-1 ) error_handling("listen() error");

    clnt_addr_size=sizeof(clnt_addr);
    clnt_sd = accept(serv_sd, (struct sockaddr*)&clnt_addr,&clnt_addr_size);

    if(clnt_sd==-1) error_handling("accept() error");

    //get the file name from the client

    len = read(clnt_sd, cbuf, BUFSIZE);
    printf("\nreceived buf = %s\n",cbuf);

    char *tokens;
    tokens = strtok(cbuf,"\n");
    while(tokens != NULL)
    {
      if(strcmp(tokens,"Move_UP")==0) {if(y>0) {y--;}}
      else if(strcmp(tokens,"Move_DOWN")==0) {if(y<10) {y++;}}
      else if(strcmp(tokens,"Move_LEFT")==0) {if(x>0) {x--;}}
      else if(strcmp(tokens,"Move_RIGHT")==0) {if(x<10) {x++;}}
      tokens = strtok(NULL,"\n");
    }

    char res[BUFSIZE]="(";
    char x_[3],y_[3];
    sprintf(x_,"%d",x);
    sprintf(y_,"%d",y);
    strcat(res,x_);
    strcat(res,",");
    strcat(res,y_);
    strcat(res,")");

    printf("result:%s\n",res);
    write(clnt_sd, res, BUFSIZE);



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
