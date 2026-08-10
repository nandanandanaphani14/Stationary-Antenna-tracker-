const byte PWMPin = 2;
const byte GreenLEDPin = 3;
const byte AmberLEDPin = 4;
const byte RedLEDPin = 5;

void setup()
{
  pinMode(PWMPin, INPUT);

  pinMode(GreenLEDPin, OUTPUT);
  pinMode(AmberLEDPin, OUTPUT);
  pinMode(RedLEDPin, OUTPUT);
}

void loop()
{
  byte PWM = GetPWM(PWMPin);
  digitalWrite(GreenLEDPin, PWM < 85);
  digitalWrite(AmberLEDPin, PWM >= 85 && PWM <= 90);
  digitalWrite(RedLEDPin, PWM > 90);
}

byte GetPWM(byte pin)
{
  unsigned long highTime = pulseIn(pin, HIGH, 50000UL);  // 50 millisecond timeout
  unsigned long lowTime = pulseIn(pin, LOW, 50000UL);  // 50 millisecond timeout

  // pulseIn() returns zero on timeout
  if (highTime == 0 || lowTime == 0)
    return digitalRead(pin) ? 100 : 0;  // HIGH == 100%,  LOW = 0%

  return (100 * highTime) / (highTime + lowTime);  // highTime as percentage of total cycle time
}
