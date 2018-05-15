import serial
import time
import sys
ser = serial.Serial('/dev/ttyUSB0',19200)
relay_status = ''
relay_node = sys.argv[1]
switch_request = sys.argv[2]
time.sleep(1.8)

if switch_request == 'RELAY_ON' :
    ser.write('0')
    relay_status = 'relay_up'
elif switch_request == 'RELAY_OFF' :
    ser.write('1')
    relay_status = 'relay_down'
print relay_status
