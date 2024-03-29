/*
vcc = 3.3v
gnd = gnd
clk = IO22
DT = IO23
SW = IO21
*/

#include "AiEsp32RotaryEncoder.h"
#include "Arduino.h"

#define ROTARY_DT_PIN 23
#define ROTARY_CLK_PIN 22
#define ROTARY_SW_PIN 21
#define ROTARY_VCC_PIN -1
#define ROTARY_STEPS 4

//instead of changing here, rather change numbers above
AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_DT_PIN, ROTARY_CLK_PIN, ROTARY_SW_PIN, ROTARY_VCC_PIN, ROTARY_STEPS);

void rotary_onButtonClick()
{
    static unsigned long lastTimePressed = 0; // Soft debouncing
    if (millis() - lastTimePressed < 500)
    {
            return;
    }
    lastTimePressed = millis();
    Serial.print("button pressed ");
    Serial.print(millis());
    Serial.println(" milliseconds after restart");
}

void rotary_loop()
{
    //dont print anything unless value changed
    if (rotaryEncoder.encoderChanged())
    {
            Serial.print("Value: ");
            Serial.println(rotaryEncoder.readEncoder());
    }
    if (rotaryEncoder.isEncoderButtonClicked())
    {
            rotary_onButtonClick();
    }
}

void IRAM_ATTR readEncoderISR()
{
    rotaryEncoder.readEncoder_ISR();
}

void setup()
{
    Serial.begin(115200);

    //we must initialize rotary encoder
    rotaryEncoder.begin();
    rotaryEncoder.setup(readEncoderISR);
    //set boundaries and if values should cycle or not
    //in this example we will set possible values between 0 and 1000;
    bool circleValues = false;
    rotaryEncoder.setBoundaries(0, 1000, circleValues); //minValue, maxValue, circleValues true|false (when max go to min and vice versa)

    //rotaryEncoder.disableAcceleration(); //acceleration is now enabled by default - disable if you dont need it
    rotaryEncoder.setAcceleration(250); //or set the value - larger number = more accelearation; 0 or 1 means disabled acceleration
}

void loop()
{
    rotary_loop();
    delay(50); 
}
