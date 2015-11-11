/****************************************************
 *  Controlleur_TicTacToe_Tactile.c
 *  Created on: oct.-2015                     
 *  Implementation of the Class Controlleur       
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Controlleur_TicTacToe_Tactile.h"

Position_TicTacToe choisir_position_TicTacToe(Position_TicTacToe position){
    Position_TicTacToe position_false={-1,-1};
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
