#include "Saisie_message_maj_GUI.h"

void test_dessin_saisie_message_maj(){
    LCD_BMP((uint8_t *)Saisie_message_maj_GUI);
	delay(10000);
	allumerled();
}
