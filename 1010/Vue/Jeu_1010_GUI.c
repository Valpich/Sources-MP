#include "Jeu_1010_GUI.h"

const int RELATIVE_ELEMENTS_COORDS_I_GUI[4][2] = {{0, 0},{0, -2},{0, -1},{0, 1}};
const int RELATIVE_ELEMENTS_COORDS_J_GUI[4][2] = {{0, 0},{-1, 0},{0, -1},{0, -2}};
const int RELATIVE_ELEMENTS_COORDS_L_GUI[4][2] = {{0, 0},{0, -1},{0, -2},{1, 0}};
const int RELATIVE_ELEMENTS_COORDS_O_GUI[4][2] = {{0, 0},{0, -1},{1, -1},{1, 0}};
const int RELATIVE_ELEMENTS_COORDS_S_GUI[4][2] = {{0, 0},{-1, 0},{0, -1},{1, -1}};
const int RELATIVE_ELEMENTS_COORDS_T_GUI[4][2] = {{0, 0},{-1, 0},{1, -1},{1, 0}};
const int RELATIVE_ELEMENTS_COORDS_Z_GUI[4][2] = {{0, 0},{-1, 0},{1, -1},{1, 0}};
const int RELATIVE_ELEMENTS_COORDS_UN_PIECE_GUI[1][2] = {{0, 0}};
const int RELATIVE_ELEMENTS_COORDS_DEUX_PIECE_GUI[2][2] = {{0, 0},{1, 0}};
const int RELATIVE_ELEMENTS_COORDS_TROIS_PIECE_GUI[3][2] = {{0, 0},{0, 1},{0, -1}};
const int RELATIVE_ELEMENTS_COORDS_CINQ_PIECE_GUI[5][2] = {{0, 0},{0, -2},{0, -1},{0, 1},{0,2}};
const int RELATIVE_ELEMENTS_COORDS_NEUF_PIECE_GUI[9][2] = {{0, 0},{1, 1},{-1, -1},{-1, 0},{0, -1},{1, -1},{-1, 1},{1, 0},{0, 1},};

void dessin_jeu_complet_1010(){
	dessin_1010();
	dessin_score(m_score);
	dessin_pieces();
}

void dessin_1010(){
	LCD_Clear(LCD_COLOR_WHITE);
	LCD_DrawFullRect(39,0,3,240, 0x2589, 0x2589);
	LCD_DrawFullRect(42,39,320-42,3, 0xfbe4, 0xfbe4);
	LCD_SetFont(&Font12x12);
	char string_tictactoe[] = "  1010    ";
	LCD_DisplayStringLine(LINE(2)-2, COLUMN(10), (uint8_t *)string_tictactoe, 0xfbe4, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	char string_Q[] = "Q";
	char string_U[] = "U";
	char string_I[] = "I";
	char string_T[] = "T";
	char string_TT[] = "T";
	char string_E[] = "E";
	char string_R[] = "R";
	int i,j;
	for(j=0;j<10;j++){
		for(i=0;i<10;i++){
			LCD_DrawFullRect(113+i*13, 97+13*j,14,13, 0x0000,0xffff);
		}
	}
	LCD_DisplayStringLine(LINE(4), COLUMN(1)+4, (uint8_t *)string_Q, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(6), COLUMN(1)+4, (uint8_t *)string_U, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(8), COLUMN(1)+6, (uint8_t *)string_I, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(10), COLUMN(1)+4, (uint8_t *)string_T, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(12), COLUMN(1)+4, (uint8_t *)string_TT, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(14), COLUMN(1)+4, (uint8_t *)string_E, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(16), COLUMN(1)+4, (uint8_t *)string_R, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
}

void dessin_pieces(){
	int i,j;
	for(j=0;j<10;j++){
		for(i=0;i<10;i++){
			if(m_panneau[i][j].m_Position.m_x == i && m_panneau[i][j].m_Position.m_y == j){
				switch(m_panneau[i][j].m_Couleur){
				case JAUNE:
					LCD_DrawFullRect(114+i*13, 98+13*j,12,11,0xffe0, 0xffe0);
					break;
				case ROUGE :
					LCD_DrawFullRect(114+i*13, 98+13*j,12,11,0xf800, 0xf800);
					break;
				case BLEU :
					LCD_DrawFullRect(114+i*13, 98+13*j,12,11,0x001f, 0x001f);
					break;
				case VERT :
					LCD_DrawFullRect(114+i*13, 98+13*j,12,11,0x07e0, 0x07e0);
					break;
				case CYAN :
					LCD_DrawFullRect(114+i*13, 98+13*j,12,11,0x07ff, 0x07ff);
					break;
				case VIOLET :
					LCD_DrawFullRect(114+i*13, 98+13*j,12,11,0xf81f, 0xf81f);
					break;
				case ORANGE :
					LCD_DrawFullRect(114+i*13, 98+13*j,12,11,0xfd20, 0xfd20);
					break;
				case NOIR :
					LCD_DrawFullRect(114+i*13, 98+13*j,12,11,0x0000, 0x0000);
					break;
				default:
					LCD_DrawFullRect(114+i*13, 98+13*j,12,11,0x2847, 0x5748);
					break;
				}
			}
		}
	}
}

void dessin_carre(Carre_GUI carre, uint16_t couleur){
	LCD_DrawFullRect(carre.x, carre.y, carre.width,carre.height, couleur, couleur);
}

void dessin_score(unsigned int score_1){
	char string_score_1[25] = "Votre score est de : ";
	char string_score1[2] = "";
	itoa(score_1,string_score1,10);
	strcat(string_score_1,string_score1);
	LCD_SetFont(&Font8x8);
	LCD_DisplayStringLine(LINE(7)-2, COLUMN(6), (uint8_t *)string_score_1, 0xe454, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
}

void dessin_piece(Piece_1010 piece, int numero){
	int i;
	switch(piece.m_Type){
	case I:
		for(i=0;i<piece.m_taille;i++){
			LCD_DrawFullRect(114+ RELATIVE_ELEMENTS_COORDS_I_GUI[i][0]*13-40, 98+13*RELATIVE_ELEMENTS_COORDS_I_GUI[i][1]+numero*60,12,11,0x0000, 0x001f);
		}
		break;
	case J:
		for(i=0;i<piece.m_taille;i++){
			LCD_DrawFullRect(114+RELATIVE_ELEMENTS_COORDS_J_GUI[i][0]*13-40, 98+13*RELATIVE_ELEMENTS_COORDS_J_GUI[i][1]+numero*60,12,11,0x0000, 0xffe0);
		}
		break;
	case L:
		for(i=0;i<piece.m_taille;i++){
			LCD_DrawFullRect(114+RELATIVE_ELEMENTS_COORDS_L_GUI[i][0]*13-40, 98+13*RELATIVE_ELEMENTS_COORDS_L_GUI[i][1]+numero*60,12,11,0x0000, 0xf800);
		}
		break;
	case O_Piece:
		for(i=0;i<piece.m_taille;i++){
			LCD_DrawFullRect(114+RELATIVE_ELEMENTS_COORDS_O_GUI[i][0]*13-40, 98+13*RELATIVE_ELEMENTS_COORDS_O_GUI[i][1]+numero*60,12,11,0x0000, 0x07e0);
		}
		break;
	case T:
		for(i=0;i<piece.m_taille;i++){
			LCD_DrawFullRect(114+RELATIVE_ELEMENTS_COORDS_T_GUI[i][0]*13-40, 98+13*RELATIVE_ELEMENTS_COORDS_T_GUI[i][1]+numero*60,12,11,0x0000, 0xf81f);
		}
		break;
	case S:
		for(i=0;i<piece.m_taille;i++){
			LCD_DrawFullRect(114+RELATIVE_ELEMENTS_COORDS_S_GUI[i][0]*13-40, 98+13*RELATIVE_ELEMENTS_COORDS_S_GUI[i][1]+numero*60,12,11,0x0000, 0x07ff);
		}
		break;
	case Z:
		for(i=0;i<piece.m_taille;i++){
			LCD_DrawFullRect(114+RELATIVE_ELEMENTS_COORDS_Z_GUI[i][0]*13-40, 98+13*RELATIVE_ELEMENTS_COORDS_Z_GUI[i][1]+numero*60,12,11,0x0000, 0xfd20);
		}
		break;
	case Un_Piece:
		for(i=0;i<piece.m_taille;i++){
			LCD_DrawFullRect(114+RELATIVE_ELEMENTS_COORDS_UN_PIECE_GUI[i][0]*13-40, 98+13*RELATIVE_ELEMENTS_COORDS_UN_PIECE_GUI[i][1]+numero*60,12,11,0x0000, 0x07ff);
		}
		break;
	case Deux_Piece:
		for(i=0;i<piece.m_taille;i++){
			LCD_DrawFullRect(114+RELATIVE_ELEMENTS_COORDS_DEUX_PIECE_GUI[i][0]*13-40, 98+13*RELATIVE_ELEMENTS_COORDS_DEUX_PIECE_GUI[i][1]+numero*60,12,11,0x0000, 0xffe0);
		}
		break;
	case Trois_Piece:
		for(i=0;i<piece.m_taille;i++){
			LCD_DrawFullRect(114+RELATIVE_ELEMENTS_COORDS_TROIS_PIECE_GUI[i][0]*13-40, 98+13*RELATIVE_ELEMENTS_COORDS_TROIS_PIECE_GUI[i][1]+numero*60,12,11,0x0000, 0xf81f);
		}
		break;
	case Cinq_Piece:
		for(i=0;i<piece.m_taille;i++){
			LCD_DrawFullRect(114+RELATIVE_ELEMENTS_COORDS_CINQ_PIECE_GUI[i][0]*13-40, 98+13*RELATIVE_ELEMENTS_COORDS_CINQ_PIECE_GUI[i][1]+numero*60,12,11,0x0000, 0x07e0);
		}
		break;
	case Neuf_Piece:
		for(i=0;i<piece.m_taille;i++){
			LCD_DrawFullRect(114+RELATIVE_ELEMENTS_COORDS_NEUF_PIECE_GUI[i][0]*13-40, 98+13*RELATIVE_ELEMENTS_COORDS_NEUF_PIECE_GUI[i][1]+numero*60,12,11,0x0000, 0xfd20);
		}
		break;
	default:
		break;
	}
}

void afficher_defaite(){
	LCD_Clear(LCD_COLOR_WHITE);
	LCD_SetFont(&Font12x12);
	char string_perdu[28] = "Vous avez perdu !";
	char string_score_1[28] = "Avec un score de : ";
	char string_quitter[28] = "Appuyer pour quitter";
	char string_score1[4] = "";
	itoa(m_score,string_score1,10);
	strcat(string_score_1,string_score1);
	LCD_DisplayStringLine(LINE(7), COLUMN(3), (uint8_t *)string_perdu, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(7)+30, COLUMN(3), (uint8_t *)string_score_1, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(LINE(7)+60, COLUMN(3), (uint8_t *)string_quitter, 0x3a59, LCD_COLOR_WHITE,LCD_NO_DISPLAY_ON_UART);
}

void dessin_choix(int choix){
	char string_1[] = "1";
	char string_2[] = "2";
	char string_3[] = "3";
	LCD_SetFont(&Font8x8);
	if(choix == 0){
		LCD_DrawFullRect(COLUMN(34),LINE(12),20,20,0xffe0, 0xffe0);
		LCD_DisplayStringLine(LINE(12)+6, COLUMN(34)+6, (uint8_t *)string_1, 0x3a59, 0xffe0,LCD_NO_DISPLAY_ON_UART);
	}
	if(choix == 1){
		LCD_DrawFullRect(COLUMN(34),LINE(18),20,20,0xffe0, 0xffe0);
		LCD_DisplayStringLine(LINE(18)+6, COLUMN(34)+6, (uint8_t *)string_2, 0x3a59, 0xffe0,LCD_NO_DISPLAY_ON_UART);
	}
	if(choix == 2){
		LCD_DrawFullRect(COLUMN(34), LINE(24),20,20,0xffe0, 0xffe0);
		LCD_DisplayStringLine(LINE(24)+6, COLUMN(34)+6, (uint8_t *)string_3, 0x3a59, 0xffe0,LCD_NO_DISPLAY_ON_UART);
	}
}

void dessin_choix_selectionner(int choix){
	char string_1[] = "1";
	char string_2[] = "2";
	char string_3[] = "3";
	LCD_SetFont(&Font8x8);
	if(choix == 0){
		LCD_DrawFullRect(COLUMN(34),LINE(12),20,20,0xfbe4,0xfbe4);
		LCD_DisplayStringLine(LINE(12)+6, COLUMN(34)+6, (uint8_t *)string_1, 0x3a59, 0xfbe4,LCD_NO_DISPLAY_ON_UART);
	}
	if(choix == 1){
		LCD_DrawFullRect(COLUMN(34),LINE(18),20,20,0xfbe4,0xfbe4);
		LCD_DisplayStringLine(LINE(18)+6, COLUMN(34)+6, (uint8_t *)string_2, 0x3a59, 0xfbe4,LCD_NO_DISPLAY_ON_UART);
	}
	if(choix == 2){
		LCD_DrawFullRect(COLUMN(34), LINE(24),20,20,0xfbe4,0xfbe4);
		LCD_DisplayStringLine(LINE(24)+6, COLUMN(34)+6, (uint8_t *)string_3, 0x3a59, 0xfbe4,LCD_NO_DISPLAY_ON_UART);
	}
}
