import socket

HOST = 'localhost'
PORT = 5000
SOCKET_PATH = "/home/yoonje/PycharmProjects/python_socket/C++server/connection.sock"  # Socket file location
BUFF_SIZE = 1024

try:
    client_sock = socket.socket(socket.AF_UNIX,
                                socket.SOCK_STREAM)  # AF_UNIX means local communication, SOCK_STREAM means TCP
    client_sock.connect(SOCKET_PATH)
    print("Socket Connected.")
except socket.error as err:
    print("error due to: %s" % err)
    exit(0)

data = input(">>")
client_sock.sendall(data.encode())
print("SEND:", data)
res = client_sock.recv(BUFF_SIZE)
print("RECEIVE:", res.decode())
client_sock.close()
