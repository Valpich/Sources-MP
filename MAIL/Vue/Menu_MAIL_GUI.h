#ifndef MENU_MAIL_GUI_H
#define MENU_MAIL_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include "../../GUI.h"
#include "stm32f4_lcd.h"

void dessin_menu_sms();
void display_message(char * sms);
void display_numero_message(char * numero);
void display_subject_message(char * subject);

#ifdef __cplusplus
}
#endif

#endif
