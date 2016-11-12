#ifndef controleur_MAIL_H
#define controleur_MAIL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include "../../GUI.h"
#include "stm32f4_lcd.h"
#include "../../MAIL/Vue/MAIL_GUI.h"
#include "../../MAIL/Modele/MAIL.h"

char appuye_touche(uint16_t x, uint16_t y, int state);

Bool_SMS saisie_message(char * SMS_0);

Bool_SMS saisie_numero(char * NUMERO_0);

int appuye_menu(uint16_t x, uint16_t y);

#ifdef __cplusplus
}
#endif

#endif
