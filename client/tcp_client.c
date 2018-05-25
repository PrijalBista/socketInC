#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(){
	printf("Tcp CLinet");
	//CREATE NETWORK SOCKET
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	//specify address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	int conn_status =connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if(conn_status==-1){printf("\nError in connection to the address");}

	//recieve data from the server
	char server_response[200];
	recv(network_socket, server_response,sizeof(server_response), 0);
	
	//print the data recieved from the other pc (server)
	printf("the server sent data: %s",server_response);
	//close the socket conn
	close(network_socket);

	return 0;
}
