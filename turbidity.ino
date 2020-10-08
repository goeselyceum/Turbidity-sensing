/*
  Turbiditeit

  Een troebeleidssensor van een wasmachine kan gebruikt worden voor troebelheid.
  https://wiki.dfrobot.com/Turbidity_sensor_SKU__SEN0189

*/
float ntu;
float voltage;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ntu = readNtu();
  Serial.print("ntu:");
  Serial.println(ntu);
  Serial.print("Volt:");
  Serial.print(voltage);
  Serial.println();
  delay(500);
}

float readNtu ()  {
  float sensorVal;
  int sensorValue = analogRead(A0);                                    // read analog pin A0
  voltage = sensorValue * (5.0 / 1023.0);                              // calculate voltage
  sensorVal = (-1120.4 * pow(voltage, 2)) + 5742.3 * voltage - 4352.9; // from datasheet
  return sensorVal;
}
