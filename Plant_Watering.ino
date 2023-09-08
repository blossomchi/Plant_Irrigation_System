#define SENSOR_READ_DELAY 10000   //This is the loop delay for sensor reading. Its in milli seconds. set it to 86400000 for once a day.
#define FULL_MOISTURE_READING 290
#define NO_MOISTURE_READING 595
#define CUT_OFF_MOISTURE_PERCENATGE 50
#define PUMP1_WATERING_TIME 4000  //This is millis


int pumpPin1=9;

int inputSensorPin1=A0;


void setup() 
{
  // put your setup code here, to run once:
  pinMode(pumpPin1,OUTPUT);

  digitalWrite(pumpPin1,HIGH);
  
}

void getMoisturePercentageAndWaterIt(int sensorValue, int outPinNo, int wateringTime)
{
  sensorValue = constrain(sensorValue ,FULL_MOISTURE_READING, NO_MOISTURE_READING); 
  int moisturePercentage = map(sensorValue, FULL_MOISTURE_READING, NO_MOISTURE_READING, 100, 0);
  
  if (moisturePercentage < CUT_OFF_MOISTURE_PERCENATGE)
  {
    digitalWrite(outPinNo, LOW);
    delay(wateringTime);
    digitalWrite(outPinNo, HIGH);
  }
}


void loop() 
{
  // put your main code here, to run repeatedly:
  int inputSensorPin1Value = analogRead(inputSensorPin1);
  getMoisturePercentageAndWaterIt(inputSensorPin1Value, pumpPin1, PUMP1_WATERING_TIME);

  delay(SENSOR_READ_DELAY);
}
