import sys, json, serial, time

#RECEIVING ARGUMENTS FOR FUNCTIONS FROM COMMAND LINE (FROM PHP)
#relay_node = sys.argv[1]
#switch_request = sys.argv[2]
switch_request = 'RELAY_ON'
relay_status = ''

#Open serial port for the XBee located at /dev/ttyUSB0
ser = serial.Serial('/dev/ttyUSB0', baudrate=19200)
if switch_request == 'RELAY_ON' :
    #writes O to qwqbe processed by Arduino, running C++, makes for less memory allocation
    ser.write('1')
    time.sleep(1)
    ser.write('0')
    time.sleep(1)
    relay_status = 'relay_up'
if switch_request == 'RELAY_OFF' :
    ser.write('0')
    time.sleep(1)
    relay_status = 'relay_down'

#Return the status of relay back to PHP script
print relay_status
