import socket
import os
import time

class UDPPing:
    udp_ip = ""
    udp_port = 0
    packet_loss = 0
    packet_count = 0
    message = ""
    sock = None

    def __init__(self, udp_ip='ibiza.dcc.ufla.br', udp_port=5002, packet_count=20, message="Default"):
        self.udp_ip = udp_ip
        self.udp_port = udp_port
        self.packet_count = packet_count
        self.message = message
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    def set_timeout(self, timeout=0.250):
        self.sock.settimeout(timeout)

    def get_response(self):
        while True:
            try:
                message, addr = self.sock.recvfrom(self.udp_port)
                return message
            except Exception:
                return 'timeout'

    def send_message(self):
        self.sock.sendto(self.message, (self.udp_ip, self.udp_port))
        return self.get_response()
    
    def ping(self):
        i = 0
        sum_rtt = 0
        while i < self.packet_count:
            time.sleep(1)
            self.message = 'PING ' + str(i)

            send_time_ms = time.time()
            response = self.send_message()
            recv_time_ms = time.time()
            rtt_in_ms = round((recv_time_ms - send_time_ms) * 1000, 3)

            if rtt_in_ms < 250:
                sum_rtt = sum_rtt + rtt_in_ms

            if response == 'timeout' or rtt_in_ms >= 250:
                self.packet_loss = self.packet_loss + 1
                response = 'timeout'
            elif response != 'timeout':
                response = ""

            print(
                str(len(self.message.encode('utf-8'))) + 'bytes ' + self.udp_ip + ':' 
                + str(self.udp_port) 
                + ' icmp_seq=' + str(i) 
                + ' time=' + str(rtt_in_ms)
                + ' ' + response
            )
            i = i + 1
        
        print('MEAN RTT: ' + str((sum_rtt/(self.packet_count - self.packet_loss))))
        print('PACKET LOSS: ' + str((self.packet_loss * 100)/20) + '%')
