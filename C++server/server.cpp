#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

#define HOST = "localhost"
#define PORT = 5000
#define BUFF_SIZE 1024

int main(int argc, char *argv[])
{
    char buffer[BUFF_SIZE];
    struct sockaddr server_addr, client_addr;
    char temp[20];
    int server_fd, client_fd; // server_fd, client_fd : each socket number
    int len, msg_size;

    // open server socket
    if((server_fd = socket(PF_LOCAL, SOCK_STREAM, 0)) == -1)
    {
        std::cout << "Server : Can't open stream socket\n";
        exit(0);
    }

    // server_addr init NULL
    memset(&server_addr, 0, sizeof(server_addr));

    // server_addr setting
    server_addr.sa_family = PF_LOCAL;

    // bind the socket
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) <0)
    {
        std::cout << "Server : Can't bind local address.\n";
        exit(0);
    }

    // wait for connection
    if(listen(server_fd, 5) < 0)
    {
        std::cout << "Server : Can't listening connect.\n";
        exit(0);
    }

    memset(buffer, 0x00, sizeof(buffer));
    std::cout << "Server : wating connection request.\n";
    client_addr_size = sizeof(client_addr)

    while(1)
    {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_size);
        if(client_fd < 0)
        {
            std::cout << "Server: accept failed.\n";
            exit(0);
        }

        msg_size = read(client_fd, buffer, BUFF_SIZE);
        write(client_fd, buffer, msg_size);
        close(client_fd);
        std::cout << "Server : %s client closed.\n", temp;
    }
    close(server_fd);
    return 0;
}