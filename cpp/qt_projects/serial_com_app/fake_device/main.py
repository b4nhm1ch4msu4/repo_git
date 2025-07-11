import serial
import threading
import sys

def read_from_serial(ser):
    while True:
        try:
            data = ser.readline()
            if data:
                decoded = data.decode().strip()
                print(f"[Serial com app]: {decoded}")
                # Optional: Gửi phản hồi tự động
                # reply = f"fake device received: {decoded}\n"
                # ser.write(reply.encode())
        except Exception as e:
            print(f"[Error reading serial] {e}")
            break

def main():
    ser_addr = input("Enter serial port (e.g. /dev/pts/1): ")
    try:
        ser = serial.Serial(ser_addr, 9600, timeout=1)
    except serial.SerialException as e:
        print(f"Failed to open port: {e}")
        return

    print(f"Connected to {ser.name}")
    print("Type messages to send to serial. Press Ctrl+C to exit.\n")

    # Start serial reading thread
    serial_thread = threading.Thread(target=read_from_serial, args=(ser,), daemon=True)
    serial_thread.start()

    # Main loop: user input
    try:
        while True:
            if (ser.readline()):
                continue
            user_input = input()
            sys.stdout.write("\033[F")  # Move cursor up one line
            sys.stdout.write("\033[K")  # Clear to the end of line
            sys.stdout.flush()
            print(f"[Fake devices]: {user_input}")
            if user_input:
                ser.write((user_input.strip() + '\n').encode())
    except KeyboardInterrupt:
        print("\nExiting...")
    finally:
        ser.close()

if __name__ == "__main__":
    main()

