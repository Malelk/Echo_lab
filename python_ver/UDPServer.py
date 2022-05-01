from socket import *
serverport = 12000
serversocket = socket(AF_INET, SOCK_DGRAM)
serversocket.bind(('', serverport))
print('Server Ready')
while True:
    message, clientAddress = serversocket.recvfrom(2048)
    print(message.decode()+'\n')
    modified = message.decode().upper()
    serversocket.sendto(modified.encode(), clientAddress)
