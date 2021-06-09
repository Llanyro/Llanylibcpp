/*
 * ClientSocket.cpp
 *
 *  Created on: Jun 9, 2021
 *      Author: llanyro
 */

#include "ClientSocket.h"

#ifdef _WIN32
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <string>
#pragma warning(disable:4996)
#pragma comment(lib, "Ws2_32.lib")
#elif __unix__
#include <arpa/inet.h>
#include <sys/socket.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <string.h>
#endif

#include "../String.h"
#include "../SimpleLists/List.h"
#include "../Containers/SmartPointer.h"

namespace Llanylib {
namespace Core {
namespace Classes {

ClientSocket::ClientSocket() {
	this->serviceAdress = sockaddr_in();
	#ifdef __unix__
	this->sock = -1;
	#elif _WIN32
	this->sock = INVALID_SOCKET;
	#endif
}
ClientSocket::~ClientSocket() { this->closeConnection(); }

connect_result ClientSocket::connectServer(const char* ip, ll_int_t port) {
	this->clear();
	connect_result result = connect_result::Ok;
	#ifdef _WIN32
	// IF windows
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2),&wsa) != 0)
		result = connectResults::ErrorWinsock;
	#endif

	//Create a socket
	if (result == connect_result::Ok) {
		#ifdef _WIN32
		if((this->sock = socket(AF_INET, SOCK_STREAM, 0 )) == INVALID_SOCKET)
		#elif __unix__
		if((this->sock = socket(AF_INET, SOCK_STREAM, 0 )) < 0)
		#endif
			result = connect_result::ErrorSocketNoDisponible;

		if(result == connect_result::Ok) {
			// Prepare connection to server
			this->serviceAdress.sin_addr.s_addr = inet_addr(ip);
			this->serviceAdress.sin_family = AF_INET;
			this->serviceAdress.sin_port = htons(port);

			//Connect to remote server
			if (connect(this->sock, (struct sockaddr*)&this->serviceAdress, sizeof(this->serviceAdress)) < 0)
				result = connect_result::ErrorConnect;
		}
	}
	return result;
}
ll_int_t ClientSocket::write(const char* bytes, const len_t& len) const {
	ll_int_t result = 0;
	if(bytes != nullptr)
		result = send(this->sock, bytes, len, 0);
	return result;
}
String* ClientSocket::read(const len_t& bytes) const {
	String* str = new String(bytes);
	ll_bool_t continuar = true;
	char* str_content = str->get(0);
	recv(this->sock, str_content, bytes, false);
	return str;
}
SimpleLists::List<Containers::SmartPointer<String>>* ClientSocket::read_all() const { return this->read_all(300); }
SimpleLists::List<Containers::SmartPointer<String>>* ClientSocket::read_all(const len_t& vector_lenght) const {
	SimpleLists::List<Containers::SmartPointer<String>>* list = new
			SimpleLists::List<Containers::SmartPointer<String>>();
	/*ll_bool_t flag = true;
	String* temp;

	do {
		temp = new
		ll_bool_t continuar = true;
		char* str_content = str->get(0);
		recv(this->sock, str_content, bytes, false);



	} while (flag);*/




	return this->read_all(300);
}
ll_int_t ClientSocket::closeConnection() {
	ll_int_t result = 0;
	#ifdef _WIN32
	if(this->sock != INVALID_SOCKET)
		result = closesocket(this->sock);
	this->sock = INVALID_SOCKET;
	#elif __unix__
	//if(this->sock > 0)
	//	result = close(this->sock);
	this->sock = -1;
	#endif
	return result;
}
ll_bool_t ClientSocket::clear() {
	this->closeConnection();
	this->serviceAdress = sockaddr_in();
	return true;
}

} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */
