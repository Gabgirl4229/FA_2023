# Import socket module
import socket

# Create a socket object
s = socket.socket()

# Define the port on which you want to connect
port = 12345

# connect to the server on local computer
s.connect(('127.0.0.1', port))

# receive data from the server and decoding to get the string.
print(s.recv(1024).decode())

# allow client to input chosen command
print(s.recv(1024).decode())

while True:
  command = str(input(''))
  s.send(command.encode())
  print(s.recv(1024).decode())
'''
  
  # NEWFOLDER command
  if (command == 'NEWFOLDER'):
    # receive data from the server
    print(s.recv(1024).decode())

    # collect folder name from client
    name = str(input(''))
    s.send(name.encode())

  if (command == 'NEWFILE'):
    # receive data from the server
    print(s.recv(1024).decode())

    # collect file name from client
    name = str(input(''))
    s.send(name.encode())

  # collect file location from client

  # close the connection
  if (command == 'END'):
    break
s.close()
'''
