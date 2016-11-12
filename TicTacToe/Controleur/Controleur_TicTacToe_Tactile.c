/****************************************************
 *  controleur_TicTacToe_Tactile.c
 *  Created on: oct.-2015                     
 *  Implementation of the Class controleur       
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "controleur_TicTacToe_Tactile.h"

Position_TicTacToe choisir_position_TicTacToe(Position_TicTacToe position){
	uint16_t x = 0,y = 0;
	Position_TicTacToe position_false ={-1,-1};
	Bool_TicTacToe appuye = FALSE_TICTACTOE;
	while(appuye == FALSE_TICTACTOE)appuye = TS_Get_Touch(&x, &y);
	delay(100);
	if(x>=138){
		if(x<=156)position.m_x=0;
		else if(x<=201)position.m_x=1;
		else if(x<=248)position.m_x=2;
	}
	if(y>=98){
		if(y<=140)position.m_y=0;
		else if(y<=186)position.m_y=1;
		else if(y<=223)position.m_y=2;
	}
	if(x<=39)choisir_quitter_jeu_TicTacToe();
	if( panneau_test_ajout_pion_TicTacToe(position.m_x, position.m_y) == FALSE_TICTACTOE)return position_false;
	return position;
}

Type_TicTacToe choisir_type_pion_TicTacToe(){
	int x = -1;
	if(random_get_bool_TicTacToe() == TRUE_TICTACTOE)x=0;
	Type_TicTacToe tmp = 0;
	if(x == 0) return tmp;
	else return X;
}

void choisir_joueur_TicTacToe(){
	m_panneau_joueur_courant_TicTacToe = random_get_bool_TicTacToe();
}

void choisir_quitter_jeu_TicTacToe(){
	m_exit_TicTacToe = TRUE_TICTACTOE;
	longjmp(buf_TicTacToe,1);
}
