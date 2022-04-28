#include "echo.h"

int main(int argc, char **argv)
{
	int listenfd, connfd;
	socklen_t clientlen;
	struct sockaddr_storage clientaddr;
	char clienthost[MAXLINE], clientport[MAXLINE];
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <port>", argv[0]);
		exit(0);
	}
	listenfd = open_listenfd(argv[1]);
	while (1)
	{
		clientlen = sizeof(struct sockaddr_storage);
		connfd = accept(listenfd, &clientaddr, &clientlen);
		getnameinfo(&clientaddr, clientlen, clienthost, MAXLINE, clientport, MAXLINE, 0);
		printf("Connected to (%s %s)\n", clienthost, clientport);
		echo(connfd);
		close(connfd);
	}
	exit(0);
}