
/**
 * \file Jeu_1010_GUI.h
 * \brief Contient les fonctions d'affichage du jeu 1010.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Novembre 2015
 */
#ifndef JEU_1010_GUI_H
#define JEU_1010_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "../../GUI.h"
#include "lcd_display_form_and_text.h"
#include "stm32f4_lcd.h"
#include "../../1010/Modele/Panneau_1010.h"


/**
 * \struct Carre_GUI
 * \brief Definie la structure Carre_GUI.
 */
typedef struct Carre_GUI{
	uint16_t x; /*!< La position en x du coin superieur gauche du carre. */
	uint16_t y; /*!< La position en y du coin superieur gauche du carre. */
	uint16_t width; /*!< La largeur du carre. */
	uint16_t height; /*!< Lahauteur du carre. */
}Carre_GUI;

/**
 * \fn void dessin_jeu_complet_1010()
 * \brief Permet d'afficher le jeu 1010.
 */
void dessin_jeu_complet_1010();

/**
 * \fn void dessin_1010()
 * \brief Permet d'afficher la base du jeu 1010.
 */
void dessin_1010();

/**
 * \fn void dessin_pieces()
 * \brief Permet de dessiner les pieces du jeu 1010.
 */
void dessin_pieces();

/**
 * \fn void dessin_carre(Carre_GUI carre, uint16_t couleur)
 * \brief Permet de dessiner un cercle du jeu 1010.
 * \param carre Le carre a dessiner.
 * \param couleur La couleur du carre a dessiner.
 */
void dessin_carre(Carre_GUI carre, uint16_t couleur);

/**
 * \fn void dessin_score(unsigned int score_1)
 * \brief Permet de dessiner le score du joueur.
 * \param score_1 Le score du joueur 1.
 */
void dessin_score(unsigned int score_1);

/**
 * \fn void afficher_defaite()
 * \brief Permet d'afficher la defaite du joueur.
 */
void afficher_defaite();

/**
 * \fn void dessin_choix(int choix)
 * \brief Affiche un nombre pour permettre au joueur de choisir la piece.
 * \param choix Le choix possible.
 */
void dessin_choix(int choix);

/**
 * \fn void dessin_choix_selectionner(int choix)
 * \brief Affiche le nombre choisi par le joueur pour la piece.
 * \param choix Le choix du joueur.
 */
void dessin_choix_selectionner(int choix);

/**
 * \fn void dessin_piece(Piece_1010 piece, int numero)
 * \brief Permet de dessiner une piece du jeu 1010.
 * \param piece La piece a dessiner.
 * \param numero Le numero de la piece a dessiner.
 */
void dessin_piece(Piece_1010 piece, int numero);

#ifdef __cplusplus
}
#endif

#endif
