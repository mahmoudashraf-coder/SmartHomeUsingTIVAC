#ifndef __ARMCORTEX_GPIO__
#define __ARMCORTEX_GPIO__
#include <stdint.h>

enum mode 
{INPUT=0 ,OUTPUT=1, NONE = -1};
enum input_mode{ANALOG=0,DIGITAL=1, DEN_R_NONE = -1};
enum set_mode {UNSET = 0, SET = 1, AFSEL_R_NONE = -1};
void port_lock(char port);
void port_init (char port);
void pin_mode (char port,uint8_t pin ,enum mode dirr,enum input_mode denr, enum set_mode afsel_mode);
volatile unsigned long * getGPIOData(char port);
void write_pin(char port ,uint8_t pin,uint8_t state);
void write_data(char port, uint8_t data);
uint8_t read_data(char port);
uint8_t read_pin(char port,uint8_t pin);
#endif
