#include "Jeu_1010_GUI.h"

void test_dessin_1010(){
	LCD_BMP((uint8_t *)JEU_1010_GUI);
	char ch1[5] = "";
	int tmp = 1000;
	itoa(tmp,ch1,10);
	LCD_SetFont(&Font8x8);
	LCD_DisplayStringLine(LINE(10)-2, COLUMN(15), (uint8_t *)ch1, 0x9edd, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
/*	int i,j;
	for(j=0;j<10;j++){
		for(i=0;i<10;i++){
			LCD_DrawFullRect(114+i*13, 98+13*j,12,11, 0x1726,0x1726);
		}
	}*/
	delay(1000);
	allumerled();
}
