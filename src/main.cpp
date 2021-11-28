#include <Arduino.h>
#include <Ps3Controller.h>
// address setting
// /lib/bt_settings/bt_settings.h
#include <bt_settings.h>

void setup() {
  // put your setup code here, to run once:
  Ps3.begin(BT_ADDRESS); // change to your address
  
}

void loop() {
  // put your main code here, to run repeatedly:
}