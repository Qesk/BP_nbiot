#include <commandadapter.h>
#include <mockcommandadapter.h>
#include <narrowband.h>
#include <narrowbandcore.h>
#include <nbdbg.h>
#include <nbutils.h>
#include <serialcmds.h>

// Select serial object for modem communication
// Please look at the specs of your board and locate
// the Serial object with a pin mapping compatible to
// the shield you're using.
HardwareSerial& modem_serial = Serial;      // Serial1
#define DebugSerial  Serial

void setup() {
    // connection speed to your terminal (e.g. via USB)
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
