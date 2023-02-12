#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZE 80
#define nofile "File isn't found"


void clearBuf(char* b)
{
	int i;
	for (i = 0; i < SIZE; i++)
		b[i] = '\0';
}

char Cipher(char ch)
{
	return ch ^ 'S';
}


int sendFile(FILE* fp, char* buf, int s)
{
	int i, len;
	if (fp == NULL) {
		strcpy(buf, nofile);
		len = strlen(nofile);
		buf[len] = EOF;
		for (i = 0; i <= len; i++)
			buf[i] = Cipher(buf[i]);
		return 1;
	}

	char ch, ch2;
	for (i = 0; i < s; i++) {
		ch = fgetc(fp);
		ch2 = Cipher(ch);
		buf[i] = ch2;
		if (ch == EOF)
			return 1;
	}
	return 0;
}


int main(int argc, char *argv[])
{

        if( argc > 2 ) {
                printf("Too many arguments supplied, only one is expected\n");
        }

        int port = atoi(argv[1]);


	int sockfd, nBytes;
	struct sockaddr_in addr_con;
	int addrlen = sizeof(addr_con);
	addr_con.sin_family = AF_INET;
	addr_con.sin_port = htons(port);
	addr_con.sin_addr.s_addr = INADDR_ANY;
	char net_buf[SIZE];
	FILE* fp;


	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
                printf("\nCouldn't find file desctiptor\n");
        }



	if (bind(sockfd, (struct sockaddr*)&addr_con, sizeof(addr_con)) == 0)
		printf("\nServer Started...\n");
	else
		printf("\nServer Failed to Start\n");

	while (1) {

		clearBuf(net_buf);

		nBytes = recvfrom(sockfd, net_buf,
						SIZE, 0,
						(struct sockaddr*)&addr_con, &addrlen);
                char *ip = inet_ntoa(addr_con.sin_addr);
                printf("Got a Client: ip address: %s port number: %d", ip, port);

		fp = fopen(net_buf, "r");
		printf("\nGot File: %s\n", net_buf);
		if (fp == NULL) {
			printf("\nFailed to Open\n");
                }

		while (1) {


			if (sendFile(fp, net_buf, SIZE)) {
				sendto(sockfd, net_buf, SIZE,
					0,
					(struct sockaddr*)&addr_con, addrlen);
				break;
			}


			sendto(sockfd, net_buf, SIZE,
				0,
				(struct sockaddr*)&addr_con, addrlen);
			clearBuf(net_buf);
		}
		if (fp != NULL)
			fclose(fp);
	}
	return 0;
}
