/*
 *  ESP arithmetics demo (C) 2020 MDE
 *  Licensed under the GNU GPLv3
 *
 *  This is a quick demonstation of some of the
 *  integer to float conversion problems and
 *  possible bugs in C/C++ code in seemingly
 *  simple arithmetics.
 *
 *  The target device is the M5StickC with an
 *  ESP32 CPU, but it can be compiled outside
 *  of the Arduino IDE as well.
 *
 *  Although the #ifdefs are for ARDUINO, the
 *  code works on ESP32 and ESP8266 CPUs, or
 *  any other which supports floating point in
 *  printf() calls, what the original Arduino
 *  doesn't do.
 */

//Uncomment the line below for correct results:
//#define USE_SIGNED_INT


#ifdef ARDUINO_M5Stick_C
    #include <M5StickC.h>
    #define log(...) \
        log_all(__VA_ARGS__);
#else
    #define log(...) \
        log_default(__VA_ARGS__);
#endif

#ifdef ARDUINO
    #define log_default(...) \
        Serial.printf(__VA_ARGS__);
#else
    #include <stdio.h>
    #define log_default(...) \
        printf(__VA_ARGS__);
#endif

#define log_all(...) \
    M5.Lcd.printf(__VA_ARGS__); \
    log_default(__VA_ARGS__);


#ifdef USE_SIGNED_INT
    signed int one = 1;
    signed int two = 2;
#else
    unsigned int one = 1;
    unsigned int two = 2;
#endif


float sum;
float diff;


void setup(void)
{

#ifdef ARDUINO_M5Stick_C
    M5.begin();
    M5.Lcd.setRotation(3);
#endif

#ifdef ARDUINO
    Serial.begin(9600);
    while (!Serial) {
    };
#endif

}

void loop() {
#ifdef ARDUINO_M5Stick_C
    M5.Lcd.setCursor(0, 0);
#endif

    sum = (one + two);
    diff = (one - two);

    log("    int sum: %d\n", (one + two));
    log("   int diff: %d\n", (one - two));

    log(" float1 sum: %f\n", ((float)one + two));
    log("float1 diff: %f\n", ((float)one - two));

    log(" float2 sum: %f\n", 1.0 * (one + two));
    log("float2 diff: %f\n", 1.0 * (one - two));

    /* The same result as float1 and float2 sum.
     * commented out to fit everything on the LCD
     */
    //log(" float3 sum: %f\n", sum);

    log("float3 diff: %f\n", diff);

#ifdef ARDUINO
    delay(1000);
#endif
}

#ifdef ARDUINO
#else
void main(void)
{
    loop();
}
#endif
