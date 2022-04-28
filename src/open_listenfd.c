#include "echo.h"

int open_listenfd(char *port)
{
	struct addrinfo hints, *p, *listp;
	int listenfd, optval = 1;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
	// Setting the AI_PASSIVE flag indicates the caller intends to use the returned socket address structure in a call to the bind function.
	hints.ai_flags |= AI_NUMERICSERV;
	getaddrinfo(NULL, port, &hints, &listp);
	for (p = listp; p != NULL; p = p->ai_next)
	{
		if (listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol) < 0)
			continue;
		/**
		 * @brief 如果想要在套接字级别上设置选项，就必须把level设置为 SOL_SOCKET
		 *
		 */
		setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
		if (bind(listenfd, p->ai_addr, sizeof(struct addrinfo)) == 0)
			break;
		close(listenfd);
	}
	freeaddrinfo(listp);
	if (!p)
		return -1;
	if (listen(listenfd, LISTENQ) < 0)
	{
		close(listenfd);
		return -1;
	}
	return listenfd;
}