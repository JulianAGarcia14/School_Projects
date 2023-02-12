#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>


void clearBuf(char* b, int size)
{
	int i;
	for (i = 0; i < size; i++)
		b[i] = '\0';
}


char Cipher(char ch)
{
	return ch ^ 'S';
}


int recvFile(char* buf, int s)
{
	int i;
	char ch;
	for (i = 0; i < s; i++) {
		ch = buf[i];
		ch = Cipher(ch);
		if (ch == EOF)
			return 1;
		else
			printf("%c", ch);
	}
	return 0;
}


int main(int argc, char *argv[])
{
        if( argc > 4 ) {
                printf("Too many arguments supplied, three are expected\n");
        }

        int size = 80;
        char *net_buf = argv[1];
        char *ip_address = argv[2];
        int port = atoi(argv[3]);


	int sockfd, nBytes;
	struct sockaddr_in addr_con;
	int addrlen = sizeof(addr_con);
	addr_con.sin_family = AF_INET;
	addr_con.sin_port = htons(port);
	addr_con.sin_addr.s_addr = inet_addr(ip_address);

	FILE* fp;


	sockfd = socket(AF_INET, SOCK_DGRAM,
					0);

	if (sockfd < 0) {
		printf("\nFailed to revieve file descriptor\n");
        }


		sendto(sockfd, net_buf, size,
			0, (struct sockaddr*)&addr_con,
			addrlen);

		printf("\nFile Received\n");

		while (1) {

		        clearBuf(net_buf, size);
		        nBytes = recvfrom(sockfd, net_buf, size, 0, (struct sockaddr*)&addr_con, &addrlen);

		        if (recvFile(net_buf, size)) {
			        break;
		}
	}

	return 0;
}
