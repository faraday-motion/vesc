#include "Arduino.h"
#include "lib/bldc_uart_comm_stm32f4_discovery/packet.h"
#include "lib/bldc_uart_comm_stm32f4_discovery/packet.c"
#include "lib/bldc_uart_comm_stm32f4_discovery/buffer.h"
#include "lib/bldc_uart_comm_stm32f4_discovery/buffer.c"
#include "lib/bldc_uart_comm_stm32f4_discovery/crc.h"
#include "lib/bldc_uart_comm_stm32f4_discovery/crc.c"
#include "lib/bldc_uart_comm_stm32f4_discovery/bldc_interface.h"
#include "lib/bldc_uart_comm_stm32f4_discovery/bldc_interface.c"
#include "lib/bldc_uart_comm_stm32f4_discovery/bldc_interface_uart.h"
#include "lib/bldc_uart_comm_stm32f4_discovery/bldc_interface_uart.c"
#include "lib/bldc_uart_comm_stm32f4_discovery/datatypes.h"


#include "FaradayVESC.h"

FaradayVESC::FaradayVESC()
{
}

// Settings
#define PACKET_HANDLER			0

/**
 * Initialize the UART interface communication. 
 * 
 */
void FaradayVESC::init(void(*s_func)(unsigned char *data, unsigned int len), void(*p_func)(unsigned char b), void(*v_func)(mc_values *val))
{
	bldc_interface_uart_init(s_func);

	bldc_interface_set_rx_value_func(v_func);
}

void FaradayVESC::process(unsigned char b)
{
	bldc_interface_uart_process_byte(b);
}

void FaradayVESC::update()
{
	bldc_interface_uart_run_timer();
}


void FaradayVESC::set_current(float current) {
	bldc_interface_set_current(current);
}


void FaradayVESC::set_current_brake(float current) {
	bldc_interface_set_current_brake(current);
}

void FaradayVESC::get_values()  {
	bldc_interface_get_values();
}

