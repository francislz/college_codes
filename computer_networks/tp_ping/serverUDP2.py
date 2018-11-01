import socket
import os

udp_ip = "127.0.0.1"
udp_port = 5005

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
                     
# Faz o bind local. Associa um socket com um IP e uma Porta.
sock.bind((udp_ip, udp_port))

while True:
	message, addr = sock.recvfrom(1024) # Tamanho do buffer eh 1024 bytes
     
	if message == "EXIT":
		print "Cliente Desconectou"
		break
	else:
		print "messagem recebida:", message
		sock.sendto(message, addr)
