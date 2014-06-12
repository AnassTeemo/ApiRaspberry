/*
 * Client.h
 *
 *  Created on: May 23, 2014
 *      Author: anass
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include<stdio.h>
#include<string.h>    //strlen
#include <iostream>
#include <vector>
#include <errno.h>

#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write

class Client {
public:
	//Client(){};
	Client(short);
	virtual ~Client() {};

	void start();
	void receive(char*);
	void sifet(char*);
private:
	int Create_Socket_Client_TCP(const char *Ip, short port);
	void read_param(int socket, std::vector<std::string>&);
	void fin_connexion(int socket, const char* msg);
	void Writer_TCP(int s, const std::string & text);
	void writeRequest(short id);

private:
	short port;
	int s;

};

#endif /* CLIENT_H_ */
