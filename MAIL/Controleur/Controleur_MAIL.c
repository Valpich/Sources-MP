#include "controleur_MAIL.h"

//Changement vers menu chiffre : =
//Changement vers menu min : #
//Changement vers menu maj : +
//Delete : <
//Retour : \n
//Quitter : >
//Mauvais cas : %
//Envoyer : |

char appuye_touche(uint16_t x, uint16_t y, int state){
	switch(state){
	case 0: //Cas menu minuscule
		if(x<=39){
			return '>';
		}
		if(x>=276 && y>= 57 && x<=276+50 && y<= 57+16)return '|';
		if(y> 87 && y<=119){
			if(x>=(68-22) && x<=68)return 'a';
			if(x>=(68+28*1-22) && x<=68+28)return 'z';
			if(x>=(68+28*2-22) && x<=68+28*2)return 'e';
			if(x>=(68+28*3-22) && x<=68+28*3)return 'r';
			if(x>=(68+28*4-22) && x<=68+28*4)return 't';
			if(x>=(68+28*5-22) && x<=68+28*5)return 'y';
			if(x>=(68+28*6-22) && x<=68+28*6)return 'u';
			if(x>=(68+28*7-22) && x<=68+28*7)return 'i';
			if(x>=(68+28*8-22) && x<=68+28*8)return 'o';
			if(x>=(68+28*9-22) && x<=68+28*9)return 'p';
		}
		if(y> 119+3 && y<=159){
			if(x>=(68-22) && x<=68)return 'q';
			if(x>=(68+28*1-22) && x<=68+28)return 's';
			if(x>=(68+28*2-22) && x<=68+28*2)return 'd';
			if(x>=(68+28*3-22) && x<=68+28*3)return 'f';
			if(x>=(68+28*4-22) && x<=68+28*4)return 'g';
			if(x>=(68+28*5-22) && x<=68+28*5)return 'h';
			if(x>=(68+28*6-22) && x<=68+28*6)return 'j';
			if(x>=(68+28*7-22) && x<=68+28*7)return 'k';
			if(x>=(68+28*8-22) && x<=68+28*8)return 'l';
			if(x>=(68+28*9-22) && x<=68+28*9)return 'm';
		}
		if(y> 159+3 && y<=199){
			if(x>=(74-30) && x<=74)return '+';
			if(x>=(68+28*2-22) && x<=68+28*2)return 'w';
			if(x>=(68+28*3-22) && x<=68+28*3)return 'x';
			if(x>=(68+28*4-22) && x<=68+28*4)return 'c';
			if(x>=(68+28*5-22) && x<=68+28*5)return 'v';
			if(x>=(68+28*6-22) && x<=68+28*6)return 'b';
			if(x>=(68+28*7-22) && x<=68+28*7)return 'n';
			if(x>=68+28*9-30 && x<=68+28*9)return '<';
		}
		if(y> 199+3 && y<=237){
			if(x>=(74-30) && x<=74)return '=';
			if(x>=245-136 && x<=245)return ' ';
			if(x>=68+28*9-30 && x<=68+28*9)return '\n';
		}
		break;
	case 1: //Cas menu majuscule
		if(x<=39){
			return '>';
		}
		if(x>=276 && y>= 57 && x<=276+50 && y<= 57+16)return '|';
		if(y> 87 && y<=119){
			if(x>=(68-22) && x<=68)return 'A';
			if(x>=(68+28*1-22) && x<=68+28)return 'Z';
			if(x>=(68+28*2-22) && x<=68+28*2)return 'E';
			if(x>=(68+28*3-22) && x<=68+28*3)return 'R';
			if(x>=(68+28*4-22) && x<=68+28*4)return 'T';
			if(x>=(68+28*5-22) && x<=68+28*5)return 'Y';
			if(x>=(68+28*6-22) && x<=68+28*6)return 'U';
			if(x>=(68+28*7-22) && x<=68+28*7)return 'I';
			if(x>=(68+28*8-22) && x<=68+28*8)return 'O';
			if(x>=(68+28*9-22) && x<=68+28*9)return 'P';
		}
		if(y> 159+3 && y<=159){
			if(x>=(68-22) && x<=68)return 'Q';
			if(x>=(68+28*1-22) && x<=68+28)return 'S';
			if(x>=(68+28*2-22) && x<=68+28*2)return 'D';
			if(x>=(68+28*3-22) && x<=68+28*3)return 'F';
			if(x>=(68+28*4-22) && x<=68+28*4)return 'G';
			if(x>=(68+28*5-22) && x<=68+28*5)return 'H';
			if(x>=(68+28*6-22) && x<=68+28*6)return 'J';
			if(x>=(68+28*7-22) && x<=68+28*7)return 'K';
			if(x>=(68+28*8-22) && x<=68+28*8)return 'L';
			if(x>=(68+28*9-22) && x<=68+28*9)return 'M';
		}
		if(y> 159+3 && y<=199){
			if(x>=(74-30) && x<=74)return '#';
			if(x>=(68+28*2-22) && x<=68+28*2)return 'W';
			if(x>=(68+28*3-22) && x<=68+28*3)return 'X';
			if(x>=(68+28*4-22) && x<=68+28*4)return 'C';
			if(x>=(68+28*5-22) && x<=68+28*5)return 'V';
			if(x>=(68+28*6-22) && x<=68+28*6)return 'B';
			if(x>=(68+28*7-22) && x<=68+28*7)return 'N';
			if(x>=68+28*9-30 && x<=68+28*9)return '<';
		}
		if(y> 199+3 && y<=237){
			if(x>=(74-30) && x<=74)return '=';
			if(x>=245-136 && x<=245)return ' ';
			if(x>=68+28*9-30 && x<=68+28*9)return '\n';
		}
		break;
	case 2: //Cas menu chiffre
		if(x<=39){
			return '>';
		}
		if(x>=276 && y>= 57 && x<=276+50 && y<= 57+16)return '|';
		if(y>87 && y<=119){
			if(x>=(68-22) && x<=68)return '1';
			if(x>=(68+28*1-22) && x<=68+28)return '2';
			if(x>=(68+28*2-22) && x<=68+28*2)return '3';
			if(x>=(68+28*3-22) && x<=68+28*3)return '4';
			if(x>=(68+28*4-22) && x<=68+28*4)return '5';
			if(x>=(68+28*5-22) && x<=68+28*5)return '6';
			if(x>=(68+28*6-22) && x<=68+28*6)return '7';
			if(x>=(68+28*7-22) && x<=68+28*7)return '8';
			if(x>=(68+28*8-22) && x<=68+28*8)return '9';
			if(x>=(68+28*9-22) && x<=68+28*9)return '0';
		}
		if(y>119+3 && y<=159){
			if(x>=(68-22) && x<=68)return '-';
			if(x>=(68+28*1-22) && x<=68+28)return '/';
			if(x>=(68+28*2-22) && x<=68+28*2)return ':';
			if(x>=(68+28*3-22) && x<=68+28*3)return ';';
			if(x>=(68+28*4-22) && x<=68+28*4)return '(';
			if(x>=(68+28*5-22) && x<=68+28*5)return ')';
			if(x>=(68+28*6-22) && x<=68+28*6)return 'E';
			if(x>=(68+28*7-22) && x<=68+28*7)return '&';
			if(x>=(68+28*8-22) && x<=68+28*8)return '@';
			if(x>=(68+28*9-22) && x<=68+28*9)return '"';
		}
		if(y>159+3 && y<=199){
			if(x>=(107-35) && x<=107)return '.';
			if(x>=(107+39-35) && x<=107+39)return ',';
			if(x>=(107+39*2-35) && x<=107+39*2)return '?';
			if(x>=(107+39*3-35) && x<=107+39*3)return '!';
			if(x>=(107+39*4-35) && x<=107+39*4)return '\'';
			if(x>=68+28*9-30 && x<=68+28*9)return '<';
		}
		if(y>199+3 && y<=237){
			if(x>=(74-30) && x<=74)return '#';
			if(x>=245-136 && x<=245)return ' ';
			if(x>=68+28*9-30 && x<=68+28*9)return '<';
		}
		break;
	case 4: //Cas menu chiffre numero
		if(x<=39){
			return '>';
		}
		if(x>=276 && y>= 57 && x<=276+50 && y<= 57+16)return '|';
		if(y>87 && y<=119){
			if(x>=(68-22) && x<=68)return '1';
			if(x>=(68+28*1-22) && x<=68+28)return '2';
			if(x>=(68+28*2-22) && x<=68+28*2)return '3';
			if(x>=(68+28*3-22) && x<=68+28*3)return '4';
			if(x>=(68+28*4-22) && x<=68+28*4)return '5';
			if(x>=(68+28*5-22) && x<=68+28*5)return '6';
			if(x>=(68+28*6-22) && x<=68+28*6)return '7';
			if(x>=(68+28*7-22) && x<=68+28*7)return '8';
			if(x>=(68+28*8-22) && x<=68+28*8)return '9';
			if(x>=(68+28*9-22) && x<=68+28*9)return '0';
		}
		if(y>119+3 && y<=159){
			if(x>=(68-22) && x<=68)return '-';
			if(x>=(68+28*8-22) && x<=68+28*8)return '@';
		}
		if(y>159+3 && y<=199){
			if(x>=(107-35) && x<=107)return '.';
			if(x>=68+28*9-30 && x<=68+28*9)return '<';
		}
		break;
	default :
		return '%';
		break;
	}
	return '%';
}

Bool_SMS saisie_message(char * SMS_0){
	typedef enum{
		MIN = 0,
		MAJ,
		CHIFFRE
	}state_e;
	SMS_0[0]='\0';
	static state_e etat= MIN;
	uint16_t x = 0,y = 0;
	char cur_char;
	static int retour = -1;
	switch(etat){
	case MIN :
		dessin_saisie_message_min();
		break;
	case MAJ :
		dessin_saisie_message_maj();
		break;
	case CHIFFRE :
		dessin_saisie_message_chiffre();
		break;
	default :
		break;
	}
	do{
		do{
			bool_e appuye = FALSE;
			while(appuye == FALSE){
				appuye = TS_Get_Touch(&x, &y);
			}
			delay(300);
			cur_char = appuye_touche(x,y,etat);
		}while(cur_char == '%'); //Mauvaise touche
		if(cur_char == '>')return FALSE_SMS; //Quitter
		if(cur_char == '=')etat = CHIFFRE; //Changement de menu vers chiffre
		if(cur_char == '#')etat = MIN;  //Changement de menu vers min
		if(cur_char == '+')etat = MAJ;  //Changement de menu vers maj
		size_t cur_len_message = strlen(SMS_0);
		if(cur_char == '<' && cur_len_message>0){
			SMS_0[cur_len_message-1] = '\0'; //Delete
		}else if(cur_len_message < 80 && cur_char != '=' && cur_char != '#' && cur_char != '+'  && retour != 4 && cur_char!='|' && cur_char != '<' ){
			SMS_0[cur_len_message] = cur_char;
			SMS_0[cur_len_message+1] = '\0';
		}
		switch(etat){
		case MIN :
			dessin_saisie_message_min();
			break;
		case MAJ :
			dessin_saisie_message_maj();
			break;
		case CHIFFRE :
			dessin_saisie_message_chiffre();
			break;
		default :
			break;
		}
		retour = display_sms(SMS_0);
	}while(cur_char!='|' );
	return TRUE_SMS;
}

Bool_SMS saisie_objet(char * OBJET_0){
	typedef enum{
		MIN = 0,
		MAJ,
		CHIFFRE
	}state_e;
	OBJET_0[0]='\0';
	static state_e etat= MIN;
	uint16_t x = 0,y = 0;
	char cur_char;
	static int retour = -1;
	switch(etat){
	case MIN :
		dessin_saisie_message_min();
		break;
	case MAJ :
		dessin_saisie_message_maj();
		break;
	case CHIFFRE :
		dessin_saisie_message_chiffre();
		break;
	default :
		break;
	}
	display_objet(OBJET_0);
	do{
		do{
			bool_e appuye = FALSE;
			while(appuye == FALSE){
				appuye = TS_Get_Touch(&x, &y);
			}
			delay(300);
			cur_char = appuye_touche(x,y,etat);
		}while(cur_char == '%'); //Mauvaise touche
		if(cur_char == '>')return FALSE_SMS; //Quitter
		if(cur_char == '=')etat = CHIFFRE; //Changement de menu vers chiffre
		if(cur_char == '#')etat = MIN;  //Changement de menu vers min
		if(cur_char == '+')etat = MAJ;  //Changement de menu vers maj
		size_t cur_len_message = strlen(OBJET_0);
		if(cur_char == '<' && cur_len_message>0){
			OBJET_0[cur_len_message-1] = '\0'; //Delete
		}else if(cur_len_message < 20 && cur_char != '=' && cur_char != '#' && cur_char != '+'  && retour != 4 && cur_char!='|' && cur_char != '<'){
			OBJET_0[cur_len_message] = cur_char;
			OBJET_0[cur_len_message+1] = '\0';
		}
		switch(etat){
		case MIN :
			dessin_saisie_message_min();
			break;
		case MAJ :
			dessin_saisie_message_maj();
			break;
		case CHIFFRE :
			dessin_saisie_message_chiffre();
			break;
		default :
			break;
		}
		display_objet(OBJET_0);
	}while(cur_char!='|' );
	return TRUE_SMS;
}

Bool_SMS saisie_numero(char * NUMERO_0){
	typedef enum{
		MIN = 0,
		MAJ,
		CHIFFRE
	}state_e;
	NUMERO_0[0]='\0';
	static state_e etat= MIN;
	Bool_SMS test = FALSE_SMS;
	uint16_t x = 0,y = 0;
	char cur_char;
	switch(etat){
	case MIN :
		dessin_saisie_message_min();
		break;
	case MAJ :
		dessin_saisie_message_maj();
		break;
	case CHIFFRE :
		dessin_saisie_message_chiffre();
		break;
	default :
		break;
	}
	display_numero(NUMERO_0);
	do{
		do{
			bool_e appuye = FALSE;
			while(appuye == FALSE){
				appuye = TS_Get_Touch(&x, &y);
			}
			delay(300);
			cur_char = appuye_touche(x,y,etat);
		}while(cur_char == '%'); //Mauvaise touche
		if(cur_char == '>')return FALSE_SMS; //Quitter
		if(cur_char == '=')etat = CHIFFRE; //Changement de menu vers chiffre
		if(cur_char == '#')etat = MIN;  //Changement de menu vers min
		if(cur_char == '+')etat = MAJ;  //Changement de menu vers maj
		size_t cur_len_message = strlen(NUMERO_0);
		if(cur_char == '<' && cur_len_message>0){
			NUMERO_0[cur_len_message-1] = '\0'; //Delete
		}else if(cur_len_message < 80 && cur_char != '=' && cur_char != '#' && cur_char != '+'  && cur_char!='|' && cur_char != '<'){
			NUMERO_0[cur_len_message] = cur_char;
			NUMERO_0[cur_len_message+1] = '\0';
		}
		switch(etat){
		case MIN :
			dessin_saisie_message_min();
			break;
		case MAJ :
			dessin_saisie_message_maj();
			break;
		case CHIFFRE :
			dessin_saisie_message_chiffre();
			break;
		default :
			break;
		}
		display_numero(NUMERO_0);
		if(cur_char == '|'){
			if(test_mail_valide(NUMERO_0) !=0)test = TRUE_SMS;
		}
	}while(test == FALSE_SMS); //Valider
	return TRUE_SMS;
}

void choisir_quitter_app_SMS(){
	m_exit_SMS = TRUE;
	longjmp(buf_SMS,1);
}

int appuye_menu_sms(uint16_t x, uint16_t y){
	if(x<=39)choisir_quitter_app_SMS();
	if(y> LINE(28)-10){
		if(x>=COLUMN(6)-2 && x<= COLUMN(15)-5)return 0;
		if(x>=COLUMN(15) && x<=COLUMN(24)-7)return 1;
		if(x>=COLUMN(24)-2 && x<=COLUMN(24)-2+8*7)return 2;
		if(x>=COLUMN(24)-2+8*8)return 3;
	}
	return 0;
}
