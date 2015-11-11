/****************************************************
 *  Controlleur_1010.c                                         
 *  Created on: oct.-2015                     
 *  Implementation of the Class Controlleur       
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Controlleur_1010.h"

Piece_1010  choisir_piece_1010(){
    Piece_1010 piece;
    puts("Saisir le type de la piece :");
    scanf("%d",&piece.m_Type);
    return piece;
}

int  choisir_x_1010(){
    int x = 0;
    puts("Saisir x :");
    scanf("%d",&x);
    return x;
}

int  choisir_y_1010(){
    int y = 0;
    puts("Saisir y :");
    scanf("%d",&y);
    return y;
}
