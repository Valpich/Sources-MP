
/** 
 * \file Panneau_1010.h
 * \brief Defini le panneau du jeu 1010 qui contient les différents elements.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(PANNEAU_1010_H)
#define PANNEAU_1010_H


#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "Element_1010.h"
#include "Piece_1010.h"
#include "Bool_1010.h"


/**
 * \var Element_1010 m_panneau
 * \brief Matrice 10*10 qui contient l'ensemble des elements du panneau.
 */
Element_1010 m_panneau[10][10];

/**
 * \var unsigned int m_score
 * \brief Contient le score actuel du joueur et ne peut pas être négatif.
 */
unsigned int m_score;

/**
 * \fn void panneau_init_1010()
 * \brief Permet d'initialiser le panneau.
 */
void panneau_init_1010();

/**
 * \fn void panneau_ajouter_piece_1010(Piece_1010 piece, int x, int y)
 * \brief Permet d'ajouter une piece au panneau.
 * \param piece_1010 La piece à ajouter.
 * \param x La position en x où l'on veut poser la piece.
 * \param y La position en y où l'on veut poser la piece.
 */
void panneau_ajouter_piece_1010(Piece_1010 piece, int x, int y);

/**
 * \fn Bool_1010 panneau_test_ajout_piece_1010(Piece_1010 piece, int x, int y)
 * \brief Permet de verifier si l'ajout d'une piece au panneau est valide.
 * \param piece_1010 La piece à ajouter.
 * \param x La position en x où l'on veut poser la piece.
 * \param y La position en y où l'on veut poser la piece.
 * \return Si il est possible d'ajouter ou pas la piece au panneau à la position fournie.
 */
Bool_1010 panneau_test_ajout_piece_1010(Piece_1010 piece, int x, int y);

/**
 * \fn Bool_1010 panneau_test_fin_de_jeu_1010(Piece_1010 piece)
 * \brief Permet de verifier si le jeu est fini.
 * \param piece_1010 La piece à ajouter.
 * La piece à ajouter va permettre de tester si il existe un emplacement pour inserer celle-ci.
 * \return Si il est de poursuivre ou pas le jeu.
 */
Bool_1010 panneau_test_fin_de_jeu_1010(Piece_1010 piece);

/**
 * \fn void panneau_test_supprimer_une_ligne_1010(int ligne)
 * \brief Permet de tester si une ligne doit être supprimée.
 * \param ligne La ligne à tester.
 * Si une ligne doit être supprimée, les elements qui la composent voient le champ m_a_supprimer passer à TRUE.
 */
void panneau_test_supprimer_une_ligne_1010(int ligne);

/**
 * \fn void panneau_test_supprimer_une_colonne_1010(int colonne)
 * \brief Permet de tester si une ligne doit être supprimée.
 * \param colonne La colonne à tester.
 * Si une colonne doit être supprimée, les elements qui la composent voient le champ m_a_supprimer passer à TRUE.
 */
void panneau_test_supprimer_une_colonne_1010(int colonne);

/**
 *fn void panneau_supprimer_les_lignes_1010()
 * brief Permet de supprimer les lignes et colonnes qui doivent l'être.
 */
void panneau_supprimer_les_lignes_1010();

#ifdef __cplusplus
}
#endif


#endif /*!defined(PANNEAU_1010_H)*/

