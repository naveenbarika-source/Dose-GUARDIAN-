#include "types.h"     // User-defined data types (u32)

/*--------------------------------------------------
  Function : delay_us
  Purpose  : Generate delay in microseconds
  Note     : Multiplier depends on CPU clock frequency
--------------------------------------------------*/
void delay_us(u32 tdly)
{
    /* 
       Assuming 12 MHz CPU clock
       1 instruction cycle ˜ 1 µs / 12
       So multiply by 12 to get 1 µs delay
    */
    tdly *= 12;

    // Empty loop used to waste CPU cycles
    while(tdly--);
}

/*--------------------------------------------------
  Function : delay_ms
  Purpose  : Generate delay in milliseconds
--------------------------------------------------*/
void delay_ms(u32 tdly)
{
    /*
       1 millisecond = 1000 microseconds
       1000 × 12 = 12000 cycles for 12 MHz clock
    */
    tdly *= 12000;

    // Busy-wait delay loop
    while(tdly--);
}

/*--------------------------------------------------
  Function : delay_s
  Purpose  : Generate delay in seconds
--------------------------------------------------*/
void delay_s(u32 tdly)
{
    /*
       1 second = 1,000,000 microseconds
       1,000,000 × 12 = 12,000,000 cycles
    */
    tdly *= 12000000;

    // Software delay using empty loop
    while(tdly--);
}

