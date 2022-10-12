#include "stm32f7xx.h"
#include "timer.h"

void init_TIMER8(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;



	TIM8->PSC=0;
	TIM8->ARR = 216000000/100000/2 -1;//init_GPIO_Output(GPIOD, 1);
	TIM8->CCR1 = TIM8->ARR/2; //регистр сравнения CCR1  число с которым сравниваетс счетчик

	TIM8->CR1|= TIM_CR1_CMS_1;			// режим симетричного счета до ARR

	TIM8->CCER|= TIM_CCER_CC1E;//включить канал сравнения, полярность если надо
	TIM8->CCMR1|= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; //выставить 0110
	TIM8->BDTR|= TIM_BDTR_MOE;//
	TIM8->CR1|= TIM_CR1_CEN;

}
//#include "timer.h"
//#include "stm32f7xx.h"

//void init_TIMER8(void){
//	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
//
//	TIM8->PSC = 0;
//	TIM8->ARR = 216000000 / 100000 / 2 - 1;
//
//	TIM8->CCR1 = TIM8->ARR / 2;
//	TIM8->CR1 |= TIM_CR1_CMS_1;
//
//	TIM8->CCER |= TIM_CCER_CC1E;
//	TIM8->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
//	TIM8->BDTR |= TIM_BDTR_MOE;
//	TIM8->CR1 |= TIM_CR1_CEN;
//
//}
