#ifndef _ST1KL3A_HPP_
#define _ST1KL3A_HPP_

#include "pxstr.hpp"

namespace sensor::pxstr{

	class ST1KL3A : public Product{
	private:
		std::unique_ptr<parameter::Wall> pxstr_;
		std::unique_ptr<peripheral::ADC> adc_;
	public:
		ST1KL3A(ADC_HandleTypeDef* hadc);
		void Init() override ;
		void ReadVal() override ;
		parameter::Wall* get_val_ptr() override;
		virtual ~ST1KL3A() = default;
	};
}





#endif /* INC_ST1KL3A_H_ */
