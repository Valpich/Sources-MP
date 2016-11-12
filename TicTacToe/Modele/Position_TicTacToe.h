
/**
 * \file Position_TicTacToe.h
 * \brief Defini une position en 2D.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(POSITION_TICTACTOE_H)
#define POSITION_TICTACTOE_H


#ifdef __cplusplus
extern "C" {
#endif

/**
 * \struct Position_TicTacToe
 * \brief Definie la structure Position_TicTacToe.
 */
typedef struct Position_TicTacToe{
	int m_x;    /*!< La valeur en x de la position */
	int m_y;    /*!< La valeur en y de la position */
}Position_TicTacToe;



#ifdef __cplusplus
}
#endif


#endif /*!defined(POSITION_TICTACTOE_H)*/
