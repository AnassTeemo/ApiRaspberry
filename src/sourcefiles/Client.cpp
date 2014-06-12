/*
 * Client.cpp
 *
 *  Created on: May 23, 2014
 *      Author: anass
 */
#include "../headers/Client.h"

Client::Client(short _port) :
		port(_port) {

}

void Client::start() {
	s = Create_Socket_Client_TCP("10.42.0.1", port);
}

void Client::writeRequest(short id) {
	id = htons(id);
	write(s, &id, sizeof(id));
}

void Client::sifet(char* tab) {

	std::string requete = "GET /SEND_BYTE HTTP/1.1\r\n";
	std::string vec(tab);
	//short vecsize = vec.size();
	//vecsize = htons(vecsize);

	vec+="\r\n";
	Writer_TCP(s,requete);
	//send(s,&vecsize,sizeof(vecsize),0);
	send(s, vec.data(), vec.size(), 0);

	puts("End Send");
}

void Client::receive(char *param) {

	std::string requete = "GET /RECEIVE_ID HTTP/1.1\r\n";
	Writer_TCP(s,requete);
	//writeRequest(request.GET);
	recv(s, param, 33, 0);

	std::cout << "my 32 bits word is: ";
	for (int j = 0; j < 33; j++)
		std::cout << ' ' << param[j];
	std::cout << '\n';

	puts("End Send");
}

void Client::read_param(int socket, std::vector<std::string>& param) {
	long size = 0;
	if (!read(socket, &size, sizeof(size)))
		fin_connexion(socket, "échec de read");
	else {
		std::cout << "Reading from port: " << port;
		size = ntohl(size);
		for (int i = 0; i < size; ++i) {
			std::string stringRead;
			long length = 0;
			read(socket, &length, sizeof(length));
			length = ntohl(length);
			while (0 < length) {
				char buffer[1024];
				//long len = sizeof(buffer);
				int cread;
				cread = read(socket, buffer,
						std::min((long) sizeof(buffer), length));
				stringRead.append(buffer, cread);
				length -= cread;
			}
			stringRead = stringRead.substr(4);
			param.push_back(stringRead);
		}
		std::cout << "myvector contains:";
		for (std::vector<std::string>::iterator it = param.begin();
				it != param.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
}

int Client::Create_Socket_Client_TCP(const char *Ip, short port) {
	int socket_desc;
	struct sockaddr_in server;

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_desc == -1) {
		throw("Could not create socket");
	}

	server.sin_addr.s_addr = inet_addr(Ip);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);

//Connect to remote server
	if (connect(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
		throw("connect error");
	}

	puts("Connected");

	return socket_desc;

}

void Client::fin_connexion(int socket, const char* msg) {
	fprintf(stderr, "fin de connexion (%s, errno=%s)\n", msg, strerror(errno));
	close(socket);
	pthread_exit(NULL);
}

void Client::Writer_TCP(int s, const std::string & text) {
	int len = send(s, text.data(), text.size(), 0);
	if (len == -1)
		throw("Writer Error");
}
