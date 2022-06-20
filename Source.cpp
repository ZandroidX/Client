#include <WS2tcpip.h>
#include <Windows.h>
#include <iostream>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

WSAData wData;
WORD ver = MAKEWORD(2, 2);


int main() {
	int wsOk = WSAStartup(ver, &wData);
	if (wsOk != 0) {
		std::cerr << "Error Initializing WinSock! Exiting" << std::endl;
		return -1;
	}
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	//Bind IP address to port
	sockaddr_in sockin;
	sockin.sin_family = AF_INET;
	sockin.sin_port = htons(8081);
	sockin.sin_addr.S_un.S_addr = (ULONG) "127.0.0.1";

	//Connect to server
	connect(sock, (sockaddr*)&sockin, sizeof(sockaddr));
}