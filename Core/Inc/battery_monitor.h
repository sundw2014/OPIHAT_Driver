#ifndef _BATTERY_MONITOR_
#define _BATTERY_MONITOR_

#ifdef __cplusplus
extern "C" {
#endif

void start_battery_monitor(void);
float get_bat_status_voltage(void);
float get_bat_status_current(void);

#ifdef __cplusplus
}
#endif

#endif
