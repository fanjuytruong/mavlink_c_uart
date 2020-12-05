

# Giao tiếp MAVLINK PIXHAWK 4 và Raspberry PI

## 1.Overview

## 2.Thiết lập ban đầu
### 2.1. Trên board PIXHAWK 4
> Để giao tiếp được với máy tính nhúng qua port TELEMETRY 2, thì cổng này cần được config để thực thi với MAVLINK.

Dùng **QGroundControl** -> vào mục **Vehicle Setup** -> **Parameters**. Thiết lập thông số như sau:
```
MAV_2_CONFIG = TELEM2   \\Dùng port Telemetry 2 làm port giao tiếp MAVLINK2
```
**Khởi động lại board Pixhawk 4, vào lại mục Parameters sẽ hiện thêm các mục sau, hãy config như dưới đây:**
```
MAV_2_MODE = Onboard
MAV_2_RATE = 80000 B/s
MAV_2_FORDWARD = 1
SER_TEL2_BAUD = 921600 8N1
```


### 2.2. Trên Rasberry Pi
> Ta sẽ tiến hành Enabled Serial Port (UART) trên PI

- Mở terminal trên Pi
- Gõ
```
sudo raspi-config
```
- Chọn **"Interfacing Options"**
- Chọn **"P6 Serial"**
- Thông báo "“Would you like a login shell to be accessible over serial?”
```
Chọn NO
```
- Thông báo “Would you like the serial port hardware to be enabled?”
```
Chọn YES
```
- Hoàn tất.



### 2.3. Kết nối phần cứng
Connect Pixhawk4 và Rasberry Pi bằng dây nối theo như dưới đây
            
            ```
            TELEM2 (PIXHAWK 4)              PI (3B+)
            TX ------------------------------ RX (PIN 10)
            RX ------------------------------ TX (PIN 8)
            GND ------------------------------ GND (PIN 6)
            ```



## 3. Run
Trên Pi, truy cập vào thư mục:
```
$ cd mavlink_c_uart
$ make
```
Sau đó chạy thử file mavlink_control
```
./mavlink_control -d /dev/ttyS0
```

Kết quả:
```
OPEN PORT
Connected to /dev/ttyS0 with 921600 baud, 8 data bits, no parity, 1 stop bit (8N1)

START READ THREAD 

CHECK FOR HEARTBEAT
Found

GOT VEHICLE SYSTEM ID: 1
GOT AUTOPILOT COMPONENT ID: 1
...............................

```

_Chúc các bạn thành công_ :penguin:
