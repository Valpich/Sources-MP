#ifndef MAIL_H_
#define MAIL_H_

#include <string.h>
#include <setjmp.h>
#include <ctype.h>
#include "../../MAIL/Vue/Menu_MAIL_GUI.h"
#include "../../GUI.h"

typedef enum Bool_SMS{
	FALSE_SMS,TRUE_SMS
}Bool_SMS;

/**
 * \var jmp_buf buf_SMS
 * \brief Permet d'indiquer à quel moment revenir lors du longjump du controleur.
 */
jmp_buf buf_SMS;


/**
 * \var jmp_buf buf_time_out
 * \brief Permet d'indiquer à quel moment revenir lors du timeout.
 */
jmp_buf buf_time_out;

/**
 * \var Bool_SMS m_exit_SMS
 * \brief Booléen indiquant qu'il faut terminer l'application de façon instannée si TRUE.
 */
Bool_SMS m_exit_SMS;

volatile bool_e TIME_OUT;

volatile bool_e timer_start;

volatile uint32_t time_out;

volatile bool_e TIME_OUT_2;

volatile bool_e timer_start_2;

volatile uint32_t time_out_2;

volatile char SMS_1[100];

volatile char SMS_2[100];

volatile char SMS_3[100];

volatile char NUMERO_1[60];

volatile char NUMERO_2[60];

volatile char NUMERO_3[60];

volatile char OBJET_1[60];

volatile char OBJET_2[60];

volatile char OBJET_3[60];

void SMS_init(void);

void SMS_nouveau();

void SMS_repondre(char * NUMERO);

int SMS_envoyer(char * numero, char * objet, char * message);

int appli_SMS_lancer();

void appli_SMS_main();

int test_mail_valide(char s[]);


#endif /* SMS_H_ */
