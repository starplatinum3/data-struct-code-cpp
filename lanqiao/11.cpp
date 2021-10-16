void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
FlasgMode_t ideMode=ESP.getFlashChipMode();
String coreVersion=ESP.getCoreVersion();
Serial.print(F("Ardui  :"));
Serial.println(coreVersion);
Serial.printf("Flasg rel  Id : %08X \n",ESP.getFlashChipId());
delay(1000);
}