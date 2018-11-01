import socket
import os

udp_ip = "127.0.0.1"
udp_port = 5005

sock = socket.socket(socket.AF_INET, # Internet 
				 socket.SOCK_DGRAM)  # UDP

 
while True:
	sendMessage = raw_input("Digite Sua Mensagem: ")
                     
	if sendMessage == "EXIT":
		sock.sendto(sendMessage, (udp_ip, udp_port))
		break
	else:
		sock.sendto(sendMessage, (udp_ip, udp_port))
		pass