import socket
import os
from _thread import *
import time
import numpy as np

ServerSideSocket = socket.socket()
host = socket.gethostbyname(socket.gethostname())
port = 2004
ThreadCount = 0

sensors=[]
dangertab=[]
try:
    ServerSideSocket.bind((host, port))
except socket.error as e:
    print(str(e))

print('Socket is listening..')
ServerSideSocket.listen(5)

def multi_threaded_client(connection, number):
    connection.send(str.encode('Server is working:'))
    data = connection.recv(2048)
    newSensor = data.decode('utf-8')
    global sensors
    global dangertab
    sensors = np.append(sensors,newSensor)
    dangertab = np.append(dangertab, False)
    while True:
        data = connection.recv(2048)
        if(data.decode('utf-8') == "DANGER"):
            sensors[number-1] = True
        else:
            sensors[number-1] = False
        response = 'Client message: ' + data.decode('utf-8')
        print(response)
        connection.sendall(str.encode('received'))
        time.sleep(1);
    connection.close()

while True:
    Client, address = ServerSideSocket.accept()
    print('Connected to: ' + address[0] + ':' + str(address[1]))
    ThreadCount += 1
    start_new_thread(multi_threaded_client, (Client, ThreadCount, ))
    print('Thread Number: ' + str(ThreadCount))
    time.sleep(1)
ServerSideSocket.close()
