#include <DHT.h>                          // Подключение библиотеки для датчика температуры и влажности (DHT11)
#include <iarduino_RF433_Transmitter.h>   // Подключение библиотеки для 433 МГц передатчика (FS1000A)

// Настройка компонентов
iarduino_RF433_Transmitter radio(12);     // Объект передатчика, пин 12 для подключения
DHT dht(2, DHT11);                        // Объект датчика DHT11 на пине 2
const int flamePin = A0;                  // Пин A0 для аналогового выхода датчика пламени
const int analogSignal = A1;              // Пин A1 для аналогового выхода датчика газа
const int digitalSignal = 4;              // Пин 4 для цифрового выхода датчика газа

void setup() {
    Serial.begin(9600);                   // Инициализация серийного порта для отладки
    dht.begin();                          // Инициализация датчика DHT11
    radio.begin();                        // Инициализация передатчика
    radio.setDataRate(i433_1KBPS);        // Установка скорости передачи данных (1 Кбит/с)
    radio.openWritingPipe(5);             // Открытие канала передачи данных (канал 5)
    pinMode(flamePin, INPUT);             // Установка пина для датчика пламени как вход
    pinMode(digitalSignal, INPUT);        // Установка пина для цифрового выхода датчика газа как вход
}

void sendSensorData(int data) {
    radio.write(&data, sizeof(data));     // Передача данных через передатчик
    delay(5000);                          // Задержка на 5 секунд
}

void loop() {
    // Считывание температуры
    float temperature = dht.readTemperature();
    if (!isnan(temperature)) {            // Проверка на корректность данных
        Serial.println("Температура: " + String(temperature) + "°C");
        sendSensorData((int)temperature); // Отправка температуры (приведение к int для упрощения)
    }

    // Считывание данных датчика газа
    int gasValue = analogRead(analogSignal);
    Serial.println("Уровень газа: " + String(gasValue));
    sendSensorData(gasValue);

    // Считывание данных датчика пламени
    int flameValue = analogRead(flamePin);
    Serial.println("Уровень пламени: " + String(flameValue));
    sendSensorData(flameValue);
}
