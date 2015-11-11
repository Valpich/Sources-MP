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
    if(m_exit_TicTacToe == TRUE_TICTACTOE) return 1;
    jouer_des_parties_TicTacToe();
    return 0;
}

int jouer_des_tours_TicTacToe(){
    int fin_de_partie = -1;
    static int premier_tour=0;
    Pion_TicTacToe pion;
    Position_TicTacToe position;
    uint16_t x,y;
    bool_e appuye = FALSE;
    m_score_1_TicTacToe=2;
    m_score_2_TicTacToe=3;
    m_panneau_TicTacToe[0][1].m_Position.m_x=0;
    m_panneau_TicTacToe[0][1].m_Position.m_y=1;
    m_panneau_TicTacToe[0][1].m_Type=0;
    dessin_jeu_complet_TicTacToe();
    do{
        if(premier_tour!=0)panneau_changer_joueur_TicTacToe();
        else premier_tour=1;
        do{
        	appuye = TS_Get_Touch(&x, &y);
        	if(x>100)position.m_x=2;
        	if(y>100)position.m_y=2;
        	//position = choisir_position_TicTacToe(position);
        	if(appuye == TRUE)goto test;
        }while(position.m_x!=-1 && position.m_y!=-1);
        test:
    	LCD_Clear(LCD_COLOR_WHITE);
        if(m_panneau_joueur_courant_TicTacToe == FALSE_TICTACTOE)
            pion.m_Type = m_joueur_pion_1_TicTacToe;
        else
            pion.m_Type = m_joueur_pion_2_TicTacToe;
        panneau_ajouter_pion_TicTacToe(pion,position.m_x,position.m_y);
        while(1);
        fin_de_partie = panneau_test_fin_de_jeu_TicTacToe();
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
