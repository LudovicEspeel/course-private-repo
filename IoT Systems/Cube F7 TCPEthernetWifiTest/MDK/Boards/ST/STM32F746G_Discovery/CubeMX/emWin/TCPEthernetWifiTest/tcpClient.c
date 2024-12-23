#include "settings.h"
#ifdef ETHERNET
#include "rl_net.h"
#include "TCPClient.h"
#include "usart1.h"
#include <string.h>
#include <stdio.h>

int32_t socket_fd = -1;

void OpenTCPConnection()
{
	if (socket_fd < 0)
	{
		SOCKADDR_IN server_addr;
		int result;
		int ip_addres[] = {192, 168, 1, 11};

		socket_fd = socket(AF_INET, SOCK_STREAM, 0); // SOCK_STREAM for TCP
		if (socket_fd < 0)
		{
			printf("Failed creating socket.\r\n");
		}
		else
		{
			server_addr.sin_family = AF_INET;
			server_addr.sin_port = htons(3100); // port
			server_addr.sin_addr.s_b1 = ip_addres[0];
			server_addr.sin_addr.s_b2 = ip_addres[1];
			server_addr.sin_addr.s_b3 = ip_addres[2];
			server_addr.sin_addr.s_b4 = ip_addres[3];
			// server_addr.sin_addr.s_addr = ip_addres[0] << 24 | ip_addres[1] << 16 | ip_addres[2] << 8 | ip_addres[3];

			result = connect(socket_fd, (SOCKADDR *)&server_addr, sizeof(server_addr));
			if (result < 0)
			{
				printf("Failed creating connection.\r\n");
				closesocket(socket_fd);
			}
		}
	}
}

void SendTCPMessage(char *message, uint32_t size)
{

	if (socket_fd > 0)
	{
		int result = send(socket_fd, message, size, 0);
		if (result < 0)
		{
			printf("Sending failed.\r\n");
		}
	}
}

int32_t ReceiveTCPMessage(char *buffer, uint32_t size)
{

	if (socket_fd > 0)
	{
		uint32_t bytesReceived = recv(socket_fd, buffer, size, 0);
		if (bytesReceived < 0)
		{
			printf("Receiving failed.\r\n");
		}
		else
		{
			buffer[bytesReceived] = '\0';
			return bytesReceived;
		}
	}
	return -1;
}

void CloseTCPConnection()
{
	if (socket_fd > 0)
	{
		closesocket(socket_fd);
		socket_fd = -1;
	}
}
#endif