/****************************************************
 *  Joueur_TicTacToe.c
 *  Created on: oct.-2015                    
 *  Implementation of the Class Joueur
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Joueur_TicTacToe.h"

void scores_init_TicTacToe(){
	m_score_1_TicTacToe = 0;
	m_score_2_TicTacToe = 0;
}

void joueur_init_TicTacToe(){
	if(m_panneau_joueur_courant_TicTacToe == FALSE_TICTACTOE){
		m_joueur_pion_1_TicTacToe = choisir_type_pion_TicTacToe();
		m_joueur_pion_2_TicTacToe = !m_joueur_pion_1_TicTacToe;
	}else{
		m_joueur_pion_2_TicTacToe = choisir_type_pion_TicTacToe();
		m_joueur_pion_1_TicTacToe = !m_joueur_pion_2_TicTacToe;
	}
}
