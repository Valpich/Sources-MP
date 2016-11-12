#include "MAIL.h"
//#define DEBUG_ON

void SMS_init(void){
#ifdef DEBUG_ON
	strcpy(SMS_1,"Coucou\nComment tu va ?\nCeci est un test !\nC'est un MAIL_1 !");
	strcpy(OBJET_1,"Objet 1");
	strcpy(NUMERO_1,"valentin.pichavant@reseau.eseo.fr");
	strcpy(SMS_2,"Coucou\nComment tu va ?\nCeci est un test !\nC'est un MAIL_2 !");
	strcpy(OBJET_2,"Objet 2");
	strcpy(NUMERO_2,"test2@hotmail.fr");
	strcpy(SMS_3,"Coucou\nComment tu va ?\nCeci est un test !\nC'est un MAIL_3 !");
	strcpy(OBJET_3,"Objet 3");
	strcpy(NUMERO_3,"test3@hotmail.fr");
#else
	NUMERO_1[0]='\0';
	NUMERO_2[0]='\0';
	NUMERO_3[0]='\0';
	OBJET_1[0]='\0';
	OBJET_2[0]='\0';
	OBJET_3[0]='\0';
	SMS_1[0]='\0';
	SMS_2[0]='\0';
	SMS_3[0]='\0';

#endif
}

void SMS_nouveau(){
	int envoi_fini = 0;
	SMS_node_restart();
	char SMS[100]="";
	char OBJET[60]="";
	char NUMERO[60]="";
	numero :
	if(saisie_numero(NUMERO) == FALSE_SMS)return;
	objet :
	if(saisie_objet(OBJET) == FALSE_SMS){
		OBJET[0]='\0';
		goto numero;
	}
	if(saisie_message(SMS) == FALSE_SMS){
		SMS[0]='\0';
		goto objet;
	}
	envoi_fini = SMS_envoyer(NUMERO,OBJET,SMS);
}

void SMS_repondre(char * NUMERO){
	int envoi_fini = 0;
	SMS_node_restart();
	char SMS[100]="";
	char OBJET[60]="";
	objet:
	if(saisie_objet(OBJET) == FALSE_SMS){
		OBJET[0]='\0';
		return;
	}
	if(saisie_message(SMS) == FALSE_SMS){
		goto objet;
	}
	envoi_fini = SMS_envoyer(NUMERO,OBJET,SMS);
}


typedef enum machine_mail{
	NON_RECEPTION =0,
	RECEPTION_FROM,
	RECEPTION_SUBJECT,
	RECEPTION_MESSAGE
}machine_mail;


void SMS_recevoir(){
	char c=-1;
	timer_start = TRUE;
	printf("dofile(\"readMail2.lua\")\r\n");
	while(c!=1)c=UART_getc(6);
    timer_start = FALSE;
	timer_start_2 = TRUE;
	static machine_mail machineMail = RECEPTION_FROM;
	static int indexFrom;
	static int indexSubject;
	static int indexMessage;
	NUMERO_1[0] = '\0';
	indexFrom = 0;
	OBJET_1[0] = '\0';
	indexSubject = 0;
	SMS_1[0] = '\0';
	indexMessage = 0;
	machineMail = RECEPTION_FROM;
	bool_e debut_from = FALSE;
	bool_e debut_subject = FALSE;
	bool_e debut_message = FALSE;
	do{
		c = UART_getc(6);
		switch(machineMail){
		case NON_RECEPTION:
			break;
		case RECEPTION_FROM:
			if(c!=1 && c!=2 && c!=3 && c!=4 && c!=0){
				if(c=='>')debut_from = FALSE;
				if(debut_from ==TRUE){
					NUMERO_1[indexFrom] = c;
					indexFrom++;
				}
				if(c=='<')debut_from = TRUE;
			}
			if(c==2){
				NUMERO_1[indexFrom] = '\0';
				machineMail = RECEPTION_SUBJECT;
			}
			break;
		case RECEPTION_SUBJECT:
			if(c!=1 && c!=2 && c!=3 && c!=4 && c!=0){
				if(c=='\r')debut_subject=FALSE;
				if(debut_subject == TRUE){
					OBJET_1[indexSubject] = c;
					indexSubject++;
				}
				if(c==' ')debut_subject=TRUE;
			}
			if(c==3){
				OBJET_1[indexSubject] = '\0';
				machineMail = RECEPTION_MESSAGE;
			}
			break;
		case RECEPTION_MESSAGE:
			if(c!=1 && c!=2 && c!=3 && c!=4 && c!=0){
				if(c>=32)debut_message=TRUE;
				if(c=='\r')debut_message=FALSE;
				if(debut_message == TRUE){
					SMS_1[indexMessage] = c;
					indexMessage++;
					if(indexMessage==84 && c=='=')indexMessage--;
				}
			}
			if(c==4){
				SMS_1[indexMessage] = '\0';
				machineMail = NON_RECEPTION;
			}
			break;
		default:
			machineMail = NON_RECEPTION;
			break;
		}
	}while(machineMail!=NON_RECEPTION);
    timer_start_2 = FALSE;

}

void SMS_node_restart(){
	printf("node.restart()\r\n");
}

int SMS_envoyer(char * numero, char * objet, char * message){
	printf("dofile(\"sendMail.lua\")\r\n");
	delay(100);
	printf("send_email(\"%s\",\"%s\",\"%s\")\r\n",numero,objet,message);
	delay(80000);
	return 1;
}

int appli_SMS_lancer(){
	SMS_init();
	m_exit_SMS = FALSE_SMS;
	setjmp(buf_SMS);
	if(m_exit_SMS == TRUE_SMS){
		delay(100);
		return 1;
	}
	while(1)appli_SMS_main();
	return 0;
}

void appli_SMS_main(){
	typedef enum{
		MENU_SMS_1 = 0,
		MENU_SMS_2,
		NOUVEAU_SMS,
		REPONDRE_SMS
	}state_e;
	static state_e etat = MENU_SMS_1;
	static state_e etat_precedent = -1;
	etat_precedent = -1;
	bool_e appuye = FALSE;
	uint16_t x = 0,y = 0;
	switch(etat){
	case MENU_SMS_1:
		if(etat_precedent!=etat){
			dessin_menu_sms(NUMERO_1,OBJET_1,SMS_1);
			SMS_node_restart();
		}
		TIME_OUT = FALSE;
		time_out = 0;
		timer_start = FALSE;
		TIME_OUT_2 = FALSE;
		time_out_2 = 0;
		timer_start_2 = FALSE;
		while(appuye == FALSE){
			appuye = TS_Get_Touch(&x, &y);
		}
		etat_precedent = etat;
		etat = appuye_menu_sms(x, y);
		break;
	case MENU_SMS_2:
		if(etat_precedent!=etat)dessin_menu_sms(NUMERO_1,OBJET_1,SMS_1);
		setjmp(buf_time_out);
		if(TIME_OUT == FALSE && TIME_OUT_2 == FALSE)SMS_recevoir();
		etat_precedent = etat;
		etat = MENU_SMS_1;
		break;
	case NOUVEAU_SMS:
		SMS_nouveau();
		etat_precedent = etat;
		etat = MENU_SMS_1;
		break;
	case REPONDRE_SMS:
		SMS_repondre(NUMERO_1);
		etat_precedent = REPONDRE_SMS;
		etat = MENU_SMS_1;
		break;
	default :
		etat_precedent = MENU_SMS_1;
		etat = MENU_SMS_1;
		break;
	}
}

int test_mail_valide(char s[]){
	return 1;
	int length=strlen(s), ind1=0;
	int i;
	int j;
	for(i = 0;i<length;i++){
		s[i] = tolower(s[i]);
	}
	if ((s[0]<'a') || (s[0]>'z')){
		return 0;
	}else{
		for (i=1;i<length;i++){
			if (s[i]=='@'){
				ind1=i+1;
				break;
			} else if ( (s[i]<'a') || (s[i]>'z') ) return 0;
		}
		for (j=ind1;j<length;j++){
			if (s[j]=='.'){
				break;
			} else if ( (s[j]<'a') || (s[j]>'z') ) return 0;
		}
	}
	return 1;
}

void TIMER2_user_handler_it_1ms(void){
	TS_process_1ms();
	if(timer_start == TRUE)time_out++;
	if(time_out >= 10000){
		TIME_OUT = TRUE;
		time_out = 0;
		timer_start = FALSE;
		longjmp(buf_time_out,1);
	}
	if(timer_start_2 == TRUE)time_out_2++;
	if(time_out_2 >= 2000){
		TIME_OUT_2 = TRUE;
		time_out_2 = 0;
		timer_start_2 = FALSE;
		longjmp(buf_time_out,1);
	}
}
