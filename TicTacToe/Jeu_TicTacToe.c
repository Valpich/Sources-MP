/****************************************************
 *  Jeu_TicTacToe.c
 *  Created on: oct.-2015                    
 *  Implementation of the Class Jeu_TicTacToe
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Jeu_TicTacToe.h"

int jeu_lancer_TicTacToe(){
	scores_init_TicTacToe();
	m_exit_TicTacToe = FALSE_TICTACTOE;
	setjmp(buf_TicTacToe);
	if(m_exit_TicTacToe == TRUE_TICTACTOE){
		delay(100);
		return 1;
	}
	jouer_des_parties_TicTacToe();
	return 0;
}

int jouer_des_tours_TicTacToe(){
	int fin_de_partie = -1;
	static int premier_tour=0;
	Pion_TicTacToe pion;
	Position_TicTacToe position;
	dessin_jeu_complet_TicTacToe();
	do{
		if(premier_tour!=0)panneau_changer_joueur_TicTacToe();
		else premier_tour=1;
		do{
			position = choisir_position_TicTacToe();
		}while(position.m_x == -1 || position.m_y == -1);
		if(m_panneau_joueur_courant_TicTacToe == FALSE_TICTACTOE)
			pion.m_Type = m_joueur_pion_1_TicTacToe;
		else
			pion.m_Type = m_joueur_pion_2_TicTacToe;
		panneau_ajouter_pion_TicTacToe(pion,position.m_x,position.m_y);
		dessin_jeu_complet_TicTacToe();
		fin_de_partie = panneau_test_fin_de_jeu_TicTacToe();
		if(fin_de_partie!=0)delay(1000);
	}while(fin_de_partie == 0);
	return fin_de_partie;
}

void jouer_des_parties_TicTacToe(){
	while(1){
		int gagnant = -1;
		panneau_init_TicTacToe();
		choisir_joueur_TicTacToe();
		joueur_init_TicTacToe();
		gagnant = jouer_des_tours_TicTacToe();
		if(gagnant == 1) m_score_1_TicTacToe +=3;
		if(gagnant == 2) m_score_2_TicTacToe +=3;
		if(gagnant == 3){
			m_score_1_TicTacToe ++;
			m_score_2_TicTacToe ++;
		}
	}
}
