/****************************************************
 *  Element_1010.c                                         
 *  Created on: oct.-2015                    
 *  Implementation of the Class Element       
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Element_1010.h"


Element_1010 element_creation_1010(){
	Element_1010 tmp;
	tmp.m_Couleur = DEFAULT_COLOR;
	tmp.m_Position.m_x = DEFAULT_POS_X;
	tmp.m_Position.m_y = DEFAULT_POS_Y;
	tmp.m_a_supprimer = FALSE_1010;
	return tmp;
}


