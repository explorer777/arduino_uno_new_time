#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
    Serial.begin(9600);

    // ���������� �� � ���������� �� ������ RTC
    if (!rtc.begin()) {
        Serial.println("RTC �� ��������!");
        while (1);
    }

    // ���� ������ RTC ������� ��������, ������������ ��� �� ������ ���� � ���
    if (rtc.lostPower()) {
        Serial.println("RTC ������� ��������, ������������ ���...");

        // ������������ ��� �� ������� ���� �� ���
        //rtc.adjust(DateTime(2024, 4, 17, 20, 20, 0)); //��, �����, ����, ������, �������, �������
    }
}

void loop() {
    // �������� ������� ���� �� ��� �� ������ RTC
    DateTime now = rtc.now();

    // �������� ������� ���� �� ��� �� Serial Monitor
    Serial.print("�������� ���: ");
    printDateTime(now);

    delay(1000); // �������� 1 �������
}

// ������� ��� ������ ���� �� ���� �� Serial Monitor
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
