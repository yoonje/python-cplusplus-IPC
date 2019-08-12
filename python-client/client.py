import socket

HOST = "localhost"
PORT = 5000

# AF_UNIX means Local communication, SOCK_STREAM means TCP
try:
    sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    sock.connect((HOST, PORT))
    print("Socket Connected.")
except socket.error as err:
    print("error due to: %s" % err)

while True:
    data = input(">>")  # 임의의 데이터를 입력 받는다.
    sock.sendall(data.encode())
    if data == "end":
        sock.close()
        break
    res = sock.recv(1024)
    print(res.decode())
