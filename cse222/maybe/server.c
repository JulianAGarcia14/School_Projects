#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#define SIZE 1024

const char* output_message(int sockfd){
  int n;

  char buffer[SIZE];

  //while (1) {
    n = recv(sockfd, buffer, SIZE, 0);
    if (n <= 0){
      //break;
      return "void";
    }
    printf("%s\n", buffer);
    //fprintf(fp, "%s", buffer);
    //bzero(buffer, SIZE);
  //}
  char s[SIZE];
  int i = 0;

  while (buffer[i] < 'A' && buffer[i] < 'z') {
          s[i] = buffer[i];
          i++;
  }
  char *t = s;
  return t;
}

void send_file(FILE *fp, int sockfd){
  int n;
  char data[SIZE] = {0};
  printf("\ngot to send\n");
  while(fgets(data, SIZE, fp) != NULL) {
    if (send(sockfd, data, sizeof(data), 0) == -1) {
      perror("Send File Error.");
      exit(1);
    }
    bzero(data, SIZE);
  }
}

int main(){
  char *ip = "127.0.0.1";


  int port = 8082;
  printf("Got a client: ip address: %s port number: %d \n", ip, port);

  int e;

  int sockfd, new_sock;
  struct sockaddr_in server_addr, new_addr;
  socklen_t addr_size;
  char buffer[SIZE];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("Socket error");
    exit(1);
  }
  printf("Server Started...\n");

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  e = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

  if(e < 0) {
    perror("Bind error");
    exit(1);
  }

  if(listen(sockfd, 10) == 0){}
  else{
		perror("Listening error");
                exit(1);
	}

  addr_size = sizeof(new_addr);
  new_sock = accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);
  printf("Got file.\n");
  const char *filename = output_message(new_sock);



  ///////////////////////////////////////////////////
  FILE *fp;
  printf("filename %s\n", filename);
  //char *filename = "send.txt";
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Read Error");
    exit(1);
  }

  send_file(fp, sockfd);


  return 0;
}
