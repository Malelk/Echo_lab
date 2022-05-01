from socket import *
serverName = 'localhost'
serverport = 15213
clientsocket = socket(AF_INET, SOCK_STREAM)
clientsocket.connect((serverName, serverport))
message = raw_input('Input')
clientsocket.send(message.encode())
modified = clientsocket.recv(2048).decode()
print(modified)
clientsocket.close()
