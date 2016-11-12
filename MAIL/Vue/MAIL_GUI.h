#ifndef MAIL_GUI_H
#define MAIL_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include "../../GUI.h"
#include "stm32f4_lcd.h"

int display_sms(const char * sms);

void display_numero(const char * numero);

void display_objet(const char * objet);

#ifdef __cplusplus
}
#endif

#endif
