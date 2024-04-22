#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
    Serial.begin(9600);

    // Перевіряємо чи є підключення до модулю RTC
    if (!rtc.begin()) {
        Serial.println("RTC не знайдено!");
        while (1);
    }

    // Якщо модуль RTC втратив живлення, встановлюємо час на задану дату і час
    if (rtc.lostPower()) {
        Serial.println("RTC втратив живлення, встановлюємо час...");

        // Встановлюємо час на вказану дату та час
        //rtc.adjust(DateTime(2024, 4, 17, 20, 20, 0)); //рік, місяць, день, години, хвилини, секунди
    }
}

void loop() {
    // Отримуємо поточну дату та час від модуля RTC
    DateTime now = rtc.now();

    // Виводимо поточну дату та час на Serial Monitor
    Serial.print("Поточний час: ");
    printDateTime(now);

    delay(1000); // Затримка 1 секунда
}

// Функція для виводу дати та часу на Serial Monitor
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
