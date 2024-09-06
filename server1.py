# import the socket library and operating system
import os
import socket

# create a socket object
s = socket.socket()
print("Server created")
port = 12345

# Next bind to the port using an empty string to listen to requests
s.bind(('', port))
print("Socket binded to %s" % (port))

# put the socket into listening mode
s.listen(5)
print("Socket is listening")

# loops forever until an interrupt or error occurs
while True:

  # Establish connection with client.
  c, addr = s.accept()
  print('Connected to: ', addr)

  # send a thank you message to the client. encoding to send byte type.
  c.send('Thank you for connecting!\n'.encode())

  c.send('Please enter a command name: '.encode())
  command = c.recv(1024).decode()

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

    # Close the connection with the client
    c.close()
    break