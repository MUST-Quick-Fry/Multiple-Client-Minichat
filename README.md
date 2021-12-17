# Multiple-Client-Minichat

### Functionality
1. The server can connect to multiple clients with different ports. And then we use the function select to receive different clients’ messages. The sever can chat with different clients at the same time.
2. The server can send ‘\n’ to end the connect with current client. And the server will show another client’s message if one of clients send a message to the server used by the select function.
3. The server and any of the clients send a message which contains “quit”, the server and client will close the socket.

------

### User Manual
+ server.c

`gcc AcceptTCPConnection.c DieWithError.c HandleTCPClient.c CreateTCPServerSocket.c TCPEchoServer-Select.c -o server`
 
`./server 500 8080 8081 8082 8083 8084`

The parameters 8080 - 8084 are the maximum number of the character you input, the list of the port number, respectively.


+ client.c
 
`gcc DieWithError.c TCPEchoClient.c -o client`

`./client 127.0.0.1 8083`