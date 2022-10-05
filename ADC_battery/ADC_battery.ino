const int ADCPIN = 34;
hw_timer_t *My_timer = NULL;

int adcValue;
float voltValue;

void IRAM_ATTR onTimer(){

  adcValue = analogRead(ADCPIN);
  voltValue = ((adcValue * 3.3) / 4095);
  Serial.print("ADC Value = ");
  Serial.print(adcValue);
  //delay(1000);
  Serial.print("  ");
  Serial.print("Voltage = ");
  Serial.print(voltValue);
  Serial.println(" V");
  //delay(1000);
}

void setup()
{  
  
  Serial.begin(115200);
  My_timer = timerBegin(0, 80, true);
  timerAttachInterrupt(My_timer, &onTimer, true);
  timerAlarmWrite(My_timer, 5000000, true);
  timerAlarmEnable(My_timer);

  
}
void loop()
{
  
}
