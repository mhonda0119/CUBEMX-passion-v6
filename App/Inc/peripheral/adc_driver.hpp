#ifndef _ADCDRIVER_HPP_
#define _ADCDRIVER_HPP_

#include <iostream>
#include "peripheral.h"
#include "stdout.h"
#include "stdint.h"

namespace adc{
	class Driver {
	private:
		uint16_t buff_[10] ={0};
		uint32_t channels_ = 5;
	public:
		Driver() = default;
		void ReadVal(ADC_HandleTypeDef *hadc);
		uint16_t * get_val_ptr();
		~Driver() = default;
	};
}

#endif /* _ADCDRIVER_HPP_ */