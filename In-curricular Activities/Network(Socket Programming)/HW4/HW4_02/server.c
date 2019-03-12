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
    printf("***received buf*** \n%s\n",cbuf);

    //printf("requested name of file: %s\n",cbuf);
    int result = calculate_expression(cbuf);
    char res[10]={0,};
    sprintf(res,"%d",result);
    printf("result:%s\n",res);

 	  write(clnt_sd, res, BUFSIZE);



    //Closing a part of the socket
    if( shutdown(clnt_sd, SHUT_WR) == -1 )
        error_handling("shutdown error");





       close(fd);
       close(clnt_sd);
       return 0;
}

 int calculate_expression(char *s){
 	int result=s[0]-48;
  int len = strlen(s);
  for (int i=1;i<len-1;i+=2){
   	if(s[i]=='+') result += (s[i+1]-48);
   	else result += - (s[i+1]-48);
  }
  return result;
 }
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
