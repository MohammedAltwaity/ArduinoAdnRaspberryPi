from smbus import SMBus
import time

addr = 0x8  # Arduino I2C address
bus = SMBus(1)  # Indicates /dev/i2c-1 on Raspberry Pi

def read_string():
    try:
        byte_data = bus.read_i2c_block_data(addr, 0, 32)  # Read up to 32 bytes
        s = ''
        for byte in byte_data:
            if byte != 255 and byte != 0:  # Filter out unwanted bytes
                s += chr(byte)  # Convert byte to character and append to string
        return s
    except Exception as e:
        print(f"Error reading from I2C bus: {e}")
        return ""

print("Requesting string from Arduino...")
received = read_string()
print(f"Received: {received}")
