# ESP_arithmetics
ESP arithmetics demo

This is a quick demonstation of some of the (unsigned) integer to float conversion problems and possible bugs in C/C++ code in seemingly simple arithmetics.
 
The target device is the M5StickC with an ESP32 CPU, but it can be compiled outside of the Arduino IDE as well.

Although the #ifdefs are for ARDUINO, the code works on ESP32 and ESP8266 CPUs, or any other which supports floating point in printf() calls, what the original Arduino doesn't do.
 
