/****************************************************
 *  Piece_1010.c
 *  Created on: oct.-2015                     
 *  Implementation of the Class Piece       
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Piece_1010.h"


void piece_creation_1010(Piece_1010 * piece){
	piece->m_Type = random_get_piece_1010();
	switch(piece->m_Type){
	case I:
		piece->m_taille =4;
		break;
	case J:
		piece->m_taille =4;
		break;
	case L:
		piece->m_taille =4;
		break;
	case O_Piece:
		piece->m_taille =4;
		break;
	case T:
		piece->m_taille =4;
		break;
	case S:
		piece->m_taille =4;
		break;
	case Z:
		piece->m_taille =4;
		break;
	case Un_Piece:
		piece->m_taille =1;
		break;
	case Deux_Piece:
		piece->m_taille =2;
		break;
	case Trois_Piece:
		piece->m_taille =3;
		break;
	case Cinq_Piece:
		piece->m_taille =5;
		break;
	case Neuf_Piece:
		piece->m_taille =9;
		break;
	default:
		piece->m_taille =0;
		break;
	}
}
