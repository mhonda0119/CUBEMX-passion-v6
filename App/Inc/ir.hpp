#ifndef _IR_HPP_
#define _IR_HPP_

#include "peripheral.h"
#include "wall_parameter.hpp"
#include "led.hpp"
#include <memory>

namespace ir{
    class Driver{
    private:
    DIR dir_;
    std::unique_ptr<gpio::LED> r_;
    std::unique_ptr<gpio::LED> l_;
    std::unique_ptr<gpio::LED> fr_;
    std::unique_ptr<gpio::LED> fl_;
    public:
        Driver();//led���C���X�^���X������4��
        void On(DIR dir = DIR::ALL);//�����������Ȃ�������S�����点�Ďw�肵����w��
        void Off(DIR dir = DIR::ALL);//�����������Ȃ�������S�����点�Ďw�肵����w��
        ~Driver() = default;
    };
}

#endif //_IR_HPP_