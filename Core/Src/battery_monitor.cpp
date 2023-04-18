#include "battery_monitor.h"
#include "ina219.h"

INA219 ina1(0x45);

void start_battery_monitor(){
  ina1.begin();
}

float get_bat_status_voltage(){
  return ina1.getBusVoltage_V();
}

float get_bat_status_current(){
  return ina1.getCurrent_mA() / 1000;
}
