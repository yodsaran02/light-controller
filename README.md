# Light-Controller
#### Video Demo: https://www.youtube.com/watch?v=ACf7QT2l790
#### Description: This Project is created for Controlling Led lights using Arduino(FastLed.h Library) and raspberry pi(works on other devices!) By using the Flask web application, Edit the serial port before running the flask server, Server opens on port 5000, Try to install it from Installation and run it from Usage, also check out on demo to see the demo web page.

#### About This project: I got Inspire from an IoT device, but the app and the device are expensive, so I decided to build my own with my raspberry pi and Arduino board, using flask and serial to communicate with the web browser and Arduino board.

#### Build by:
- Python
- CSS
- Bootstrap
- Flask
- Arduino(FastLED library)
- HTML

#### Installation: Install python package, Flash, and complie the code on Arduino using Arduino ide(or Arduino-CLI).
```bash
pip3 install flask
pip3 install pyserial
pip3 install serial
```

#### Usage: Run the flask server (Don't forget to change the serial port in app.py) and plug Arduino into the first USB port in raspberry pi(or other devices), Use The /dev/ttyUSB0 port (The port might not be the same on other devices).

```
...
app.config["TEMPLATES_AUTO_RELOAD"] = True
arduino = serial.Serial(port="<serial port>",baudrate=9600)
time.sleep(3)
...
```

```bash
python3 -m serial.tools.miniterm

--- Available ports:
---  1: /dev/ttyAMA0         'ttyAMA0' (The port might not be the same on other devices)
---  2: /dev/ttyUSB0         'USB Serial' (The port might not be the same on other devices)
--- Enter port index or full name: 2
--- Miniterm on /dev/ttyUSB0  9600,8,N,1 ---
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---

(Try typing Red to check if the Arduino is working)

```

```bash
python3 -m flask run --host 0.0.0.0

WARNING: This is a development server. Do not use it in a production deployment. Use a production WSGI server instead.
 * Running on all addresses (0.0.0.0)
 * Running on http://127.0.0.1:5000
 * Running on http://192.168.1.110:5000
Press CTRL+C to quit
```


#### Demo: Web app page ![alt text](https://i.ibb.co/c834Pvm/1666589175038.jpg)


#### Things that might improve in the future:
- Change from Arduino to esp board(Don't need to use Rpi anymore!).
- improve the User interface to be more simple and cleaner.
- Add function to control using TFT screen connected to Esp board.
- Add more color to display in the web application
- Make web app more compatible with older device

#### Contact: yodsaran02@gmail.com.
