# Installing the Asynchronous Web Server library

### 1. ESP8266 Asynchronous Web Server

To build the web server we’ll use the [ESPAsyncWebServer library](https://github.com/me-no-dev/ESPAsyncWebServer) that provides an easy way to build an asynchronous web server. Building an asynchronous web server has several advantages. We recommend taking a quick look at the [library documentation on its GitHub page](https://github.com/me-no-dev/ESPAsyncWebServer).

#### Installing the ESPAsyncWebServer library

The ESPAsyncWebServer library is not available to install in the Arduino IDE Library Manager. So, you need to install it manually.

Follow the next steps to install the ESPAsyncWebServer library:

1. [Click here to download the ESPAsyncWebServer library](https://github.com/me-no-dev/ESPAsyncWebServer/archive/master.zip). You should have a .zip folder in your Downloads folder
2. Unzip the .zip folder and you should get _ESPAsyncWebServer-master_ folder
3. Rename your folder from ~~ESPAsyncWebServer-master~~ to _ESPAsyncWebServer_
4. Move the _ESPAsyncWebServer_ folder to your Arduino IDE installation libraries folder

**Installing the ESPAsync TCP Library**

The ESPAsyncWebServer library requires the [ESPAsyncTCP](https://github.com/me-no-dev/ESPAsyncTCP) library to work. Follow the next steps to install that library:

1. [Click here to download the ESPAsyncTCP library](https://github.com/me-no-dev/ESPAsyncTCP/archive/master.zip). You should have a .zip folder in your Downloads folder
2. Unzip the .zip folder and you should get _ESPAsyncTCP-master_ folder
3. Rename your folder from ~~ESPAsyncTCP-master~~ to _ESPAsyncTCP_
4. Move the _ESPAsyncTCP_ folder to your Arduino IDE installation libraries folder
5. Finally, re-open your Arduino IDE.



