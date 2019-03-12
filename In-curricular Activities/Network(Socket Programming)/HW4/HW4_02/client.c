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

int main(int argc, char **argv)
{
    int fd;
    int sd;

    char buf[BUFSIZE]={0,};
    char cbuf[BUFSIZE]={0,};
    char response[50]={0,};
    int len;
    struct sockaddr_in serv_addr;

    if(argc!=2){
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    //making the socket
    sd=socket(PF_INET, SOCK_STREAM, 0);
    if(sd == -1)
         error_handling("socket error");

     memset(&serv_addr, 0, sizeof(serv_addr));
     serv_addr.sin_family=AF_INET;
     serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
     serv_addr.sin_port=htons(atoi(argv[1]));

   if( connect(sd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1 )
       error_handling("connection error");
   printf("connected\n");

    fd = open("expression.txt",O_RDONLY);
    if(fd==-1)
      {perror("open expression.txt "); return 1;}

    char bufff[BUFSIZE]={0,};
    printf("expression opened successfully\n");

    while( (len=read(fd, bufff, BUFSIZE)) != 0 )
     {
      write(sd, bufff, len);
     }

    int res,len2;
    char cbuff[BUFSIZE]={0,};

    printf("Receiving from the server..\n");
    len2 = read(sd, cbuff, BUFSIZE);
    printf("***received result*** = %s\n",cbuff);

    FILE *fp = fopen("result.txt","w");
    fputs(cbuff,fp);
    //write(res, cbuff, BUFSIZE);

    printf("Connection terminated!\n");


    close(res);
    close(fd);
    close(sd);
    return 0;
 }

void error_handling(char *message)
 {
      fputs(message, stderr);
      fputc('\n', stderr);
      exit(1);
 }
