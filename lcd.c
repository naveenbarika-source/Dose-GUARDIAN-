 #include <LPC21xx.h>        // LPC21xx microcontroller register definitions
#include "delay.h"          // Software delay functions
#include "types.h"          // User-defined data types
#include "defines.h"        // General macros
#include "lcd.h"            // LCD function prototypes
#include "lcd_defines.h"    // LCD command definitions
#include "pindefines.h"     // Pin definitions for LCD control
#include "rtc.h"            // RTC read/display functions

// RTC variables declared in main program
extern s32 hour, min, sec, date, month, year, day;

/*--------------------------------------------------
  Function : InitLCD
  Purpose  : Initialize LCD in 8-bit, 2-line mode
--------------------------------------------------*/
void InitLCD(void)
{
    /* Configure LCD data pins and control pins as OUTPUT */
    IODIR0 |= (0xff << LCD_data) | (1 << RS) | (1 << RW) | (1 << EN);

    /* LCD power-on initialization sequence */
    delay_ms(20);
    CmdLCD(MODE_8BIT_1LINE);
    delay_ms(8);
    CmdLCD(MODE_8BIT_1LINE);
    delay_ms(1);
    CmdLCD(MODE_8BIT_1LINE);
    delay_ms(1);

    /* Set LCD to 8-bit, 2-line display mode */
    CmdLCD(MODE_8BIT_2LINE);

    /* LCD configuration commands */
    CmdLCD(DSP_OFF);          // Display OFF
    CmdLCD(CLEAR_LCD);        // Clear display
    CmdLCD(SHIFT_CUR_RIGHT);  // Cursor move direction
    CmdLCD(DSP_ON_CUR_OFF);   // Display ON, cursor OFF
}

/*--------------------------------------------------
  Function : DispLCD
  Purpose  : Send one byte (data/command) to LCD
--------------------------------------------------*/
void DispLCD(u8 val)
{
    /* RW = 0 ? Write operation */
    IOCLR0 = 1 << RW;

    /* Write 8-bit value to LCD data pins */
    WRITEBYTE(IOPIN0, LCD_data, val);

    /* Generate enable pulse to latch data */
    IOSET0 = 1 << EN;
    delay_ms(2);
    IOCLR0 = 1 << EN;
    delay_us(2);
}

/*--------------------------------------------------
  Function : CmdLCD
  Purpose  : Send command to LCD
--------------------------------------------------*/
void CmdLCD(u8 cmd)
{
    /* RS = 0 ? Command mode */
    IOCLR0 = 1 << RS;
    DispLCD(cmd);
    delay_ms(2);
}

/*--------------------------------------------------
  Function : CharLCD
  Purpose  : Display single character on LCD
--------------------------------------------------*/
void CharLCD(s8 data)
{
    /* RS = 1 ? Data mode */
    IOSET0 = 1 << RS;
    DispLCD(data);
    delay_ms(2);
}

/*--------------------------------------------------
  Function : StrLCD
  Purpose  : Display string on LCD
--------------------------------------------------*/
void StrLCD(s8 *ptr)
{
    /* Display characters until NULL character */
    while(*ptr != '\0')
    {
        CharLCD(*ptr);
        ptr++;
    }
}

/*--------------------------------------------------
  Function : IntLCD
  Purpose  : Display integer number on LCD
--------------------------------------------------*/
void IntLCD(s32 num)
{
    s8 a[10], i = 0;

    /* Handle zero case */
    if(num == 0)
    {
        CharLCD('0');
    }
    else
    {
        /* Handle negative numbers */
        if(num < 0)
        {
            CharLCD('-');
            num = -num;
        }

        /* Convert integer to characters */
        while(num)
        {
            a[i++] = (num % 10) + '0';
            num = num / 10;
        }

        /* Display digits in correct order */
        --i;
        for(; i >= 0; i--)
        {
            CharLCD(a[i]);
        }
    }
}

/*--------------------------------------------------
  Function : FloatLCD
  Purpose  : Display floating-point number on LCD
--------------------------------------------------*/
void FloatLCD(f32 fN, u32 nDP)
{
    u32 n;
    s32 i;

    /* Handle negative floating value */
    if(fN < 0.0)
    {
        CharLCD('-');
        fN = -fN;
    }

    /* Display integer part */
    n = fN;
    IntLCD(n);
    CharLCD('.');

    /* Display fractional part up to nDP decimals */
    for(i = 0; i < nDP; i++)
    {
        fN = (fN - n) * 10;
        n = fN;
        CharLCD(n + '0');
    }
}

/*--------------------------------------------------
  Function : Diplay_medicine_time
  Purpose  : Display medicine reminder alert
--------------------------------------------------*/
void Diplay_medicine_time()
{
    CmdLCD(CLEAR_LCD);
    CmdLCD(GOTO_LINE1_POS0);
    StrLCD("TAKE MEDCINE");
}

/*--------------------------------------------------
  Function : Diplay
  Purpose  : Display RTC time, date and day on LCD
--------------------------------------------------*/
void Diplay()
{
    /* Get and display current time */
    GetRTCTimeInfo(&hour, &min, &sec);
    DisplayRTCTime(hour, min, sec);

    /* Get and display current date */
    GetRTCDateInfo(&date, &month, &year);
    DisplayRTCDate(date, month, year);

    /* Get and display current day */
    GetRTCDay(&day);
    DisplayRTCDay(day);
}

/*--------------------------------------------------
  Function : Disp_medicine_fail
  Purpose  : Display medicine missed warning
--------------------------------------------------*/
void Disp_medicine_fail()
{
    CmdLCD(CLEAR_LCD);
    CmdLCD(GOTO_LINE1_POS0);
    StrLCD("FAILED TO TAKE");
    CmdLCD(GOTO_LINE2_POS0);
    StrLCD("MEDICINE");
}

/*--------------------------------------------------
  Function : Disp_menu
  Purpose  : Display menu options on LCD
--------------------------------------------------*/
void Disp_menu()
{
    CmdLCD(CLEAR_LCD);
    CmdLCD(GOTO_LINE1_POS0);
    StrLCD("MENU: 1:RTC ");
    CmdLCD(GOTO_LINE2_POS0);
    StrLCD("2:MED 3:EXIT");

    /* Small delay to allow user to read menu */
    delay_s(1);
}
void display_med_taken()
{
	             CmdLCD(CLEAR_LCD);
							CmdLCD(GOTO_LINE1_POS0);
							StrLCD("MEDICINE TAKEN");
							delay_s(2);
}
