#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
#include <signal.h>

using namespace std;

#define HOST "localhost"
#define PORT 5000
#define BUFF_SIZE 1024
#define SOCKET_PATH "/home/yoonje/PycharmProjects/python_socket/C++server/server.dat" // Socket file location

int
main()
{
    char buffer[BUFF_SIZE];
    struct sockaddr_un server_addr;
    struct sockaddr_un client_addr;
    socklen_t client_addr_size;
    int server_sock, client_sock;
    int msg_size;

    signal(SIGPIPE, SIG_IGN);

    unlink(SOCKET_PATH);

    // open server socket
    if((server_sock = socket(PF_FILE, SOCK_STREAM, 0)) == -1)
    {
        std::cout << "Server : Can't open stream socket\n";
        exit(0);
    }

    // server_addr init NULL
    memset(&server_addr, 0, sizeof(server_addr));

    // server_addr setting
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH);
    

    // bind the socket
    if(bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr))<0)
    {
        std::cout << "Server : Can't bind local address.\n";
        exit(0);
    }

    std::cout << "Server : wating connection request.\n";

    // wait for connection
    if(listen(server_sock, 5) < 0)
    {
        std::cout << "Server : Can't listening connect.\n";
        exit(0);
    }

    while(1)
    {

        memset(buffer, 0x00, sizeof(buffer));

        // client_addr init NULL
        memset(&client_addr, 0, sizeof(client_addr));
        client_addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);
        
        while(1)
        {
            if(client_sock < 0)
            {
                std::cout << "Server: accept failed.\n";
                exit(0);
            }

            msg_size = read(client_sock, buffer, BUFF_SIZE);
            if(msg_size == 0)
                break;
            std::cout << "Received data: "<< buffer << endl;

            write(client_sock, buffer, msg_size);
            std::cout << "Sent data: "<< buffer << endl;
        }

        close(client_sock);
    }    
    close(server_sock);
    unlink(SOCKET_PATH);
    return 0;
}
