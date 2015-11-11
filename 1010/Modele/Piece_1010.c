/****************************************************
 *  Piece_1010.c
 *  Created on: oct.-2015                     
 *  Implementation of the Class Piece       
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Piece_1010.h"


Piece_1010 piece_creation_1010(){
    Piece_1010 tmp;
    tmp.m_Type = random_get_piece_1010();
    return tmp;
}

