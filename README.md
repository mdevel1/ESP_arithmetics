# ESP_arithmetics
ESP arithmetics demo

This is a quick demonstation of some of the (unsigned) integer to float
conversion problems and possible bugs in C/C++ code in seemingly simple
arithmetics.
 
The target device is the M5StickC with an ESP32 CPU, but it can be
compiled outside of the Arduino IDE as well.

Although the #ifdefs are for ARDUINO, the code works on ESP32 and ESP8266
CPUs, or any other which supports floating point in printf() calls, what
the original Arduino doesn't do.

For easy compilation with GCC outside of the IDE you can use the
directory 'c' with a symlink inside it to the Arduino sketch file.

The output of the program:

~~~~
    int sum: 3
   int diff: -1
 float1 sum: 3.000000
float1 diff: -1.000000
 float2 sum: 3.000000
float2 diff: 4294967295.000000
float3 diff: 4294967296.000000
~~~~
