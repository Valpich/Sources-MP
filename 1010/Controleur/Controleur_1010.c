/****************************************************
 *  controleur_1010.c                                         
 *  Created on: oct.-2015                     
 *  Implementation of the Class controleur       
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "controleur_1010.h"

void choisir_position_1010(Piece_1010 piece){
	if(panneau_test_fin_de_jeu_1010(piece) == TRUE_1010)return;
	Position_1010 position ={-1,-1};
	uint16_t x = 0,y = 0;
	Bool_1010 appuye = FALSE_1010;
	do{
		appuye = FALSE_1010;
		while(appuye == FALSE_1010)appuye = TS_Get_Touch(&x, &y);
		delay(100);
		int i,j;
		for(j=0;j<10;j++){
			for(i=0;i<10;i++){
				if(x>=114+i*13 && x<114+i*13+12)position.m_x = i;
				if(y>=98+13*j && y<98+13*j+11)position.m_y = j;
			}
		}
		if(x<=39)choisir_quitter_jeu_1010();
	}while( panneau_test_ajout_piece_1010(piece, position.m_x, position.m_y) == FALSE_1010);
	panneau_ajouter_piece_1010(piece,position.m_x,position.m_y);
}

int choisir_piece_1010(){
	int choix = -1;
	uint16_t x = 0,y = 0;
	Bool_1010 appuye = FALSE_1010;
	do{
		appuye = FALSE_1010;
		while(appuye == FALSE_1010)appuye = TS_Get_Touch(&x, &y);
		delay(100);
		if(x>=COLUMN(34) && x < COLUMN(34)+20){
			if(y>=LINE(12) && y <LINE(12)+20)choix = 0;
		}
		if(x>=COLUMN(34) && x < COLUMN(34)+20){
			if(y>=LINE(18) && y <LINE(18)+20)choix = 1;
		}
		if(x>=COLUMN(34) && x < COLUMN(34)+20){
			if(y>=LINE(24) && y <LINE(24)+20)choix = 2;
		}
		if(x<=39)choisir_quitter_jeu_1010();
	}while(choix == -1);
	return choix;
}

void choisir_quitter_jeu_1010(){
	m_exit_1010 = TRUE_1010;
	longjmp(buf_1010,1);
}
