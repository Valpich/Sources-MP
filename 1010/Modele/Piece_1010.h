
/** 
 * \file Piece_1010.h
 * \brief Defini une piece du jeu 1010.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(PIECE_1010_H)
#define PIECE_1010_H


#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "Type_1010.h"
#include "Element_1010.h"
#include "Random_1010.h"

/**
 * \struct Piece_1010
 * \brief Definie la structure Piece_1010.
 */
typedef struct Piece_1010{
	Type_1010 m_Type;    /*!< Le type de la piece */
	unsigned int m_taille;	/*!< La taille de la piece */
}Piece_1010;

/**
 * \fn void creation_piece_1010();
 * \brief Retourne une nouvelle piece créée aléatoirement.
 * \param La piece nouvellement créée.
 */
void piece_creation_1010(Piece_1010 * piece);

#ifdef __cplusplus
}
#endif


#endif /*!defined(PIECE_1010_H)*/

