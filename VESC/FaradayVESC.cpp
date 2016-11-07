#include "Arduino.h"
#include "packet.h"
#include "packet.c"
#include "buffer.h"
#include "buffer.c"
#include "crc.h"
#include "crc.c"
#include "bldc_interface.h"
#include "bldc_interface.c"
#include "bldc_interface_uart.h"
#include "bldc_interface_uart.c"
#include "FaradayVESC.h"

FaradayVESC::FaradayVESC()
{
}

// Settings
#define PACKET_HANDLER			0

void FaradayVESC::init(void(*s_func)(unsigned char *data, unsigned int len), void(*p_func)(unsigned char *data, unsigned int len))
{
	bldc_interface_uart_init(s_func);
}

void FaradayVESC::update()
{
	bldc_interface_uart_run_timer();
}


void FaradayVESC::set_current(float current) {
	bldc_interface_set_current_dual(current);
	//bldc_interface_set_forward_can(-1);
	//bldc_interface_set_current(current);
	//bldc_interface_set_forward_can(1);
	//bldc_interface_set_current(current);
}


void FaradayVESC::set_current_brake(float current) {
	bldc_interface_set_current_brake_dual(current);
	///bldc_interface_set_forward_can(-1);
	//bldc_interface_set_current_brake(current);
	//bldc_interface_set_forward_can(1);
	//bldc_interface_set_current_brake(current);
}


