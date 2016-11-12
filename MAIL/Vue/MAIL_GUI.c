#include "MAIL_GUI.h"

int display_sms(const char * sms){
	char SMS_1[21]="";
	char SMS_2[21]="";
	char SMS_3[21]="";
	char SMS_4[21]="";
	int i = 0;
	int n = 0;
	int current = 0;
	int retour = -1;
	for(i=0;i<strlen(sms);i++){
		switch(n){
		case 0:
			if(i < 20){
				if(sms[i]!='\n')SMS_1[i] = sms[i];
				if(sms[i]!='\n')SMS_1[i+1] = '\0';
			}else if(i>= 20 && i < 40){
				if(sms[i]!='\n')SMS_2[i-20] = sms[i];
				if(sms[i]!='\n')SMS_2[i+1-20] = '\0';
			}else if (i>=40 && i < 60){
				if(sms[i]!='\n')SMS_3[i-40] = sms[i];
				if(sms[i]!='\n')SMS_3[i+1-40] = '\0';
			}else if(i>=60 && i < 80){
				if(sms[i]!='\n')SMS_4[i-60] = sms[i];
				if(sms[i]!='\n')SMS_4[i+1-60] = '\0';
			}else{
				retour = 0;
			}
			if(sms[i]=='\n'){
				n++;
				current = i+1;
			}
			break;
		case 1:
			if(i>= current && i < 20+current){
				if(sms[i]!='\n')SMS_2[i-current] = sms[i];
				if(sms[i]!='\n')SMS_2[i+1-current] = '\0';
			}else if (i>=20+current && i < 40+current){
				if(sms[i]!='\n')SMS_3[i-current-20] = sms[i];
				if(sms[i]!='\n')SMS_3[i+1-20-current] = '\0';
			}else if(i>=40+current && i < 60+current){
				if(sms[i]!='\n')SMS_4[i-40-current] = sms[i];
				if(sms[i]!='\n')SMS_4[i+1-40-current] = '\0';
			}else{
				retour = 1;
			}
			if(sms[i]=='\n'){
				n++;
				current = i+1;
			}
			break;
		case 2:
			if(i>= current && i < 20+current){
				if(sms[i]!='\n')SMS_3[i-current] = sms[i];
				if(sms[i]!='\n')SMS_3[i+1-current] = '\0';
			}else if (i>=20+current && i < 40+current){
				if(sms[i]!='\n')SMS_4[i-20-current] = sms[i];
				if(sms[i]!='\n')SMS_4[i+1-20-current] = '\0';
			}else{
				retour = 2;
			}
			if(sms[i]=='\n'){
				n++;
				current = i+1;
			}
			break;
		case 3:
			if(i>= current && i < 20+current){
				if(sms[i]!='\n')SMS_4[i-current] = sms[i];
				if(sms[i]!='\n')SMS_4[i+1-current] = '\0';
			}else{
				retour = 3;
			}
			if(sms[i]=='\n'){
				n++;
				current = i+1;
			}
			break;
		default :
			retour = 4;
			break;
		}
	}
	LCD_SetFont(&Font8x8);
	LCD_DisplayStringLine(LINE(1), COLUMN(11), (uint8_t *)SMS_1, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(3), COLUMN(11), (uint8_t *)SMS_2, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(5), COLUMN(11), (uint8_t *)SMS_3, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(7), COLUMN(11), (uint8_t *)SMS_4, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	return retour;
}

void display_numero(const char * numero){
	LCD_SetFont(&Font8x8);
	char NUMERO_0[21]="Adresse email :";
	LCD_DisplayStringLine(LINE(1), COLUMN(11), (uint8_t *)NUMERO_0, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(3), COLUMN(11), (uint8_t *)numero, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
}

void display_objet(const char * objet){
	LCD_SetFont(&Font8x8);
	char OBJET_0[21]="Objet :";
	LCD_DisplayStringLine(LINE(1), COLUMN(11), (uint8_t *)OBJET_0, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(3), COLUMN(11), (uint8_t *)objet, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
}
