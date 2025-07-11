2025-07-08: 
    - QT app can receive data and send data throught serial port
    - Python app is used to print data was sent by QT app
    - fake_device C++ is used to simulate data send to QT app

- [ ] add send feature to python app
- [ ] list available port in QT app
- [ ] save log file

# Create virtual connection with "socat"
socat -d -d pty,raw,echo=0 pty,raw,echo=0
