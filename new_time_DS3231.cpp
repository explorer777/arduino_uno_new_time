#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
    Serial.begin(9600);

    
    if (!rtc.begin()) {
        Serial.println("RTC íå çíàéäåíî!");
        while (1);
    }

    
    if (rtc.lostPower()) {
        Serial.println("RTC lost power...");

        
        //rtc.adjust(DateTime(2024, 4, 17, 20, 20, 0)); 
    }
}

void loop() {
    DateTime now = rtc.now();
    Serial.print("Ïîòî÷íèé ÷àñ: ");
    printDateTime(now);
}
void printDateTime(DateTime dt) {
    Serial.print(dt.year(), DEC);
    Serial.print('/');
    Serial.print(dt.month(), DEC);
    Serial.print('/');
    Serial.print(dt.day(), DEC);
    Serial.print(" ");
    Serial.print(dt.hour(), DEC);
    Serial.print(':');
    Serial.print(dt.minute(), DEC);
    Serial.print(':');
    Serial.print(dt.second(), DEC);
    Serial.println();
}
