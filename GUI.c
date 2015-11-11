#include "GUI.h"

void LCD_BMP(uint8_t *bitmap) {
    uint32_t size = 240 * 320;
    uint16_t *bitmap_ptr = (uint16_t *)bitmap;
    LCD_SetCursor(0x00, 0x00);
    LCD_SetDisplayWindow(0, 0, 319, 239);
    LCD_WriteRAM_Prepare();
    volatile uint32_t index;
    for(index = 0; index<(size); index++)
    {
        LCD_Data = *bitmap_ptr++;
    }
    allumerled();
}

void test_dessin_image_1(){
   /* LCD_BMP((uint8_t *)Menu_Principal_GUI);
	delay(10000);
	allumerled();*/
}

void test_dessin_image_2(){
    /*register short x,y;
    for(y = 0;y<240;y++){
        for(x = 0; x<320; x++){
        	LCD_PutPixel(x,y,Menu_Principal_GUI[x+320*y]);
        }
    }*/
    allumerled();
}

void allumerled(){
    static int allumeGreen = 0;
    allumeGreen++;
	if(allumeGreen <=1000){
		HAL_GPIO_WritePin(GREEN_LED, 0);
	}
	else{
		if(allumeGreen>=2000)allumeGreen=0;
		HAL_GPIO_WritePin(GREEN_LED, 1);
	}
}

void delay(__IO uint32_t nCount){
	__IO uint32_t index = 0;
	for(index = (10000 * nCount); index != 0; index--){
	}
}
