import serial

def init_serial():
    arduino_serial =  serial.Serial()
    arduino_serial.baudrate = 9600
    arduino_serial.port = 'COM3'
    arduino_serial.open()
    # arduino_serial.write(b'hello')
    print(arduino_serial)
    arduino_serial.flush()
    return arduino_serial

def init_audio_player():
    pass

def start_arduino_show(arduino_serial):
    # input_text = input("Enter: ")
    input_text = 's'
    arduino_serial.write(input_text.encode())

def start_music(timeout=5):
    pass

def main():
    arduino_serial = init_serial()
    init_audio_player()

    start_arduino_show(arduino_serial)
    start_music(10)

    # try:
    #     while True:    
    #         if arduino_serial.readable():
    #             data = arduino_serial.readline().decode().strip()
    #             print(data)
    #             # arduino_serial.flush()
    #             break

    # except KeyboardInterrupt:
    #     arduino_serial.close()

if __name__ == "__main__":
    main()