#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// ---------------- BASE CLASS ----------------
class Device {
  public:
    virtual void update() = 0;
};

// ---------------- LIGHT CLASS ----------------
class Light : public Device {

  private:
    int ldrPin;
    int ledPin;

  public:
    Light(int ldr, int led) {

      ldrPin = ldr;
      ledPin = led;

      pinMode(ledPin, OUTPUT);
    }

    void update() {

      int lightValue = analogRead(ldrPin);

      Serial.print("LDR Value: ");
      Serial.println(lightValue);

      if (lightValue < 300) {
        digitalWrite(ledPin, HIGH);
      }
      else {
        digitalWrite(ledPin, LOW);
      }
    }
};

// ---------------- FAN CLASS ----------------
class Fan : public Device {

  private:
    int IN3;
    int IN4;

  public:
    Fan(int pin3, int pin4) {

      IN3 = pin3;
      IN4 = pin4;

      pinMode(IN3, OUTPUT);
      pinMode(IN4, OUTPUT);
    }

    void update() {

      float temp = dht.readTemperature();

      if (isnan(temp)) {
        Serial.println("DHT Error");
        return;
      }

      Serial.print("Temperature: ");
      Serial.print(temp);
      Serial.println(" C");

      // FAN CONTROL
      if (temp > 37) {

        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);

        Serial.println("Fan ON");
      }
      else {

        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);

        Serial.println("Fan OFF");
      }
    }
};

// ---------------- OBJECTS ----------------
Light roomLight(A0, 8);
Fan roomFan(9, 10);

void setup() {

  Serial.begin(9600);

  dht.begin();
}

void loop() {

  roomLight.update();

  roomFan.update();

  delay(2000);
}
