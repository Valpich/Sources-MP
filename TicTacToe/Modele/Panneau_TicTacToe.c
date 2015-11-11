/****************************************************
 *  Panneau_TicTacToe.c
 *  Created on: oct.-2015                    
 *  Implementation of the Class Panneau
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Panneau_TicTacToe.h"

void panneau_init_TicTacToe(){
    int i,j;
    Pion_TicTacToe pion;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            m_panneau_TicTacToe[i][j] = pion;
            m_panneau_TicTacToe[i][j].m_Position.m_x = -1;
            m_panneau_TicTacToe[i][j].m_Position.m_y = -1;
        }
    }
}

void panneau_ajouter_pion_TicTacToe(Pion_TicTacToe pion, int x, int y){
    if(panneau_test_ajout_pion_TicTacToe(x,y)){
        m_panneau_TicTacToe[x][y] = pion;
        m_panneau_TicTacToe[x][y].m_Position.m_x = x;
        m_panneau_TicTacToe[x][y].m_Position.m_y = y;
    }
}

Bool_TicTacToe panneau_test_ajout_pion_TicTacToe(int x, int y){
    if(m_panneau_TicTacToe[x][y].m_Position.m_x == -1 || m_panneau_TicTacToe[x][y].m_Position.m_y == -1)return TRUE_TICTACTOE;
    return FALSE_TICTACTOE;
}

int panneau_test_fin_de_jeu_TicTacToe(){
    int x,y;
    //Colonne 0
    if(m_panneau_TicTacToe[0][0].m_Position.m_x != -1 && m_panneau_TicTacToe[0][1].m_Position.m_x != -1 && m_panneau_TicTacToe[0][2].m_Position.m_x != -1){
        if(m_panneau_TicTacToe[0][0].m_Type == m_panneau_TicTacToe[0][1].m_Type && m_panneau_TicTacToe[0][0].m_Type == m_panneau_TicTacToe[0][2].m_Type ){
            if(m_panneau_TicTacToe[0][0].m_Type == m_joueur_pion_1_TicTacToe)return 1;
            return 2;
        }
    }
    //Colonne 1
    if(m_panneau_TicTacToe[1][0].m_Position.m_x != -1 && m_panneau_TicTacToe[1][1].m_Position.m_x != -1 && m_panneau_TicTacToe[1][2].m_Position.m_x != -1){
        if(m_panneau_TicTacToe[1][0].m_Type == m_panneau_TicTacToe[1][1].m_Type && m_panneau_TicTacToe[1][0].m_Type == m_panneau_TicTacToe[1][2].m_Type ){
            if(m_panneau_TicTacToe[1][0].m_Type == m_joueur_pion_1_TicTacToe)return 1;
            return 2;
        }
    }
    //Colonne 2
    if(m_panneau_TicTacToe[2][0].m_Position.m_x != -1 && m_panneau_TicTacToe[2][1].m_Position.m_x != -1 && m_panneau_TicTacToe[2][2].m_Position.m_x != -1){
        if(m_panneau_TicTacToe[2][0].m_Type == m_panneau_TicTacToe[2][1].m_Type && m_panneau_TicTacToe[2][0].m_Type == m_panneau_TicTacToe[2][2].m_Type ){
            if(m_panneau_TicTacToe[2][0].m_Type == m_joueur_pion_1_TicTacToe)return 1;
            return 2;
        }
    }
    //Ligne 0
    if(m_panneau_TicTacToe[0][0].m_Position.m_x != -1 && m_panneau_TicTacToe[1][0].m_Position.m_x != -1 && m_panneau_TicTacToe[2][0].m_Position.m_x != -1){
        if(m_panneau_TicTacToe[0][0].m_Type == m_panneau_TicTacToe[1][0].m_Type && m_panneau_TicTacToe[0][0].m_Type == m_panneau_TicTacToe[2][0].m_Type ){
            if(m_panneau_TicTacToe[0][0].m_Type == m_joueur_pion_1_TicTacToe)return 1;
            return 2;
        }
    }
    //Ligne 1
    if(m_panneau_TicTacToe[0][1].m_Position.m_x != -1 && m_panneau_TicTacToe[1][1].m_Position.m_x != -1 && m_panneau_TicTacToe[2][1].m_Position.m_x != -1){
        if(m_panneau_TicTacToe[0][1].m_Type == m_panneau_TicTacToe[1][1].m_Type && m_panneau_TicTacToe[0][1].m_Type == m_panneau_TicTacToe[2][1].m_Type ){
            if(m_panneau_TicTacToe[0][1].m_Type == m_joueur_pion_1_TicTacToe)return 1;
            return 2;
        }
    }
    //Ligne 2
    if(m_panneau_TicTacToe[0][2].m_Position.m_x != -1 && m_panneau_TicTacToe[1][2].m_Position.m_x != -1 && m_panneau_TicTacToe[2][2].m_Position.m_x != -1){
        if(m_panneau_TicTacToe[0][2].m_Type == m_panneau_TicTacToe[1][2].m_Type && m_panneau_TicTacToe[0][2].m_Type == m_panneau_TicTacToe[2][2].m_Type ){
            if(m_panneau_TicTacToe[0][2].m_Type == m_joueur_pion_1_TicTacToe)return 1;
            return 2;
        }
    }
    //Diagonale 0
    if(m_panneau_TicTacToe[0][0].m_Position.m_x != -1 && m_panneau_TicTacToe[1][1].m_Position.m_x != -1 && m_panneau_TicTacToe[2][2].m_Position.m_x != -1){
        if(m_panneau_TicTacToe[0][0].m_Type == m_panneau_TicTacToe[1][1].m_Type && m_panneau_TicTacToe[0][0].m_Type == m_panneau_TicTacToe[2][2].m_Type ){
            if(m_panneau_TicTacToe[0][0].m_Type == m_joueur_pion_1_TicTacToe)return 1;
            return 2;
        }
    }
    //Diagonale 1
    if(m_panneau_TicTacToe[0][2].m_Position.m_x != -1 && m_panneau_TicTacToe[1][1].m_Position.m_x != -1 && m_panneau_TicTacToe[2][0].m_Position.m_x != -1){
        if(m_panneau_TicTacToe[0][2].m_Type == m_panneau_TicTacToe[1][1].m_Type && m_panneau_TicTacToe[0][2].m_Type == m_panneau_TicTacToe[2][0].m_Type ){
            if(m_panneau_TicTacToe[0][2].m_Type == m_joueur_pion_1_TicTacToe)return 1;
            return 2;
        }
    }
    //Verification jeu non plein
    for(x=0;x<3;x++){
        for(y=0;y<3;y++){
            if(m_panneau_TicTacToe[x][y].m_Position.m_x == -1)return 0;
        }
    }
    //Egalitée
    return 3;
}

void panneau_changer_joueur_TicTacToe(){
    m_panneau_joueur_courant_TicTacToe = ! m_panneau_joueur_courant_TicTacToe;
}