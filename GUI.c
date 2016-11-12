#include "GUI.h"

void LCD_BMP(uint16_t *bitmap) {
	uint32_t size = 240 * 320;
	uint16_t *bitmap_ptr = bitmap;
	LCD_SetCursor(0x00, 0x00);
	LCD_SetDisplayWindow(0, 0, 319, 239);
	LCD_WriteRAM_Prepare();
	volatile uint32_t index;
	for(index = 0; index<(size); index++)LCD_Data = *bitmap_ptr++;
}

void display_coordinate_pressed(){
	uint16_t x = 0,y = 0;
	bool_e appuye = FALSE;
	while(appuye == FALSE)appuye = TS_Get_Touch(&x, &y);
	char string_1[5] = "";
	char string_2[5] = "";
	itoa(x,string_1,10);
	itoa(y,string_2,10);
	LCD_SetFont(&Font8x8);
	LCD_DisplayStringLine(LINE(7)-2, COLUMN(16), (uint8_t *)string_1, 0xe454, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(10)+0.5, COLUMN(16), (uint8_t *)string_2, 0xe454, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
}

void allumerled(){
	BSP_GPIO_PinCfg(GREEN_LED, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FAST, 0);
	HAL_GPIO_WritePin(GREEN_LED, 1);
}

void delay(__IO uint32_t nCount){
	__IO uint32_t index = 0;
	for(index = (10000 * nCount); index != 0; index--){
	}
}

void display_char_pressed(int state){
	uint16_t x = 0,y = 0;
	bool_e appuye = FALSE;
	while(appuye == FALSE)appuye = TS_Get_Touch(&x, &y);
	char string_1[5] = "";
	char string_2[5] = "";
	char string_3[12] = "Lettre : ";
	itoa(x,string_1,10);
	itoa(y,string_2,10);
	LCD_SetFont(&Font8x8);
	LCD_DisplayStringLine(LINE(7)-2, COLUMN(16), (uint8_t *)string_1, 0xe454, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(10)+0.5, COLUMN(16), (uint8_t *)string_2, 0xe454, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_SetFont(&Font8x8);
	size_t cur_len = 9;
	char cur_char = appuye_touche(x,y,state);
	if(cur_len < 12) {
		string_3[cur_len] = cur_char;
		string_3[cur_len+1] = '\0';
	}
	LCD_DisplayStringLine(LINE(5), COLUMN(16), (uint8_t *)string_3, 0xe454, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	delay(500);
}
