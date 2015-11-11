
/** 
 * \file Joueur_TicTacToe.h
 * \brief Defini le joueur du jeu TicTacToe.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(JOUEUR_TICTACTOE_H)
#define JOUEUR_TICTACTOE_H


#ifdef __cplusplus
extern "C" {
#endif
    
    #include <stdio.h>
    #include "Bool_TicTacToe.h"
    #include "Position_TicTacToe.h"
    #include "Type_TicTacToe.h"
    #include "Panneau_TicTacToe.h"
    #include "../Controlleur/Controlleur_TicTacToe_Tactile.h"
    
    /**
     * \var unsigned int m_score_1_TicTacToe
     * \brief Contient le score actuel du joueur 1 et ne peut pas être négatif.
     */
    unsigned int m_score_1_TicTacToe;
    
    /**
     * \var unsigned int m_score_2_TicTacToe
     * \brief Contient le score actuel du joueur 2 et ne peut pas être négatif.
     */
    unsigned int m_score_2_TicTacToe;

    /**
     * \var Type m_joueur_pion_1_TicTacToe
     * \brief Contient le pion actuel du joueur 1.
     */
    Type_TicTacToe m_joueur_pion_1_TicTacToe;
    
    /**
     * \var Type m_joueur_pion_2_TicTacToe
     * \brief Contient le pion actuel du joueur 2.
     */
    Type_TicTacToe m_joueur_pion_2_TicTacToe;
    
    /**
     * \fn void scores_init_TicTacToe()
     * \brief Initialise les scores des joueurs.
     */
    void scores_init_TicTacToe();

    /**
     * \fn void joueur_init_TicTacToe()
     * \brief Initialise les joueurs.
     */
    void joueur_init_TicTacToe();
    
    
#ifdef __cplusplus
}
#endif


#endif /*!defined(PANNEAU_TICTACTOE_H)*/
 
