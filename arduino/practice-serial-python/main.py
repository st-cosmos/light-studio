import serial
import pygame

AUDIO_FILE_PATH = './the_greate_escape.wav'

def init_serial():
    arduino_serial = serial.Serial()
    arduino_serial.baudrate = 9600
    arduino_serial.port = 'COM3'
    arduino_serial.open()
    # arduino_serial.write(b'hello')
    # print(arduino_serial)
    arduino_serial.flush()
    return arduino_serial

def init_audio_player():
    pygame.init()
    pygame.mixer.init()
    audio = pygame.mixer.Sound(AUDIO_FILE_PATH)
    return audio

def start_arduino_show(arduino_serial):
    # input_text = input("Enter: ")
    # input_text = 's'
    # arduino_serial.write(b's')
    arduino_serial.write('s'.encode())

    # for _ in range(10):
    #     if arduino_serial.readable():
    #         data = arduino_serial.readline().decode().strip()
    #         print(data)
    #         # arduino_serial.flush()
    #         break

def start_music(audio, timeout=5):
    audio.play()
    pygame.time.wait(timeout * 1000)

def main():
    arduino_serial = init_serial()
    print(arduino_serial)
    audio = init_audio_player()

    pygame.time.wait(200)
    start_arduino_show(arduino_serial)
    start_music(audio, 64)

    arduino_serial.write('q'.encode())
    arduino_serial.close()
    pygame.quit()

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

