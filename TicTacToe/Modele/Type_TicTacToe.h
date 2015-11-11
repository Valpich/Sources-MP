
/**
 * \file Type_TicTacToe.h
 * \brief Definie les différents types de pion du jeu TicTacToe.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(TYPE_TICTACTOE_H)
#define TYPE_TICTACTOE_H


#ifdef __cplusplus
extern "C" {
#endif
    
    /**
     * \enum Type_TicTacToe
     * \brief Definie l'enum Type_TicTacToe.
     * Les valeurs pour les pions possibles sont : O,X.
     */
    typedef enum Type_TicTacToe{
        X, O
    }Type_TicTacToe;


#ifdef __cplusplus
}
#endif


#endif /*!defined(TYPE_TICTACTOE_H)*/
 
