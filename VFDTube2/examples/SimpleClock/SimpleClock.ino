#include "VFDTube2.h"

#define TUBE_COUNT 4

VFDTube2 tube(8, 9, 10, 11, TUBE_COUNT);
// DIN on pin #8, OE on pin #9, STCP on pin #10, SHCP on pin #11,
// 6 for sections count in serial
// Pin #9 is with PWM output, so the brightness is adjustable

void setup()
{
    tube.setBrightness(0xc0); // set brightness, range 0x00 - 0xff
    // Serial.begin(9600); // enable for troubleshooting on Serial port

}

// display a basic digital clock pattern
void loop()
{
    static byte s = 56; // second
    static byte m = 34; // minute

    tube.clear();
    tube.setBackgroundColor(White);
    // tube.setBackgroundColor((Color) ((s) / 7));
    // background color shift in every 7 seconds

    if (s & 0x01)
        tube.printf("%02d%02d.", m, s);
    else
        tube.printf("%02d%02d", m, s);

    // tube.setPoint(3);

    tube.display();
    // Serial.print(s); // enable for troubleshooting on Serial port
    delay(1000); // reduce this value to check a fast shifting

    s++;

    if (s == 60)
    {
        s = 0;
        m++;
    }
    if (m == 60)
    {
        m = 0;

    }

}
