from email import message
from socket import *
from sqlite3 import connect
serverport = 15213
serversocket = socket(AF_INET, SOCK_STREAM)
serversocket.bind(('', serverport))
serversocket.listen(1)
while True:
    connectSocket, addr = serversocket.accept()
    message = connectSocket.recv(2048).decode().upper().encode()
    connectSocket.send(message)
    connectSocket.close()
