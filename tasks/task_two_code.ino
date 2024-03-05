#define redLed 10
#define greenLed 9
#define blueLed 8
#define colorRedLed 13
#define colorGreenLed 12
#define colorBlueLed 11
bool isFirstTime = true;
void setup()
{
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(blueLed, OUTPUT);
    pinMode(colorRedLed, OUTPUT);
    pinMode(colorGreenLed, OUTPUT);
    pinMode(colorBlueLed, OUTPUT);
}
void loop()
{
    openRed();
    delay(1000);
    openGreen();
    delay(1000);
    openBlue();
    delay(1000);
}
void openRed()
{
    digitalWrite(blueLed, LOW);
    digitalWrite(colorGreenLed, LOW);
    digitalWrite(redLed, HIGH);
    if (isFirstTime)
    {
        isFirstTime = false;
        return;
    }
    digitalWrite(colorRedLed, HIGH);
}
void openGreen()
{
    digitalWrite(colorBlueLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(colorGreenLed, HIGH);
    digitalWrite(colorRedLed, HIGH);
}
void openBlue()
{
    digitalWrite(colorRedLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, HIGH);
    digitalWrite(colorBlueLed, HIGH);
}