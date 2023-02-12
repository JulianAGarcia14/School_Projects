#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#define SIZE 1024

void send_file(char *fp, int sockfd){
  int n;
  //char data[SIZE] = {0};

  //while(fgets(data, SIZE, fp) != NULL) {
    if (send(sockfd, fp, sizeof(fp), 0) == -1) {
      perror("Send File Error.");
      exit(1);
    }
    //bzero(data, SIZE);
  //}
}

void output_message(int sockfd){
  int n;

  char buffer[SIZE];

  while (1) {
    n = recv(sockfd, buffer, SIZE, 0);
    if (n <= 0){
      break;
      return;
    }
    printf("%s", buffer);
    //fprintf(fp, "%s", buffer);
    bzero(buffer, SIZE);
  }
  return;
}

int main(){
  char *ip = "127.0.0.1";
  int port = 8082;
  int e;

  int sockfd, new_sock;
  struct sockaddr_in server_addr, new_addr;
  socklen_t addr_size;
  //FILE *fp;
  //char *filename = "send.txt";

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("Socket Error");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  e = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if(e == -1) {
    perror("Socket Error");
    exit(1);
  }
	printf("Connected to server.\n");

  //fp = fopen(filename, "r");
  //if (fp == NULL) {
  //  perror("Read Error");
  //  exit(1);
  //}

  send_file("send.txt\n", sockfd);


  //addr_size = sizeof(new_addr);
  //new_sock = accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);
  output_message(sockfd);

  close(sockfd);

  return 0;
}
