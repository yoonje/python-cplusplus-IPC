## Python Cplusplus IPC 
Between Python(Client) process and C++(Server) process inter communication by socket file(.sock).<br>

### Usage
- You should run C++ process before run Python process.
- C++ server run infinitely, Python Client run once.

### My Setting
`HOST = localhost`<br>
`PORT = 5000`<br>
`SOCKET_PATH = "/home/yoonje/PycharmProjects/python_socket/C++server/server.dat"`

### Socket Progress
- TCP/IP communication function order<br>
![tetris auto fast](image/tcp_prog.gif)

- Server<br>
![tetris auto fast](image/tcp_prog_001.gif)

- Client<br>
![tetris auto fast](image/tcp_prog_002.gif)
