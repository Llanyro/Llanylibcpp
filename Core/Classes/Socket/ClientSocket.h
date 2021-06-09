/*
 * ClientSocket.h
 *
 *  Created on: Jun 9, 2021
 *      Author: llanyro
 */

#ifndef CORE_CLASSES_CLIENTSOCKET_H_
#define CORE_CLASSES_CLIENTSOCKET_H_

#ifdef _WIN32
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <string>
#pragma warning(disable:4996)
#elif __unix__
#include <netinet/in.h>
#endif

#include "../../Libs/llanytypeslib.h"

namespace Llanylib {
namespace Core {
namespace Classes {

namespace SimpleLists {
	template<class T>
	class List;
}
namespace Containers {
template<class T>
class SmartPointer;
}

class String;


enum class connect_result {
	Ok,
	ErrorSocketNoDisponible,
	ErrorIpNoValida,
	ErrorConnect,

	ErrorWinsock,

};

class ClientSocket {
	protected:
		sockaddr_in serviceAdress;
		#ifdef __unix__
		int sock;
		#elif _WIN32
		SOCKET sock;
		#endif
	public:
		ClientSocket();
		virtual ~ClientSocket();
		connect_result connectServer(const char* ip, ll_int_t port);
		// Send a string of bytes
		ll_int_t write(const char* bytes, const len_t& len) const;
		// Read n bytes
		String* read(const len_t& bytes) const;
		// Read while c not found (return character too)
		String* read(const char& c) const;
		SimpleLists::List<Containers::SmartPointer<String>>* read_all() const;
		SimpleLists::List<Containers::SmartPointer<String>>* read_all(const len_t& vector_lenght) const;
		ll_int_t closeConnection();
		ll_bool_t clear();
};

} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* CORE_CLASSES_CLIENTSOCKET_H_ */
