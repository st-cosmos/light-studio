
import serial

arduino_serial =  serial.Serial()
arduino_serial.baudrate = 9600
arduino_serial.port = 'COM3'
arduino_serial.open()
# arduino_serial.write(b'hello')
print(arduino_serial)
arduino_serial.flush()

input_text = input("Enter: ")

try:
    while True:    
        arduino_serial.write(input_text.encode())

        if arduino_serial.readable():
            data = arduino_serial.readline().decode().strip()
            print(data)
            # arduino_serial.flush()
            break

except KeyboardInterrupt:
    arduino_serial.close()