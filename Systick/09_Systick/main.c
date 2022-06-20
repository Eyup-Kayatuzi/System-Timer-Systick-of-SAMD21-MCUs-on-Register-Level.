//////////////////////////////////////////////////////////////////////////
// Include and defines
//////////////////////////////////////////////////////////////////////////
#include "sam.h"
#include "definitions.h"
#include "app.h"

//////////////////////////////////////////////////////////////////////////
// Function Prototypes
//////////////////////////////////////////////////////////////////////////
void ClocksInit(void);	// Configure Clock, Wait States and synch, bus clocks for 48MHz operation

uint8_t counter = 0;

int main(void)
{
	// CMSIS compliant function not used
	//SystemInit();
	
	// Application hardware and software initialization 
	AppInit();
	PORT->Group[0].PINCFG[28].bit.PMUXEN = 1;
	PORT->Group[0].PMUX[14].bit.PMUXE = 0x7;
	NVIC_EnableIRQ(SysTick_IRQn); // global enable
	SysTick->LOAD = 16000000;
	SysTick->VAL   = 0UL;
	SysTick->CTRL = ( 0xfffffff8 & SysTick->CTRL) | 0x00000007;  
	// Super loop
	while(1)
	{
		
	}
} // main()

void SysTick_Handler(){
	
	counter += 1;
	if (counter == 3){
		
		PORT->Group[LED0_PORT].OUTTGL.reg = LED0_PIN_MASK; // pa17 is toggling
		counter = 0;
	}
	
	SysTick->VAL = 0;
}


