#include "echo.h"

void echo(int connfd)
{
	size_t n;
	char buf[MAXLINE];
	rio_t rio;

	Rio_readinitb(&rio, connfd);

	while (1)
	{
		recv(connfd, buf, MAXLINE, 0);
		printf("%s\n", buf);
		// Fputs(buf, stdout);
		// Rio_writen(connfd, buf, n);
	}
	return;
}