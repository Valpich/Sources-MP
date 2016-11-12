/****************************************************
 *  Panneau_1010.c
 *  Created on: oct.-2015                    
 *  Implementation of the Class Panneau   
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Panneau_1010.h"

const int RELATIVE_ELEMENTS_COORDS_I[4][2] = {{0, 0},{0, -2},{0, -1},{0, 1}};
const int RELATIVE_ELEMENTS_COORDS_J[4][2] = {{0, 0},{-1, 0},{0, -1},{0, -2}};
const int RELATIVE_ELEMENTS_COORDS_L[4][2] = {{0, 0},{0, -1},{0, -2},{1, 0}};
const int RELATIVE_ELEMENTS_COORDS_O[4][2] = {{0, 0},{0, -1},{1, -1},{1, 0}};
const int RELATIVE_ELEMENTS_COORDS_S[4][2] = {{0, 0},{-1, 0},{0, -1},{1, -1}};
const int RELATIVE_ELEMENTS_COORDS_T[4][2] = {{0, 0},{-1, 0},{1, -1},{1, 0}};
const int RELATIVE_ELEMENTS_COORDS_Z[4][2] = {{0, 0},{-1, 0},{1, -1},{1, 0}};
const int RELATIVE_ELEMENTS_COORDS_UN_PIECE[1][2] = {{0, 0}};
const int RELATIVE_ELEMENTS_COORDS_DEUX_PIECE[2][2] = {{0, 0},{1, 0}};
const int RELATIVE_ELEMENTS_COORDS_TROIS_PIECE[3][2] = {{0, 0},{0, 1},{0, -1}};
const int RELATIVE_ELEMENTS_COORDS_CINQ_PIECE[5][2] = {{0, 0},{0, -2},{0, -1},{0, 1},{0,2}};
const int RELATIVE_ELEMENTS_COORDS_NEUF_PIECE[9][2] = {{0, 0},{1, 1},{-1, -1},{-1, 0},{0, -1},{1, -1},{-1, 1},{1, 0},{0, 1}};


void panneau_init_1010(){
	m_score = 0;
	int i = 0;
	int j = 0;
	for(i = 0;i<10;i++){
		for(j = 0;j<10;j++){
			m_panneau[i][j] = element_creation_1010();
		}
	}
}

void panneau_ajouter_piece_1010(Piece_1010 piece, int x, int y){
	if(panneau_test_ajout_piece_1010(piece,x,y)==TRUE_1010){
		int i = 0;
		int tmp_x = x;
		int tmp_y = y;
		Couleur_1010 couleur;
		for(i=0;i<piece.m_taille;i++){
			tmp_x = x;
			tmp_y = y;
			switch(piece.m_Type){
			case I:
				tmp_x += RELATIVE_ELEMENTS_COORDS_I[i][0];
				tmp_y += RELATIVE_ELEMENTS_COORDS_I[i][1];
				couleur = BLEU;
				break;
			case J:
				tmp_x += RELATIVE_ELEMENTS_COORDS_J[i][0];
				tmp_y += RELATIVE_ELEMENTS_COORDS_J[i][1];
				couleur = JAUNE;
				break;
			case L:
				tmp_x += RELATIVE_ELEMENTS_COORDS_L[i][0];
				tmp_y += RELATIVE_ELEMENTS_COORDS_L[i][1];
				couleur = ROUGE;
				break;
			case O_Piece:
				tmp_x += RELATIVE_ELEMENTS_COORDS_O[i][0];
				tmp_y += RELATIVE_ELEMENTS_COORDS_O[i][1];
				couleur = VERT;
				break;
			case T:
				tmp_x += RELATIVE_ELEMENTS_COORDS_T[i][0];
				tmp_y += RELATIVE_ELEMENTS_COORDS_T[i][1];
				couleur = VIOLET;
				break;
			case S:
				tmp_x += RELATIVE_ELEMENTS_COORDS_S[i][0];
				tmp_y += RELATIVE_ELEMENTS_COORDS_S[i][1];
				couleur = CYAN;
				break;
			case Z:
				tmp_x += RELATIVE_ELEMENTS_COORDS_Z[i][0];
				tmp_y += RELATIVE_ELEMENTS_COORDS_Z[i][1];
				couleur = ORANGE;
				break;
			case Un_Piece:
				tmp_x += RELATIVE_ELEMENTS_COORDS_UN_PIECE[i][0];
				tmp_y += RELATIVE_ELEMENTS_COORDS_UN_PIECE[i][1];
				couleur = CYAN;
				break;
			case Deux_Piece:
				tmp_x += RELATIVE_ELEMENTS_COORDS_DEUX_PIECE[i][0];
				tmp_y += RELATIVE_ELEMENTS_COORDS_DEUX_PIECE[i][1];
				couleur = JAUNE;
				break;
			case Trois_Piece:
				tmp_x += RELATIVE_ELEMENTS_COORDS_TROIS_PIECE[i][0];
				tmp_y += RELATIVE_ELEMENTS_COORDS_TROIS_PIECE[i][1];
				couleur = VIOLET;
				break;
			case Cinq_Piece:
				tmp_x += RELATIVE_ELEMENTS_COORDS_CINQ_PIECE[i][0];
				tmp_y += RELATIVE_ELEMENTS_COORDS_CINQ_PIECE[i][1];
				couleur = VERT;
				break;
			case Neuf_Piece:
				tmp_x += RELATIVE_ELEMENTS_COORDS_NEUF_PIECE[i][0];
				tmp_y += RELATIVE_ELEMENTS_COORDS_NEUF_PIECE[i][1];
				couleur = ORANGE;
				break;
			default:
				puts("Type de piece inconnu");
				break;
			}
			m_panneau[tmp_x][tmp_y].m_Position.m_x = tmp_x;
			m_panneau[tmp_x][tmp_y].m_Position.m_y = tmp_y;
			m_panneau[tmp_x][tmp_y].m_Couleur = couleur;
		}
	}else{
		return;
	}
}

Bool_1010 panneau_test_ajout_piece_1010(Piece_1010 piece, int x, int y){
	int i = 0;
	int tmp_x = x;
	int tmp_y = y;
	for(i=0;i<piece.m_taille;i++){
		tmp_x = x;
		tmp_y = y;
		switch(piece.m_Type){
		case I:
			tmp_x += RELATIVE_ELEMENTS_COORDS_I[i][0];
			tmp_y += RELATIVE_ELEMENTS_COORDS_I[i][1];
			break;
		case J:
			tmp_x += RELATIVE_ELEMENTS_COORDS_J[i][0];
			tmp_y += RELATIVE_ELEMENTS_COORDS_J[i][1];
			break;
		case L:
			tmp_x += RELATIVE_ELEMENTS_COORDS_L[i][0];
			tmp_y += RELATIVE_ELEMENTS_COORDS_L[i][1];
			break;
		case O_Piece:
			tmp_x += RELATIVE_ELEMENTS_COORDS_O[i][0];
			tmp_y += RELATIVE_ELEMENTS_COORDS_O[i][1];
			break;
		case T:
			tmp_x += RELATIVE_ELEMENTS_COORDS_T[i][0];
			tmp_y += RELATIVE_ELEMENTS_COORDS_T[i][1];
			break;
		case S:
			tmp_x += RELATIVE_ELEMENTS_COORDS_S[i][0];
			tmp_y += RELATIVE_ELEMENTS_COORDS_S[i][1];
			break;
		case Z:
			tmp_x += RELATIVE_ELEMENTS_COORDS_Z[i][0];
			tmp_y += RELATIVE_ELEMENTS_COORDS_Z[i][1];
			break;
		case Un_Piece:
			tmp_x += RELATIVE_ELEMENTS_COORDS_UN_PIECE[i][0];
			tmp_y += RELATIVE_ELEMENTS_COORDS_UN_PIECE[i][1];
			break;
		case Deux_Piece:
			tmp_x += RELATIVE_ELEMENTS_COORDS_DEUX_PIECE[i][0];
			tmp_y += RELATIVE_ELEMENTS_COORDS_DEUX_PIECE[i][1];
			break;
		case Trois_Piece:
			tmp_x += RELATIVE_ELEMENTS_COORDS_TROIS_PIECE[i][0];
			tmp_y += RELATIVE_ELEMENTS_COORDS_TROIS_PIECE[i][1];
			break;
		case Cinq_Piece:
			tmp_x += RELATIVE_ELEMENTS_COORDS_CINQ_PIECE[i][0];
			tmp_y += RELATIVE_ELEMENTS_COORDS_CINQ_PIECE[i][1];
			break;
		case Neuf_Piece:
			tmp_x += RELATIVE_ELEMENTS_COORDS_CINQ_PIECE[i][0];
			tmp_y += RELATIVE_ELEMENTS_COORDS_CINQ_PIECE[i][1];
			break;
		}
		if(tmp_x<0)return FALSE_1010;
		if(tmp_y<0)return FALSE_1010;
		if(tmp_x>9)return FALSE_1010;
		if(tmp_y>9)return FALSE_1010;
		if(m_panneau[tmp_x][tmp_y].m_Position.m_x != -1||m_panneau[tmp_x][tmp_y].m_Position.m_y != -1)return FALSE_1010;
	}
	return TRUE_1010;
}

Bool_1010 panneau_test_fin_de_jeu_1010(Piece_1010 piece){
	int i = 0;
	int j = 0;
	for(i = 0; i<10; i++){
		for(j = 0; j<10; j++){
			if(panneau_test_ajout_piece_1010(piece,i,j)==TRUE_1010){
				return FALSE_1010;
			}
		}
	}
	return TRUE_1010;
}

void panneau_test_supprimer_une_ligne_1010(int ligne){
	int i = 0;
	for(i=0;i<10;i++){
		if(m_panneau[ligne][i].m_Position.m_x == -1||m_panneau[ligne][i].m_Position.m_y == -1)return;
	}
	for(i=0;i<10;i++){
		m_panneau[ligne][i].m_a_supprimer = TRUE_1010;
		m_score++;
	}
}

void panneau_test_supprimer_une_colonne_1010(int colonne){
	int i = 0;
	for(i=0;i<10;i++){
		if(m_panneau[i][colonne].m_Position.m_x == -1||m_panneau[i][colonne].m_Position.m_y == -1)return;
	}
	for(i=0;i<10;i++){
		m_panneau[i][colonne].m_a_supprimer = TRUE_1010;
		m_score++;
	}
}

void panneau_supprimer_les_lignes_1010(){
	int i = 0;
	int j = 0;
	for(i = 0;i<10;i++){
		panneau_test_supprimer_une_colonne_1010(i);
		panneau_test_supprimer_une_ligne_1010(i);
	}
	for(i = 0;i<10;i++){
		for(j = 0;j<10;j++){
			if(m_panneau[i][j].m_a_supprimer == TRUE_1010)m_panneau[i][j] = element_creation_1010();
		}
	}
}
