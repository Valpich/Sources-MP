
/**
 * \file Jeu_TicTacToe_GUI.h
 * \brief Contient les fonctions d'affichage du jeu TicTacToe.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Novembre 2015
 */
#ifndef JEU_TICTACTOE_GUI_H
#define JEU_TICTACTOE_GUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>
#include "../../GUI.h"
#include "lcd_display_form_and_text.h"
#include "stm32f4_lcd.h"
#include "../Modele/Panneau_TicTacToe.h"


/**
 * \fn void dessin_jeu_complet_TicTacToe()
 * \brief Permet d'afficher le jeu TicTacToe.
 */
void dessin_jeu_complet_TicTacToe();

/**
 * \fn void dessin_TicTacToe()
 * \brief Permet d'afficher la base du jeu TicTacToe.
 */
void dessin_TicTacToe();

/**
 * \fn void dessin_pion()
 * \brief Permet de dessiner les pions du jeu TicTacToe.
 */
void dessin_pion();

/**
 * \fn void dessin_cercle(Cercle_GUI cercle)
 * \brief Permet de dessiner un cercle du jeu TicTacToe.
 * \param cercle Le cercle a dessiner.
 */
void dessin_cercle(Cercle_GUI cercle);

/**
 * \fn void dessin_croix(Croix_GUI croix)
 * \brief Permet de dessiner une croix du jeu TicTacToe.
 * \param croix La croix a dessiner.
 */
void dessin_croix(Croix_GUI croix);

/**
 * \fn void dessin_scores(unsigned int score_1, unsigned int score_2)
 * \brief Permet de dessiner les scores du jeu TicTacToe.
 * \param score_1 Le score du joueur 1.
 * \param score_2 Le score du joueur 2.
 */
void dessin_scores(unsigned int score_1, unsigned int score_2);

/**
 * \fn void dessin_joueur(unsigned int joueur)
 * \brief Permet de dessiner les scores du jeu TicTacToe.
 * \param joueur Le numero du joueur actuel.
 */
void dessin_joueur(unsigned int joueur);

//Fonctions de test :

/**
 * \fn void test_dessin_TicTacToe()
 * \brief Permet de tester l'affichage du jeu TicTacToe.
 */
void test_dessin_TicTacToe();

/**
 * \fn void test_dessin_cercle()
 * \brief Permet de tester l'affichage d'un cercle.
 */
void test_dessin_cercle();

/**
 * \fn void test_dessin_croix()
 * \brief Permet de tester l'affichage d'une croix.
 */
void test_dessin_croix();

//Constantes relative aux positions des pions du jeu
static const Cercle_GUI cercle_a={{135,119},10};
static const Cercle_GUI cercle_b={{181,119},10};
static const Cercle_GUI cercle_c={{227,119},10};
static const Cercle_GUI cercle_d={{135,165},10};
static const Cercle_GUI cercle_e={{181,165},10};
static const Cercle_GUI cercle_f={{227,165},10};
static const Cercle_GUI cercle_g={{135,211},10};
static const Cercle_GUI cercle_h={{181,211},10};
static const Cercle_GUI cercle_i={{227,211},10};
static const Croix_GUI croix_a={{{125,109},{145,129}},{{125,129},{145,109}}};
static const Croix_GUI croix_b={{{171,109},{191,129}},{{171,129},{191,109}}};
static const Croix_GUI croix_c={{{217,109},{237,129}},{{217,129},{237,109}}};
static const Croix_GUI croix_d={{{125,155},{145,175}},{{125,175},{145,155}}};
static const Croix_GUI croix_e={{{171,155},{191,175}},{{171,175},{191,155}}};
static const Croix_GUI croix_f={{{217,155},{237,175}},{{217,175},{237,155}}};
static const Croix_GUI croix_g={{{125,201},{145,221}},{{125,221},{145,201}}};
static const Croix_GUI croix_h={{{171,201},{191,221}},{{171,221},{191,201}}};
static const Croix_GUI croix_i={{{217,201},{237,221}},{{217,221},{237,201}}};


#ifdef __cplusplus
}
#endif

#endif
