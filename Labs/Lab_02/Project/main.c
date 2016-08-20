//---------------------------------------------------------------------------
// Project: Blink TM4C - CCS Lab - STARTER
//
// Author: Eric Wilbur, www.MindshareAdvantage.com
//
// Date: Nov 2015
//
//---------------------------------------------------------------------------


//------------------------------------------
// TivaWare Header Files
//------------------------------------------
#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include <time.h>


//----------------------------------------
// Prototypes
//----------------------------------------
void hardware_init(void);
void ledToggle(void);
void delay(void);


//---------------------------------------
// Globals
//---------------------------------------
volatile int16_t i16ToggleCount = 0;
uint8_t ui8PinData=1;

//---------------------------------------------------------------------------
// main()
//---------------------------------------------------------------------------
void main(void)
{

   hardware_init();							// init hardware via Xware

   while(1)									// forever loop
   {
	   ledToggle();							// toggle LED

	   delay();								// create a delay of ~1/2sec

	   i16ToggleCount += 1;					// keep track of #toggles
   }
}
//---------------------------------------------------------------------------
// hardware_init()
//
// inits GPIO pins for toggling the LED
//---------------------------------------------------------------------------
void hardware_init(void)
{
	SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
	GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0|GPIO_PIN_1);
	GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0|GPIO_PIN_1, 0x00);

}


//---------------------------------------------------------------------------
// ledToggle()
//
// toggles LED on Tiva-C LaunchPad
//---------------------------------------------------------------------------
void ledToggle(void)
{
	GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1, ui8PinData);
	SysCtlDelay(2000000);
	if(ui8PinData==4) {ui8PinData=1;} else {ui8PinData=ui8PinData*2;}
}

//---------------------------------------------------------------------------
// delay()
//
// Creates a 500ms delay via TivaWare fxn
//---------------------------------------------------------------------------
void delay(void)
{
	 SysCtlDelay(6700000);		// creates ~500ms delay - TivaWare fxn

}




