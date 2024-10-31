#include <Wire.h>
#include "RTClib.h"


RTC_DS1307 rtc;
int second, minute, hour;
DateTime hoursFecha;
const int relayPin = 2;
int arrOFFHours[8] = {0, 5, 6, 11, 12, 17, 18, 23};

void setup()
{
  pinMode( relayPin, OUTPUT);
  Serial.begin(115200);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
}

void loop()
{

  DateTime currentTime = rtc.now();
  second = currentTime.second();
  minute = currentTime.minute();
  hour = currentTime.hour();
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
   Serial.print(":");
    Serial.print(second);
   Serial.println();

  if (arrayIncludeElement(arrOFFHours, hour) && minute >= 0 && minute < 60) {
    Serial.print("Find - OFF");
    digitalWrite( relayPin, LOW);
     Serial.println();
  } else {
    Serial.print("NOT Find - ON");
    digitalWrite( relayPin, HIGH);
     Serial.println();

  }
delay( 1000);

  // digitalWrite( relayPin, HIGH);
  // Serial.println(digitalRead(relayPin));
  // delay( 3000);
  // digitalWrite( relayPin, LOW);
  // Serial.println(digitalRead(relayPin));
  // delay( 1000);
}

boolean arrayIncludeElement(int array[], int element) {
  for (int i = 0; i < 8; i++) {
    if (array[i] == element) {
      return true;
    }
  }
  return false;
}
