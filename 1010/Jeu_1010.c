/****************************************************
 *  Jeu_1010.c                                         
 *  Created on: oct.-2015                    
 *  Implementation of the Class Jeu_1010       
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Jeu_1010.h"

int jeu_1010_lancer(){
    panneau_init_1010();
    Piece_1010 piece;
    int x,y;
    affichage_panneau_to_ascii_1010();
    piece = choisir_piece_1010();
    do{
        affichage_piece_to_string_1010(piece);
        x = choisir_x_1010();
        y = choisir_y_1010();
        panneau_ajouter_piece_1010(piece,x,y);
        panneau_supprimer_les_lignes_1010();
        affichage_panneau_to_ascii_1010();
        affichage_score_1010(m_score);
        piece = choisir_piece_1010();
    }while(panneau_test_fin_de_jeu_1010(piece) == FALSE_1010);
    affichage_defaite_1010(m_score);
    return 0;
} 

