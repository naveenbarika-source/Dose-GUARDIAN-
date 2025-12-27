
#include "kpm_defines.h"   // Keypad pin definitions (R0–R3, C0–C3) and LUT
#include "types.h"
#include <LPC21xx.h>      // LPC21xx MCU register definitions
#include "kpm.h"          
#include "types.h"        // User-defined data types (s8 etc.)

/*--------------------------------------------------
  Function : KeyadInit
  Purpose  : Configure keypad ROW pins as OUTPUT
--------------------------------------------------*/
void KeyadInit(void)
{
    // Set keypad row pins (R0–R3) as output pins
    IODIR1 |= (1<<R0)|(1<<R1)|(1<<R2)|(1<<R3);
}

/*--------------------------------------------------
  Function : ColStat
  Purpose  : Check whether any key is pressed
  Return   : 1 ? No key pressed
             0 ? Key pressed
--------------------------------------------------*/
int ColStat(void)
{
    // Read column pins; if all columns are HIGH (0xF),
    // it means no key is pressed
    if(((IOPIN1>>C0) & 0xF) == 0x0F)
    {
        return 1;
    }
    return 0;
}

/*--------------------------------------------------
  Function : ReadKeyVal
  Purpose  : Detect row & column of pressed key
             and return corresponding key value
--------------------------------------------------*/
char ReadKeyVal(void)
{
    s8 rowval, colval;   // Variables to store detected row and column

    /* -------- Scan ROW 0 -------- */
    IOCLR1 = 1<<R0;                      // Make ROW 0 LOW
    IOSET1 = (1<<R1)|(1<<R2)|(1<<R3);    // Keep other rows HIGH
    if(((IOPIN1>>C0) & 0xF) != 0xF)       // Check if any column goes LOW
    {
        rowval = 0;                      // Row 0 is active
        goto colcheak;
    }

    /* -------- Scan ROW 1 -------- */
    IOCLR1 = 1<<R1;                      // Make ROW 1 LOW
    IOSET1 = (1<<R0)|(1<<R2)|(1<<R3);
    if(((IOPIN1 >> C0) & 0xF) != 0xF)
    {
        rowval = 1;
        goto colcheak;
    }

    /* -------- Scan ROW 2 -------- */
    IOCLR1 = 1<<R2;                      // Make ROW 2 LOW
    IOSET1 = (1<<R0)|(1<<R1)|(1<<R3);
    if(((IOPIN1 >> C0) & 0xF) != 0xF)
    {
        rowval = 2;
        goto colcheak;
    }

    /* -------- Scan ROW 3 -------- */
    IOCLR1 = 1<<R3;                      // Make ROW 3 LOW
    IOSET1 = (1<<R0)|(1<<R1)|(1<<R2);
    if(((IOPIN1 >> C0) & 0xF) != 0xF)
    {
        rowval = 3;
        goto colcheak;
    }

colcheak:
    /* -------- Identify COLUMN -------- */
    // The column which becomes LOW indicates the pressed key
    if(((IOPIN1 >> C0) & 1) == 0)
    {
        colval = 0;
    }
    else if(((IOPIN1 >> C1) & 1) == 0)
    {
        colval = 1;
    }
    else if(((IOPIN1 >> C2) & 1) == 0)
    {
        colval = 2;
    }
    else
    {
        colval = 3;
    }

    /* -------- Key release wait (debouncing) -------- */
    // Wait until key is released before returning value
    while(((IOPIN1 >> C0) & 0xF) != 0xF);

    /* -------- Return key value from LUT -------- */
    // LUT maps row & column to actual keypad character
    return LUT[rowval][colval];
}
