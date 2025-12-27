#include "types.h"     // User-defined data types (u8, s8, s32, f32, u32)

/*---------------- LCD Initialization ----------------*/
// Initializes LCD in required mode (4-bit / 8-bit)
void InitLCD(void);

/*---------------- LCD Command Function ----------------*/
// Sends command to LCD (clear, cursor, shift, etc.)
void CmdLCD(u8);

/*---------------- LCD Character Display ----------------*/
// Displays a single character on LCD
void CharLCD(s8);

/*---------------- LCD String Display ----------------*/
// Displays a string on LCD
void StrLCD(s8 *);

/*---------------- LCD Integer Display ----------------*/
// Displays signed integer value on LCD
void IntLCD(s32);

/*---------------- LCD Float Display ----------------*/
// Displays floating-point number on LCD
// u32 parameter specifies number of decimal places
void F32LCD(f32, u32);

/*---------------- Application Display Functions ----------------*/
// Displays medicine reminder time on LCD
void Diplay_medicine_time(void);

// Displays main application screen
void Diplay(void);

// Displays message when medicine is missed
void Disp_medicine_fail(void);

// Displays menu options on LCD
void Disp_menu(void);

//displays message when switch is pressed  within 30 seconds 
void display_med_taken(void);
