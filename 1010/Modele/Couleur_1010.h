
/** 
 * \file Couleur_1010.h
 * \brief Defini les couleurs pour le jeu 1010.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(COULEUR_1010_H)
#define COULEUR_1010_H


#ifdef __cplusplus
extern "C" {
#endif

#ifndef clrscr
/**
 * \def clrscr()
 * \brief Une macro qui nettoye le terminal.
 */
#define clrscr() printf("\033[H\033[2J")
#endif

#ifndef couleur
/**
 * \def couleur(param)
 * \brief Une macro qui modifie la couleur d'affichage sur le terminal.
     param devant être un const char *, vide (identique à "0")
     ou formé d'une où plusieurs valeurs séparées par des ";" parmi
     0  réinitialisation         1  haute intensité des caractères
     5  clignotement             7  video inversé
     30, 31, 32, 33, 34, 35, 36, 37 couleur des caractères
     40, 41, 42, 43, 44, 45, 46, 47 couleur du fond
 */
#define couleur(param) printf("\033[%sm",param)
#endif


/**
 * \enum Couleur_1010
 * \brief Definie l'enum Couleur_1010e.
 * Les valeurs sont 0 pour JAUNE, 1 pour ROUGE, 2 pour BLEU, 3 pour VERT, 4 pour CYAN, 5 pour VIOLET, 6 pour ORANGE et 7 pour NOIR.
 */
typedef enum Couleur_1010{
	JAUNE,ROUGE,BLEU,VERT,CYAN,VIOLET,ORANGE,NOIR
}Couleur_1010;


#ifdef __cplusplus
}
#endif


#endif /*!defined(COULEUR_1010_H)*/

