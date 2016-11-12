#include "Menu_MAIL_GUI.h"

void dessin_menu_sms(char * NUMERO, char * SUBJECT, char * SMS){
	LCD_Clear(LCD_COLOR_WHITE);
	LCD_DrawFullRect(39,0,3,240, 0x2589, 0x2589);
	LCD_DrawFullRect(42,39,320-42,3, 0xfbe4, 0xfbe4);
	LCD_SetFont(&Font12x12);
	char string_SMS[] = "   MAIL    ";
	char string_SMS_AFFICHER[] = "AFFICHER";
	char string_SMS_CHARGER[] = "CHARGER";
	char string_SMS_NOUVEAU[] = "NOUVEAU";
	char string_SMS_REPONDRE[] = "REPONDRE";
	LCD_DisplayStringLine(LINE(2)-2, COLUMN(10), (uint8_t *)string_SMS, 0xfbe4, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_SetFont(&Font8x8);
	LCD_DisplayStringLine(LINE(28)-2, COLUMN(6)-2, (uint8_t *)string_SMS_AFFICHER, 0xfbe4, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(28)-2, COLUMN(15), (uint8_t *)string_SMS_CHARGER, 0xfbe4, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(28)-2, COLUMN(24)-5, (uint8_t *)string_SMS_NOUVEAU, 0xfbe4, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(28)-2, COLUMN(32)-2, (uint8_t *)string_SMS_REPONDRE, 0xfbe4, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	char string_Q[] = "Q";
	char string_U[] = "U";
	char string_I[] = "I";
	char string_T[] = "T";
	char string_TT[] = "T";
	char string_E[] = "E";
	char string_R[] = "R";
	LCD_SetFont(&Font12x12);
	LCD_DisplayStringLine(LINE(4), COLUMN(1)+4, (uint8_t *)string_Q, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(6), COLUMN(1)+4, (uint8_t *)string_U, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(8), COLUMN(1)+6, (uint8_t *)string_I, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(10), COLUMN(1)+4, (uint8_t *)string_T, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(12), COLUMN(1)+4, (uint8_t *)string_TT, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(14), COLUMN(1)+4, (uint8_t *)string_E, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(16), COLUMN(1)+4, (uint8_t *)string_R, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	display_numero_message(NUMERO);
	display_subject_message(SUBJECT);
	display_message(SMS);
	delay(100);
}

void display_message(char * sms){
	char SMS_0[]="Message :";
	char SMS_1[31]="";
	char SMS_2[31]="";
	char SMS_3[31]="";
	char SMS_4[31]="";
	int i = 0;
	int n = 0;
	int current = 0;
	for(i=0;i<strlen(sms);i++){
		switch(n){
		case 0:
			if(i < 30){
				if(sms[i]!='\n')SMS_1[i] = sms[i];
				if(sms[i]!='\n')SMS_1[i+1] = '\0';
			}else if(i>= 30 && i < 60){
				if(sms[i]!='\n')SMS_2[i-30] = sms[i];
				if(sms[i]!='\n')SMS_2[i+1-30] = '\0';
			}else if (i>=60 && i < 90){
				if(sms[i]!='\n')SMS_3[i-60] = sms[i];
				if(sms[i]!='\n')SMS_3[i+1-60] = '\0';
			}else if(i>=90 && i < 120){
				if(sms[i]!='\n')SMS_4[i-90] = sms[i];
				if(sms[i]!='\n')SMS_4[i+1-90] = '\0';
			}
			if(sms[i]=='\n'){
				n++;
				current = i+1;
			}
			break;
		case 1:
			if(i>= current && i < 30+current){
				if(sms[i]!='\n')SMS_2[i-current] = sms[i];
				if(sms[i]!='\n')SMS_2[i+1-current] = '\0';
			}else if (i>=30+current && i < 60+current){
				if(sms[i]!='\n')SMS_3[i-current-30] = sms[i];
				if(sms[i]!='\n')SMS_3[i+1-30-current] = '\0';
			}else if(i>=60+current && i < 90+current){
				if(sms[i]!='\n')SMS_4[i-60-current] = sms[i];
				if(sms[i]!='\n')SMS_4[i+1-60-current] = '\0';
			}
			if(sms[i]=='\n'){
				n++;
				current = i+1;
			}
			break;
		case 2:
			if(i>= current && i < 30+current){
				if(sms[i]!='\n')SMS_3[i-current] = sms[i];
				if(sms[i]!='\n')SMS_3[i+1-current] = '\0';
			}else if (i>=30+current && i < 60+current){
				if(sms[i]!='\n')SMS_4[i-30-current] = sms[i];
				if(sms[i]!='\n')SMS_4[i+1-30-current] = '\0';
			}
			if(sms[i]=='\n'){
				n++;
				current = i+1;
			}
			break;
		case 3:
			if(i>= current && i < 30+current){
				if(sms[i]!='\n')SMS_4[i-current] = sms[i];
				if(sms[i]!='\n')SMS_4[i+1-current] = '\0';
			}
			if(sms[i]=='\n'){
				n++;
				current = i+1;
			}
			break;
		default :
			break;
		}
	}
	LCD_SetFont(&Font8x8);
	LCD_DisplayStringLine(LINE(14), COLUMN(7), (uint8_t *)SMS_0, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(16), COLUMN(7), (uint8_t *)SMS_1, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(18), COLUMN(7), (uint8_t *)SMS_2, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(20), COLUMN(7), (uint8_t *)SMS_3, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(22), COLUMN(7), (uint8_t *)SMS_4, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
}

void display_numero_message(char * numero){
	LCD_SetFont(&Font8x8);
	char NUMERO_0[20]="Adresse email :";
	LCD_DisplayStringLine(LINE(6), COLUMN(7), (uint8_t *)NUMERO_0, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(8), COLUMN(7), (uint8_t *)numero, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
}

void display_subject_message(char * subject){
	LCD_SetFont(&Font8x8);
	char OBJECT_0[20]="Objet :";
	LCD_DisplayStringLine(LINE(10), COLUMN(7), (uint8_t *)OBJECT_0, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(12), COLUMN(7), (uint8_t *)subject, 0x0000, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
}

