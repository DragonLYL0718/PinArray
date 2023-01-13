char *buff = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    int begin = Serial.parseInt();
    // ;;
    while(Serial.available())
    {
      char inChar = (char)Serial.read();
      if(inChar == '\n')
      {
        Serial.println(buff);
        buff = "";
      }
      else buff += inChar;
    }
  }
  buff = "";
}
