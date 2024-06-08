# Socket creazione di un Server e Client

## Socket comunicazione tramite protocollo tcp / udp in una rete

```c++
// C++ program to show the example of server application in 
// socket programming 
#include <cstring> 
#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h> 

using namespace std; 

int main() 
{ 
	// creating socket 
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0); 

	// specifying the address 
	sockaddr_in serverAddress; 
	serverAddress.sin_family = AF_INET; 
	serverAddress.sin_port = htons(8080); 
	serverAddress.sin_addr.s_addr = INADDR_ANY; 

	// binding socket. 
	bind(serverSocket, (struct sockaddr*)&serverAddress, 
		sizeof(serverAddress)); 

	// listening to the assigned socket 
	listen(serverSocket, 5); 

	// accepting connection request 
	int clientSocket = accept(serverSocket, nullptr, nullptr); 

	// recieving data 
	char buffer[1024] = { 0 }; 
	recv(clientSocket, buffer, sizeof(buffer), 0); 
	cout << "Message from client: " << buffer << endl; 

	// closing the socket. 
	close(serverSocket); 

	return 0; 
}
```

```c++
// C++ program to illustrate the client application in the 
// socket programming 
#include <cstring> 
#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h> 

int main() 
{ 
    // creating socket 
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0); 

    // specifying address 
    sockaddr_in serverAddress; 
    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_port = htons(8080); 
    serverAddress.sin_addr.s_addr = INADDR_ANY; 

    // sending connection request 
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)); 

    // sending data 
    const char* message = "Hello, server!"; 
    send(clientSocket, message, strlen(message), 0); 

    // closing socket 
    close(clientSocket); 

    return 0; 
}
```