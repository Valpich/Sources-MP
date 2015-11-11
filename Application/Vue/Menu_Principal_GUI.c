#include "Menu_Principal_GUI.h"

void test_dessin_menu_principal(){
    LCD_BMP((uint8_t *)Menu_Principal_GUI);
	delay(10000);
	allumerled();
}
