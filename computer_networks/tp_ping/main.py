import sys
from UDPPing import *

ping = UDPPing()
ping.set_timeout(timeout=0.250)
ping.ping()
