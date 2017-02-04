#ifndef FaradayVESC_h
#define FaradayVESC_h

#include "lib/bldc_uart_comm_stm32f4_discovery/packet.h"
#include "lib/bldc_uart_comm_stm32f4_discovery/buffer.h"
#include "lib/bldc_uart_comm_stm32f4_discovery/crc.h"
#include "lib/bldc_uart_comm_stm32f4_discovery/datatypes.h"


class FaradayVESC{
public:
	FaradayVESC();
	void init(void(*s_func)(unsigned char *data, unsigned int len), void(*p_func)(unsigned char b), void(*v_func)(mc_values *val));
	void process(unsigned char b);
	void update();
	void set_current(float current);
	void set_current_brake(float current);
	void get_values();
};

#endif
