#define redLed 7
#define greenLed 8
#define blueLed 9
#define pushButton 2
unsigned long previousMillis = 0;
const long second = 1000;
int counter = 0;
void setup()
{
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(blueLed, OUTPUT);
    pinMode(pushButton, INPUT);
}
void loop()
{
    ifButtonPressed();
    if (isEven(counter))
        turnOffLeds();
    else
        runningLeds();
}

bool isEven(int count)
{
    if (count % 2 == 0)
        return true;
    return false;
}

void ifButtonPressed()
{
    if (digitalRead(pushButton))
    {
        while (digitalRead(pushButton))
            ;
        counter++;
        previousMillis = millis();
    }
}

void runningLeds()
{
    if (millis() - previousMillis <= 3 * second)
    {
        if (millis() - previousMillis <= second)
            turnOnRedLed();
        else if (millis() - previousMillis <= 2 * second)
            turnOnGreenLed();
        else if (millis() - previousMillis <= 3 * second)
            turnOnBlueLed();
    }
    else
        previousMillis = millis();
}
void turnOnRedLed()
{
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, LOW);
}

void turnOnGreenLed()
{
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(blueLed, LOW);
}
void turnOnBlueLed()
{
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, HIGH);
}
void turnOffLeds()
{
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, LOW);
}