#include "echo.h"

int open_clientfd(char *hostname, char *port)
{
	int clientfd;
	struct addrinfo hints, *listp, *p;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_socktype = SOCK_STREAM;
	/**
	 *  SOCK_STREAM 有以下几个特征：
		1.数据在传输过程中不会消失；
		2.数据是按照顺序传输的；
		3.数据的发送和接收不是同步的
	 *
	 */
	hints.ai_flags = AI_NUMERICSERV; //返回端口号，默认返回etc/services中的服务名
	//	hints.ai_flags |= AI_NUMERICHOST; //返回数字地址字符串。默认会返回host域名
	hints.ai_flags |= AI_ADDRCONFIG; //推荐设置
	getaddrinfo(hostname, port, &hints, &listp);
	for (p = listp; p != NULL; p = p->ai_next)
	{

		if (clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol) < 0) //尝试创建socket
			continue;
		//	printf("Connect = %d \n", connect(clientfd, p->ai_addr, p->ai_addrlen));

		if (connect(clientfd, p->ai_addr, p->ai_addrlen) != -1) //链接成功
			break;
		//	printf("debug\n");
		close(clientfd);
	}
	freeaddrinfo(listp); //释放地址链表防止内存泄漏。
	if (!p)
		return -1; // Failed
	else
		return clientfd;
}