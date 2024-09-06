# import the socket library and operating system
import os
import socket
from _thread import start_new_thread


def start_server():
  # create a socket object
  s = socket.socket()
  print("Socket successfully created")

  # reserve a port on your computer
  host = ''
  port = 12345

  # Next bind to the port using an empty string to listen to requests
  s.bind((host, port))
  print("socket binded to %s" % (port))

  # put the socket into listening mode
  s.listen(5)
  print("socket is listening")

  # loop for server to accept multiple clients
  while True:
    accept_connection(s)


def accept_connection(s):
  # establish connection with client
  c, addr = s.accept()
  print('Connected to: ' + addr[0] + ':' + str(addr[1]))
  # start a new thread
  start_new_thread(client_handler, (c, ))


def client_handler(c):
  # send a thank you message to the client
  c.send('Thank you for connecting!\n'.encode())

  # prompt client for command
  c.send('Please enter a command name: '.encode())

  while True:
    # listen for commands from client
    command = (c.recv(1024).decode())
    print(command)
  '''
      # command to create a new folder
      if (command == 'NEWFOLDER'):
        c.send('Please enter the name of your folder: '.encode())

        #create a path for the project to follow
        path = c.recv(1024).decode()

        #create new single directory (if it doesn't already exist)
        if not (os.path.exists(path)):
          os.mkdir(path)

          #check if the folder was made properly
          if (os.path.exists(path)):
            print("The folder %s was created successfully\n" % path)
          else:
            print("The folder could not be created\n")
        else:
          print("The folder at %s already exists\n" % path)

    # command to close the connection
    if (command == 'END'):
       # Close the connection with the client
       print('Disconnected from client')
       break
  c.close()
  '''


# command to start server
start_server()
