#ifndef GUI_H
#define GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include "lcd_display_form_and_text.h"

#define GREEN_LED	GPIOD, GPIO_PIN_12

typedef struct Point_GUI{
	uint16_t x;
	uint16_t y;
}Point_GUI;

typedef struct Cercle_GUI{
	Point_GUI point;
	uint16_t rayon;
}Cercle_GUI;

typedef struct Droite_GUI{
	Point_GUI point_A;
	Point_GUI point_B;
}Droite_GUI;

typedef struct Croix_GUI{
	Droite_GUI droite_A;
	Droite_GUI droite_B;
}Croix_GUI;

void LCD_BMP(uint8_t *bitmap);
void test_dessin_image_1();
void test_dessin_image_2();
void allumerled();
void delay(__IO uint32_t nCount);

#ifdef __cplusplus
}
#endif

#endif
