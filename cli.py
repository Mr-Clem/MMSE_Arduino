import socket
import time
import serial as sr

clientSocket = socket.socket()

port_serie = sr.Serial(port = "/dev/ttyACM0", baudrate = "9600")
ip = input("Server IP: ")
sensorName = input("Sensor name: ")

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
        print("Nothing from serv")
    #time.sleep(1);

clientSocket.close()
