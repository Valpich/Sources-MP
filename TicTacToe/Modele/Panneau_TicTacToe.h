
/**
 * \file Panneau_TicTacToe.h
 * \brief Defini le panneau du jeu TicTacToe qui contient les différents pions.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(PANNEAU_TICTACTOE_H)
#define PANNEAU_TICTACTOE_H


#ifdef __cplusplus
extern "C" {
#endif
    
    #include <stdio.h>
    #include "Pion_TicTacToe.h"
    #include "Bool_TicTacToe.h"
    #include "Joueur_TicTacToe.h"
    
    /**
     * \var Pion_TicTacToe m_panneau_TicTacToe
     * \brief Matrice 3*3 qui contient l'ensemble des pions du panneau.
     */
    Pion_TicTacToe m_panneau_TicTacToe[3][3];
    
    /**
     * \var Bool_TicTacToe m_panneau_joueur_courant_TicTacToe
     * \brief Contient FALSE_TICTACTOE pour le joueur 1, TRUE_TICTACTOE pour le joueur 2.
     */
    Bool_TicTacToe m_panneau_joueur_courant_TicTacToe;
    
    /**
     * \fn void panneau_init_TicTacToe()
     * \brief Permet d'initialiser le panneau.
     */
    void panneau_init_TicTacToe();
    
    /**
     * \fn void panneau_ajouter_pion_TicTacToe(Pion_TicTacToe pion, int x, int y)
     * \brief Permet d'ajouter un pion au panneau.
     * \param pion Le pion à ajouter.
     * \param x La position en x où l'on veut poser le pion.
     * \param y La position en y où l'on veut poser le pion.
     */
    void panneau_ajouter_pion_TicTacToe(Pion_TicTacToe pion, int x, int y);
    
    /**
     * \fn Bool_TicTacToe panneau_test_ajout_pion_TicTacToe(int x, int y)
     * \brief Permet de verifier si l'ajout d'un pion au panneau est valide.
     * \param x La position en x où l'on veut poser le pion.
     * \param y La position en y où l'on veut poser le pion.
     * \return Si il est possible d'ajouter ou pas le pion au panneau à la position fournie.
     */
    Bool_TicTacToe panneau_test_ajout_pion_TicTacToe(int x, int y);
    
    /**
     * \fn int panneau_test_fin_de_jeu_TicTacToe()
     * \brief Permet de verifier si le jeu est fini.
     * \return 0 si il est de poursuivre le jeu, 1 si le joueur 1 a gagné, 2 si le joueur 2 a gagné, 3 si il y a  égalité.
     */
    int panneau_test_fin_de_jeu_TicTacToe();
    
    /**
     * \fn void panneau_changer_joueur_TicTacToe()
     * \brief Permet de changer le joueur actuel.
     */
    void panneau_changer_joueur_TicTacToe();
    
#ifdef __cplusplus
}
#endif


#endif /*!defined(PANNEAU_TICTACTOE_H)*/
 
