import socket
from _thread import *

serversocket = socket.socket()
host = ''
port = 8889
ThreadCount = 0
try:
 serversocket.bind((host, port))
except socket.error as e:
 print(str(e))

print('Waiting for connection...')
serversocket.listen(5)

def threader_client(connection):
 connection.send(str.encode('Welcome to the Server\n'))
 while True:
  data = connection.recv(2048)
  reply = 'Server says: ' + data.decode('utf-8')
  if not data:
   break
  connection.sendall(str.encode(reply))
 connection.close()

while True:
 Client, address = serversocket.accept()
 print('Connected to: ' + address[0] + ':' + str(address[1]))
 start_new_thread(threaded_client, (Client, ))
 ThreadCount += 1
 print('Thread Number: ' + str(ThreadCount))

serversocket.close()
