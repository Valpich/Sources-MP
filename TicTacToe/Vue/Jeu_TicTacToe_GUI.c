#include "Jeu_TicTacToe_GUI.h"

void dessin_jeu_complet_TicTacToe(){
	dessin_TicTacToe();
	dessin_scores(m_score_1_TicTacToe, m_score_2_TicTacToe);
	if(m_panneau_joueur_courant_TicTacToe == FALSE_TICTACTOE)dessin_joueur(1);
	else dessin_joueur(2);
	dessin_pion();
}

void dessin_TicTacToe(){
	LCD_Clear(LCD_COLOR_WHITE);
	LCD_DrawFullRect(114,141,135,3, LCD_COLOR_BLACK, LCD_COLOR_BLACK);
	LCD_DrawFullRect(114,187,135,3, LCD_COLOR_BLACK, LCD_COLOR_BLACK);
	LCD_DrawFullRect(157,98,3,135, LCD_COLOR_BLACK, LCD_COLOR_BLACK);
	LCD_DrawFullRect(203,98,3,135, LCD_COLOR_BLACK, LCD_COLOR_BLACK);
	LCD_DrawFullRect(39,0,3,240, 0x2589, 0x2589);
	LCD_DrawFullRect(42,39,320-42,3, 0xfbe4, 0xfbe4);
	LCD_SetFont(&Font12x12);
	char string_tictactoe[] = "Tic Tac Toe";
	LCD_DisplayStringLine(LINE(2)-2, COLUMN(10), (uint8_t *)string_tictactoe, 0xfbe4, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	char string_Q[] = "Q";
	char string_U[] = "U";
	char string_I[] = "I";
	char string_T[] = "T";
	char string_TT[] = "T";
	char string_E[] = "E";
	char string_R[] = "R";
	LCD_DisplayStringLine(LINE(4), COLUMN(1)+4, (uint8_t *)string_Q, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(6), COLUMN(1)+4, (uint8_t *)string_U, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(8), COLUMN(1)+6, (uint8_t *)string_I, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(10), COLUMN(1)+4, (uint8_t *)string_T, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(12), COLUMN(1)+4, (uint8_t *)string_TT, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(14), COLUMN(1)+4, (uint8_t *)string_E, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(16), COLUMN(1)+4, (uint8_t *)string_R, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
}

void dessin_pion(){
	int x,y=0;
	for(y=0;y<3;y++){
		for(x=0;x<3;x++){
			if(m_panneau_TicTacToe[x][y].m_Position.m_x == -1 || m_panneau_TicTacToe[x][y].m_Position.m_y == -1){
			}else{
				switch(m_panneau_TicTacToe[x][y].m_Type){
				case X:
					if(x==0&&y==0)dessin_croix(croix_a);
					if(x==1&&y==0)dessin_croix(croix_b);
					if(x==2&&y==0)dessin_croix(croix_c);
					if(x==0&&y==1)dessin_croix(croix_d);
					if(x==1&&y==1)dessin_croix(croix_e);
					if(x==2&&y==1)dessin_croix(croix_f);
					if(x==0&&y==2)dessin_croix(croix_g);
					if(x==1&&y==2)dessin_croix(croix_h);
					if(x==2&&y==2)dessin_croix(croix_i);
					break;
				default: //Case 0
					if(x==0&&y==0)dessin_cercle(cercle_a);
					if(x==1&&y==0)dessin_cercle(cercle_b);
					if(x==2&&y==0)dessin_cercle(cercle_c);
					if(x==0&&y==1)dessin_cercle(cercle_d);
					if(x==1&&y==1)dessin_cercle(cercle_e);
					if(x==2&&y==1)dessin_cercle(cercle_f);
					if(x==0&&y==2)dessin_cercle(cercle_g);
					if(x==1&&y==2)dessin_cercle(cercle_h);
					if(x==2&&y==2)dessin_cercle(cercle_i);
					break;
				}
			}
		}
	}
}

void dessin_cercle(Cercle_GUI cercle){
	LCD_DrawCircle(cercle.point.x, cercle.point.y, cercle.rayon, 0xf8a4);
}

void dessin_croix(Croix_GUI croix){
	LCD_DrawUniLine(croix.droite_A.point_A.x,croix.droite_A.point_A.y, croix.droite_A.point_B.x,croix.droite_A.point_B.y, 0x9eee);
	LCD_DrawUniLine(croix.droite_B.point_A.x,croix.droite_B.point_A.y, croix.droite_B.point_B.x,croix.droite_B.point_B.y, 0x9eee);
}

void dessin_scores(unsigned int score_1, unsigned int score_2){
	char string_score_1[20] = "Score joueur 1 : ";
	char string_score1[2] = "";
	char string_score_2[20] = "Score joueur 2 : ";
	char string_score2[2] = "";
	itoa(score_1,string_score1,10);
	itoa(score_2,string_score2,10);
	strcat(string_score_1,string_score1);
	strcat(string_score_2,string_score2);
	LCD_SetFont(&Font8x8);
	LCD_DisplayStringLine(LINE(7)-2, COLUMN(6), (uint8_t *)string_score_1, 0xe454, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(10)+0.5, COLUMN(6), (uint8_t *)string_score_2, 0xe454, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
}

void dessin_joueur(unsigned int joueur){
	char string_joueur[2] = "";
	char string_default[17]= "Tour du joueur ";
	itoa(joueur,string_joueur,10);
	strcat(string_default,string_joueur);
	LCD_SetFont(&Font8x8);
	LCD_DisplayStringLine(LINE(8)+3, COLUMN(6), (uint8_t *)string_default, 0xfea8, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
}

void test_dessin_TicTacToe(){
	//test_dessin_cercle();
	//test_dessin_croix();
	dessin_cercle(cercle_a);
	dessin_croix(croix_b);
	dessin_croix(croix_c);
	dessin_cercle(cercle_d);
	dessin_cercle(cercle_e);
	dessin_croix(croix_h);
	dessin_croix(croix_i);
	dessin_scores(100,5000);
	dessin_joueur(1);
	delay(10000);
	allumerled();
}

void test_dessin_cercle(){
	dessin_cercle(cercle_a);
	dessin_cercle(cercle_b);
	dessin_cercle(cercle_c);
	dessin_cercle(cercle_d);
	dessin_cercle(cercle_e);
	dessin_cercle(cercle_f);
	dessin_cercle(cercle_g);
	dessin_cercle(cercle_h);
	dessin_cercle(cercle_i);
}

void test_dessin_croix(){
	dessin_croix(croix_a);
	dessin_croix(croix_b);
	dessin_croix(croix_c);
	dessin_croix(croix_d);
	dessin_croix(croix_e);
	dessin_croix(croix_f);
	dessin_croix(croix_g);
	dessin_croix(croix_h);
	dessin_croix(croix_i);
}
