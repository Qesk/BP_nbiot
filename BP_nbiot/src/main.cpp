#include <Arduino.h>
#include <serialcmds.h>
#include <narrowbandcore.h>
#include <narrowband.h>


HardwareSerial & modem_serial = Serial;
#define DebugSerial     Serial

void setup() {

    DebugSerial.begin(115200);

    modem_serial.begin(115200);

    // Instantiate command adapter as the connection via serial
    Narrowband::ArduinoSerialCommandAdapter ca(modem_serial);

    // Driver class
    Narrowband::NarrowbandCore nbc(ca);

    DebugSerial.print("Module Info: "); 
    DebugSerial.println(nbc.getModuleInfo());

    DebugSerial.print("IMEI: "); 
    DebugSerial.println(nbc.getIMEI());

    DebugSerial.print("IMSI: "); 
    DebugSerial.println(nbc.getIMSI());

}


void loop() {
}
