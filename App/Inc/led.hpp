#ifndef _LED_HPP_
#define _LED_HPP_

#include "peripheral.h"

namespace gpio{
    class LED{
    private:
        GPIO_TypeDef* port_;  // GPIO�|�[�g
        uint16_t pin_;    // GPIO�s���ԍ�
    public:
        LED(GPIO_TypeDef*,uint16_t);
        void On();
        void Off();
        void Toggle();
        ~LED() = default;
    };
}

#endif //_LED_HPP_