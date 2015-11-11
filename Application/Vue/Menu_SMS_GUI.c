#include "Menu_SMS_GUI.h"

void test_dessin_menu_sms(){
    LCD_BMP((uint8_t *)MENU_SMS_GUI);
	delay(10000);
	allumerled();
}
