#include <M5Stack.h>
#include <M5GFX.h>
#include <Ps3Controller.h>
// address setting
// /lib/bt_settings/bt_settings.h
#include <bt_settings.h>

void onConnect();
void notify();

M5GFX display;

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.Power.begin(); //Init Power module.
  display.begin();
  display.fillScreen(TFT_BLACK);
  display.printf("m5roomba");

  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin(BT_ADDRESS); // change to your address
  Serial.println("PS3Controller isReady");
}

void loop() {
  // put your main code here, to run repeatedly:
  M5.update();
  display.fillScreen(TFT_BLACK);
  display.setColor(TFT_WHITE);
  display.drawCircle(display.width()/2.0, display.height()/2.0, 100);
  display.drawLine(0, display.height()/2.0, display.width(), display.height()/2.0);
  display.drawLine(display.width()/2.0, 0, display.width()/2.0, display.height());
  display.drawLine(
    display.width()/2.0, display.height()/2.0,
    display.width()/2.0 + Ps3.data.analog.stick.lx,
    display.height()/2.0 + Ps3.data.analog.stick.ly);

  // Serial.println(
  //   String(Ps3.data.analog.stick.lx) + "\t"
  //   + String(Ps3.data.analog.stick.ly) + "\t"
  //   + String(Ps3.data.analog.stick.rx) + "\t"
  //   + String(Ps3.data.analog.stick.ry)
  // );

  delay(50);
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
