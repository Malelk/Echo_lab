#include "echo.h"
int Accept(int s, struct sockaddr *addr, socklen_t *addrlen);
int main(int argc, char **argv)
{
	int listenfd, connfd;
	socklen_t clientlen;
	struct sockaddr_storage clientaddr;
	char clienthost[MAXLINE], clientport[MAXLINE];
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
	}
	listenfd = open_listenfd(argv[1]);
	printf("Listenfd = %d\n", listenfd);
	while (1)
	{
		// printf("1\n");
		clientlen = sizeof(struct sockaddr_storage);
		connfd = accept(listenfd, (SA *)&clientaddr, &clientlen);
		if (connfd < 0)
			continue;
		getnameinfo((SA *)&clientaddr, clientlen, clienthost, MAXLINE, clientport, MAXLINE, 0);
		printf("Connected to (%s %s)\n", clienthost, clientport);
		echo(connfd);
		close(connfd);
	}
	exit(0);
}