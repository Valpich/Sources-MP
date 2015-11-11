#include "Saisie_message_min_GUI.h"

void test_dessin_saisie_message_min(){
    LCD_BMP((uint8_t *)Saisie_message_min_GUI);
	delay(10000);
	allumerled();
}
