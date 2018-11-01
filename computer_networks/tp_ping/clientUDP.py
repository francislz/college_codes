import socket
import os

udp_ip = "ibiza.dcc.ufla.br"
udp_port = 5002

sock = socket.socket(socket.AF_INET, # Internet 
				 socket.SOCK_DGRAM)  # UDP
 
while True:
	sendMessage = "Mensagem"
	response = sock.sendto(sendMessage, (udp_ip, udp_port))
	print(response)
		