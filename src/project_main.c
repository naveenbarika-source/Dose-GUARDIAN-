#include <LPC21xx.h>        // LPC21xx MCU register definitions
#include "defines.h"        // General macro definitions
#include "lcd.h"            // LCD function prototypes
#include "lcd_defines.h"    // LCD command macros
#include "kpm.h"            // Keypad driver functions
#include "rtc.h"            // RTC initialization and read functions
#include "delay.h"          // Software delay functions
#include "edit.h"           // RTC and medicine time edit functions
#include "pindefines.h"     // Pin definitions for LED, buzzer, switches

// Medicine reminder time variables
s32 M_HOUR = 10, M_MIN, M_SEC;

// RTC time and calendar variables
s32 hour, min, sec, date, month, year, day;

int main()
{
    u8 choice;   // Variable to store keypad choice

    // Configure LED and BUZZER pins as OUTPUT
    IODIR0 |= 3 << LED;

    // Initialize Real Time Clock
    RTC_Init();

    // Initialize LCD display
    InitLCD();

    // Initialize keypad row pins
    KeyadInit();

    while(1)
    {
        /* Display current RTC time and calendar date on LCD */
        Diplay();

        /* Check whether SW1 switch is pressed (active LOW) */
        if((((IOPIN0 >> SW1) & 1) == 0))
        {
            /* Display menu for RTC and Medicine time settings */
            Disp_menu();

            // Clear keypad rows before reading key
            WRITENIBBLE(IOPIN1,16,0);

            // Wait until a key is pressed
            while(ColStat());

            // Read keypad key value
            choice = ReadKeyVal();

            switch(choice)
            {
                case '1':
                         CmdLCD(CLEAR_LCD);
                         // Edit Real Time Clock
                         edit_RTC();
                         break;

                case '2':
                         CmdLCD(CLEAR_LCD);
                         // Edit Medicine reminder time
                         edit_MED(&M_HOUR, &M_MIN, &M_SEC);
                         break;

                case '3':
                         CmdLCD(CLEAR_LCD);
                         // Exit menu and return to main display
                          break;

                default:
                         CmdLCD(CLEAR_LCD);
													/* Display error message for invalid key input */
													StrLCD("WRONG INPUT");
													delay_s(31);
													CmdLCD(CLEAR_LCD);
            }
        }

        /* Check if RTC time matches medicine reminder time */
        if((hour == M_HOUR) && (min == M_MIN)&&(sec ==M_SEC))
				{
						u32 i;
						u8 taken = 0;

					/* Display medicine reminder */
					Diplay_medicine_time();

					/* Turn ON buzzer */
					SETBIT(IOSET0, BUZZER);

				/* Wait for 30 seconds OR until SW2 is pressed */
				for(i = 0; i < 30; i++)
				{
						if(((IOPIN0 >> SW2) & 1) == 0)   // SW2 pressed (active LOW)
							{
									taken = 1;
										break;
							}
							delay_s(1);
				}

				/* Turn OFF buzzer after 30 sec or on confirmation */
					SETBIT(IOCLR0, BUZZER);

					if(taken)
					{
							/* Medicine taken */
						display_med_taken();
					}
				else
				{
						/* Medicine NOT taken */
						SETBIT(IOSET0, LED);          // Warning LED ON
						Disp_medicine_fail();         // Show fail message

						/* Wait until user presses SW2 */
						while(((IOPIN0 >> SW2) & 1) != 0);

						SETBIT(IOCLR0, LED);          // LED OFF
				}
					CmdLCD(CLEAR_LCD);
				}

    }
}
