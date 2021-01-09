# MMSE_Arduino

Project in collaboration with Luka Moraiz, Florian Gardes and Alex Portes Narrieu.

How to use:
* Your arduino must be plugged to your client PC.
* Run serv.py using python 3 as below:
  ```bash
  $python3 serv.py
  ```
* Run clients using python 3 as below:
  ```bash
  $python3 client.py
  > Entrez l adresse du server : <server address>
  > Entrez le nom de votre capteur : <sensor name>
  ```

Depending of the number of sensor that send "DANGER" to the server, the message on each
client LCD display will be different. 
You can run as many clients as you want.
