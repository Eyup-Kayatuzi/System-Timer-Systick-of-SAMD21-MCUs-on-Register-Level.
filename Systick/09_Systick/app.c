//////////////////////////////////////////////////////////////////////////
// Include and defines
//////////////////////////////////////////////////////////////////////////
#include "app.h"
#include "clock.h"


//////////////////////////////////////////////////////////////////////////
// Global Variables
//////////////////////////////////////////////////////////////////////////


void AppInit(void)
{
	/*	Clock initialization (CPU, AHB, APBx, Asynchronous Peripheral Clocks)
		The System RC Oscillator (RCSYS) provides the source for the main clock
		at chip startup. It is set to 1MHz.
	*/
	ClocksInit();
	
	// Assign LED0 as OUTPUT
	REG_PORT_DIR0 = LED0_PIN_MASK;
	
	// Set LED0 OFF
	REG_PORT_OUTCLR0 = LED0_PIN_MASK;
	

} // AppInit()

void AppRun(void)
{
	// Set the LED drive strength to strong
	PORT->Group[LED0_PORT].PINCFG[LED0_PIN_NUMBER].bit.DRVSTR = 1;
	
	// Configure SysTick to trigger every millisecond using the CPU Clock
	SysTick->CTRL = 0;					 // Disable SysTick
	SysTick->LOAD = 47999UL;		     // Set reload register for 1mS interrupts (48 MHz clk)
	NVIC_SetPriority(SysTick_IRQn, 3);	 // Set interrupt priority to least urgency
	SysTick->VAL = 0;					 // Reset the SysTick counter value
	
	 // Enable SysTick, Enable SysTick Exceptions, Use CPU Clock
	 SysTick->CTRL  = 
	    SysTick_CTRL_CLKSOURCE_Msk |
	    SysTick_CTRL_TICKINT_Msk   |
	    SysTick_CTRL_ENABLE_Msk;
	
	// Enable SysTick Interrupt     			
	NVIC_EnableIRQ(SysTick_IRQn);		
	
	while(1)
	{
		
	}

} // Apprun()

