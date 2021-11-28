#include <Arduino.h>
#include <Ps3Controller.h>
// address setting
// /lib/bt_settings/bt_settings.h
#include <bt_settings.h>

void onConnect();
void notify();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin(BT_ADDRESS); // change to your address
  Serial.println("PS3Controller isReady");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(
    String(Ps3.data.analog.stick.lx) + "\t"
    + String(Ps3.data.analog.stick.ly) + "\t"
    + String(Ps3.data.analog.stick.rx) + "\t"
    + String(Ps3.data.analog.stick.ry)
  );
}

void onConnect(){
  Serial.println("Connected.");
}

void notify(){
  if( Ps3.data.button.cross ){
    // Serial.println("RDown");
  }
  if( Ps3.data.button.square ){
    // Serial.println("RLeft");
  }
  if( Ps3.data.button.triangle ){
    // Serial.println("RUp");
  }
  if( Ps3.data.button.circle ){
    // Serial.println("RRight");
  }
}
