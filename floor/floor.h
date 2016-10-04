#ifndef FLOOR_H
#define FLOOR_H

#include <stdbool.h>
#include <stdint.h>

#include "nrf51.h"
#include "nrf_gpio.h"
#include "nrf_gpiote.h"

/*
 * ------------------------------------------------
 *  Configuration
 * ------------------------------------------------
 */
#define FLOOR_USES_TIMER2
#define PULSE_COUNTER      NRF_TIMER1
#define TIMER_MEASUREMENT  NRF_TIMER2

// the index of the last sensor
#define last_sensor 5

// timer overflow values as multiples of clock ticks (depends on fTIMER i.e. PRESCALER value)
#define measurement_duration 1000
#define measurement_interval 2000

// pins to which sensors are attached
#define sensor_pin {0,1,2,7,6,5}

// ------------------------------------------------

// a typedef for the handler functions,
// which can be attached
typedef void (*handler_t)();

void select_first_sensor();
void select_next_sensor();
bool is_last_sensor();

void generate_json();

void configure_pulse_counter();
void restart_pulse_counter();
void stop_pulse_counter();
uint32_t get_pulse_count();

void configure_measurement_timer();
void measurement_timer_enable();
void measurement_timer_disable();

void set_handler_measurement_complete(handler_t*);
void set_handler_measurement_interval(handler_t*);

#endif // FLOOR_H