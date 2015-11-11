
/** 
 * \file Jeu_TicTacToe.h
 * \brief Permet de jouer au jeu, possède le point d'entré du programme avec la méthode main.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(JEU_TICTACTOE_H)
#define JEU_TICTACTOE_H


#ifdef __cplusplus
extern "C" {
#endif
    
    #include <setjmp.h>
    #include "Vue/Jeu_TicTacToe_GUI.h"
    #include "Modele/Panneau_TicTacToe.h"
    #include "Modele/Joueur_TicTacToe.h"
    #include "Controlleur/Controlleur_TicTacToe_Tactile.h"
	#include "../demo_touchscreen.h"

    /**
     * \var jmp_buf buf_TicTacToe
     * \brief Permet d'indiquer à quel moment revenir lors du longjump du controlleur.
     */
    jmp_buf buf_TicTacToe;
    
    /**
     * \var Bool_TicTacToe m_exit
     * \brief Booléen indiquant qu'il faut terminer le jeu de façon instannée si TRUE.
     */
    Bool_TicTacToe m_exit_TicTacToe;
    
    /** 
     * \fn int jeu_lancer_TicTacToe()
     * \brief Permet de lancer le jeu, peut être appelé sans la méthode main par un autre programme.
     * \return La valeur retour du jeu, indique 0 si jeu terminé normalement, 1 si quitter en plein milieu.
     */
    int jeu_lancer_TicTacToe();
    
    /**
     * \fn int jouer_des_tours_TicTacToe()
     * \brief Permet de jouer tant que la partie n'est pas finie.
     * \return 1 si le joueur 1 a gagné, 2 si le joueur 2 a gagné, 3 si il y a  égalité.
     */
    int jouer_des_tours_TicTacToe();
    
    /**
     * \fn Bool jouer_des_parties_TicTacToe()
     * \brief Permet de jouer des parties tant que je le(s) joueur(s) ne souhaite(nt) pas quitter la partie.
     */
    void jouer_des_parties_TicTacToe();
    
#ifdef __cplusplus
}
#endif


#endif /*!defined(JEU_TICTACTOE_H)*/
 
