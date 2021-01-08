import socket
import time

clientSocket = socket.socket()

ip = raw_input("Entrez l'adresse du server: ")

host = ip
port = 2004

print('Waiting for connection response')
try:
    clientSocket.connect((host, port))
except socket.error as e:
    print(str(e))

res = clientSocket.recv(1024)
while True:
    clientSocket.send(str.encode('hello'))
    try:
        res = clientSocket.recv(1024)
        print(res.decode('utf-8'))
    except:
        print("nothing from serv")
    time.sleep(1);

clientSocket.close()
