
/** \file Pion_TicTacToe.h
 * \brief Defini un pion du jeu TicTacToe.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(PION_TICTACTOE_H)
#define PION_TICTACTOE_H


#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "Type_TicTacToe.h"
#include "Position_TicTacToe.h"

/**
 * \struct Pion_TicTacToe
 * \brief Definie la structure Pion_TicTacToe
 */
typedef struct Pion_TicTacToe{
	Type_TicTacToe m_Type;            /*!< Le type du pion */
	Position_TicTacToe m_Position;     /*!< La position du pion */
}Pion_TicTacToe;

/**
 * \fn Pion_TicTacToe creation_pion_TicTacToe(Type_TicTacToe m_Type)
 * \brief Retourne un pion.
 * \return Le pion nouvellement créé.
 */
Pion_TicTacToe creation_pion_TicTacToe(Type_TicTacToe m_Type);

#ifdef __cplusplus
}
#endif


#endif /*!defined(PION_TICTACTOE_H)*/
