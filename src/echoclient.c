#include "echo.h"

int main(int argc, char **argv)
{
	int clientfd;
	char *host, *port, buf[MAXLINE];
	rio_t rio;
	if (argc != 3)
	{
		fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
		exit(0);
	}
	host = argv[1];
	port = argv[2];
	clientfd = open_clientfd(host, port);
	if (clientfd == -1)
	{
		//	unix_error("Cant't open client");
		unix_error("");
		exit(0);
	}
	Rio_readinitb(&rio, clientfd);
	printf("Clientfd = %d\n", clientfd);
	// printf("debug");
	while (1)
	{
		fgets(buf, MAXLINE, stdin);
		send(clientfd, buf, strlen(buf), 0);
	}
	close(clientfd);
	exit(0);
}