import serial
s = serial.Serial(port='/dev/tty.usbserial-A103VO60', baudrate=9600)

s.write('text')
s.read()
s.readline()