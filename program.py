import serial


data = ""

for i in range(4):
    print("Enter complex number (real and imaginary part separated by a space): ",end = "")
    comp = input().split(" ")
    data += comp[0] + "," + comp[1] + ","


data = data[:-1] + "\n"

ser = serial.Serial('/dev/ttyACM0', 115200)

ser.write(data.encode())

data_received = []

try:
    while True:
        byte_received = ser.read()
        if byte_received == b'\n':
            break
        data_received.append(byte_received)
except KeyboardInterrupt:
    ser.close()

data_received = b''.join(data_received).decode().split(",")
data_received = [(float(data_received[i]), float(data_received[i+1])) for i in range(0,len(data_received),2)]

print("\nDFT of sent signal: ", end = "")
print(data_received)
