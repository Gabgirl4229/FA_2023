# Import socket module
import socket

# Create a socket object
s = socket.socket()
port = 12345

# connect to the server on local computer
s.connect(('127.0.0.1', port))

# receive data from the server and decoding to get the string.
print(s.recv(1024).decode())

# allow client to input folder command
command = str(input(''))
s.send(command.encode())

# receive data from the server again
print(s.recv(1024).decode())

# collect folder name from client
name = str(input(''))
s.send(name.encode())

# close the connection
s.close()