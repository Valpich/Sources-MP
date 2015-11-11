/****************************************************
 *  Pion_TicTacToe.c
 *  Created on: oct.-2015                     
 *  Implementation of the Class Pion      
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Pion_TicTacToe.h"

Pion_TicTacToe creation_pion(Type_TicTacToe m_Type){
    Pion_TicTacToe pion;
    pion.m_Type = m_Type;
    pion.m_Position.m_x = -1;
    pion.m_Position.m_y = -1;
    return pion;
}