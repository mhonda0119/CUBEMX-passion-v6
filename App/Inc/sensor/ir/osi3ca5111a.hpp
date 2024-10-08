#ifndef _IR_HPP_
#define _IR_HPP_

#include "peripheral.h"
#include "wall.hpp"
#include "gpio.hpp"
#include "main.h"
#include <memory>
#include <iostream>

namespace sensor::ir{
    class OSI3CA5111A{
    private:
    parameter::DIR dir_;
    std::unique_ptr<peripheral::GPIO> r_;
    std::unique_ptr<peripheral::GPIO> l_;
    std::unique_ptr<peripheral::GPIO> fr_;
    std::unique_ptr<peripheral::GPIO> fl_;
    public:
        OSI3CA5111A();
        void On(parameter::DIR dir = parameter::DIR::ALL);
        void Off(parameter::DIR dir = parameter::DIR::ALL);
        ~OSI3CA5111A() = default;
    };
}

#endif //_IR_HPP_