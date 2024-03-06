#include <stdint.h>
#include "STM32F103.h"
#include "SysTick_Interface.h"
#include "SysTick_Private.h"

void SysTick_Delay_ms(uint32_t Copy_u32Time_ms)
{
	/*Store Reload Value*/
	SysTick->SYST_RVR = (Copy_u32Time_ms * 1000);
	/*Select SysTick Source*/
	SysTick->SYST_CSR &= ~(1 << SYST_CSR_CLKSOURCE);
	/*Enable SysTick*/
	SysTick->SYST_CSR |= (1 << SYST_CSR_ENABLE);
	/*Wait Until Count Flag Set*/
	while (((SysTick->SYST_CSR) & (1 << SYST_CSR_COUNTFLAG)) == 0)	;
	/*disable SysTick*/
	SysTick->SYST_CSR &= ~(1 << SYST_CSR_ENABLE);
}
void SysTick_Delay_us(uint32_t Copy_u32Time_us)
{
	/*Store Reload Value*/
	SysTick->SYST_RVR = (Copy_u32Time_us);
	/*Select SysTick Source*/
	SysTick->SYST_CSR &= ~(1 << SYST_CSR_CLKSOURCE);
	/*Enable SysTick*/
	SysTick->SYST_CSR |= (1 << SYST_CSR_ENABLE);
	/*Wait Until Count Flag Set*/
	while (((SysTick->SYST_CSR) & (1 << SYST_CSR_COUNTFLAG)) == 0)	;
	/*disable SysTick*/
	SysTick->SYST_CSR &= ~(1 << SYST_CSR_ENABLE);
}