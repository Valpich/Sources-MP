/****************************************************
 *  Jeu_1010.c                                         
 *  Created on: oct.-2015                    
 *  Implementation of the Class Jeu_1010       
 *  Original author: Romain Hamon Valentin Pichavant                     
 ****************************************************/

#include "Jeu_1010.h"

int jeu_lancer_1010(){
	panneau_init_1010();
	m_exit_1010 = FALSE_1010;
	setjmp(buf_1010);
	if(m_exit_1010 == TRUE_1010){
		delay(100);
		return 1;
	}
	while(1)jeu_1010_jouer();
	return 0;
}

int jeu_1010_jouer(){
	Piece_1010 piece_1;
	Piece_1010 piece_2;
	Piece_1010 piece_3;
	dessin_jeu_complet_1010();
	uint16_t x = 0,y = 0;
	int numero_piece = -1;
	Bool_1010 piece_disponible[3];
	do{
		piece_creation_1010(&piece_1);
		piece_disponible[0]=TRUE_1010;
		piece_creation_1010(&piece_2);
		piece_disponible[1]=TRUE_1010;
		piece_creation_1010(&piece_3);
		piece_disponible[2]=TRUE_1010;
		do{
			dessin_jeu_complet_1010();
			if(piece_disponible[0]==TRUE_1010){
				dessin_piece(piece_1, 0);
				dessin_choix(0);
			}
			if(piece_disponible[1]==TRUE_1010){
				dessin_piece(piece_2, 1);
				dessin_choix(1);
			}
			if(piece_disponible[2]==TRUE_1010){
				dessin_piece(piece_3, 2);
				dessin_choix(2);
			}
			do{
				numero_piece = choisir_piece_1010();
			}while(piece_disponible[numero_piece] == FALSE_1010 || test_position_possible(piece_1,piece_2,piece_3,numero_piece) == TRUE_1010 );
			if(numero_piece == 0){
				piece_disponible[0]=FALSE_1010;
				dessin_jeu_complet_1010();
				dessin_piece(piece_1, 1);
				dessin_choix_selectionner(0);
				choisir_position_1010(piece_1);
			}
			if(numero_piece == 1){
				piece_disponible[1]=FALSE_1010;
				dessin_jeu_complet_1010();
				dessin_piece(piece_2, 1);
				dessin_choix_selectionner(1);
				choisir_position_1010(piece_2);
			}
			if(numero_piece == 2){
				piece_disponible[2]=FALSE_1010;
				dessin_jeu_complet_1010();
				dessin_piece(piece_3, 1);
				dessin_choix_selectionner(2);
				choisir_position_1010(piece_3);
			}
			panneau_supprimer_les_lignes_1010();
		}while((piece_disponible[0] == TRUE_1010 || piece_disponible[1] == TRUE_1010 || piece_disponible[2] == TRUE_1010) && test_fin_de_jeu(piece_1,piece_2,piece_3,piece_disponible) == FALSE_1010);
	}while(test_fin_de_jeu(piece_1,piece_2,piece_3,piece_disponible) == FALSE_1010 );
	afficher_defaite();
	delay(400);
	Bool_1010 appuye = FALSE_1010;
	while(appuye == FALSE_1010)appuye = TS_Get_Touch(&x, &y);
	choisir_quitter_jeu_1010();
	return 0;
} 

Bool_1010 test_fin_de_jeu(Piece_1010 piece_1, Piece_1010 piece_2, Piece_1010 piece_3, Bool_1010 * test){
	if(test[0] == TRUE_1010){
		if(panneau_test_fin_de_jeu_1010(piece_1)==FALSE_1010)return FALSE_1010;
	}
	if(test[1] == TRUE_1010){
		if(panneau_test_fin_de_jeu_1010(piece_2)==FALSE_1010)return FALSE_1010;
	}
	if(test[2] == TRUE_1010){
		if(panneau_test_fin_de_jeu_1010(piece_3)==FALSE_1010)return FALSE_1010;
	}
	if(test[0] == FALSE_1010 && test[1] == FALSE_1010 && test[2] == FALSE_1010)return FALSE_1010;
	return TRUE_1010;
}

Bool_1010 test_position_possible(Piece_1010 piece_1, Piece_1010 piece_2, Piece_1010 piece_3,int numero_piece){
	if(numero_piece == 0){
		if(panneau_test_fin_de_jeu_1010(piece_1)==TRUE_1010)return TRUE_1010;
	}
	if(numero_piece == 1){
		if(panneau_test_fin_de_jeu_1010(piece_2)==TRUE_1010)return TRUE_1010;
	}
	if(numero_piece == 2){
		if(panneau_test_fin_de_jeu_1010(piece_3)==TRUE_1010)return TRUE_1010;
	}
	return FALSE_1010;
}
