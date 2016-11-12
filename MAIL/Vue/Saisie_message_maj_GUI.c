#include "Saisie_message_maj_GUI.h"
#define DEBUG_ON

void test_dessin_saisie_message_maj(){
	LCD_BMP((uint16_t *)Saisie_message_maj_GUI);
#ifdef DEBUG_ON
	display_char_pressed(2);
	allumerled();
#endif
	delay(100);
}

void dessin_saisie_message_maj(){
	LCD_BMP((uint16_t *)Saisie_message_maj_GUI);
	char string_Q[] = "Q";
	char string_U[] = "U";
	char string_I[] = "I";
	char string_T[] = "T";
	char string_TT[] = "T";
	char string_E[] = "E";
	char string_R[] = "R";
	LCD_SetFont(&Font12x12);
	LCD_DisplayStringLine(LINE(4), COLUMN(1)+4, (uint8_t *)string_Q, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(6), COLUMN(1)+4, (uint8_t *)string_U, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(8), COLUMN(1)+6, (uint8_t *)string_I, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(10), COLUMN(1)+4, (uint8_t *)string_T, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(12), COLUMN(1)+4, (uint8_t *)string_TT, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(14), COLUMN(1)+4, (uint8_t *)string_E, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(16), COLUMN(1)+4, (uint8_t *)string_R, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	delay(100);
}
