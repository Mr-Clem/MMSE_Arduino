import socket
import time
import serial as sr

clientSocket = socket.socket()

port_serie = sr.Serial(port = "/dev/ttyACM3", baudrate = "9600")
ip = input("Entrez l'adresse du server: ")
sensorName = input("Entrez lne nom de votre capteur: ")

host = ip
port = 2004

print('Waiting for connection response')
try:
    clientSocket.connect((host, port))
except socket.error as e:
    print(str(e))

res = clientSocket.recv(1024)

clientSocket.send(str.encode(sensorName))

while True:
    try:
        tab = port_serie.readline().split()
        ligne = tab[0].decode("utf-8")
    except:
        ligne = ""
    clientSocket.send(str.encode(ligne))
    try:
        res = clientSocket.recv(1024)
        msg = res.decode('utf-8')
        print(msg)
        msg = msg + "\n"
        port_serie.write(msg.encode())

    except:
        print("nothing from serv")
    time.sleep(1);

clientSocket.close()
