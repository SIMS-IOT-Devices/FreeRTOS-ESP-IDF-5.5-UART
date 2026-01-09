import serial
import time

# Open COM6
ser = serial.Serial(
    port='COM6',
    baudrate=115200,
    timeout=1
)

time.sleep(2)  # Give ESP32 time to reset

# Send a string
message = "Hello to ESP32\n"
ser.write(message.encode('utf-8'))

print("Sent:", message)

ser.close()
