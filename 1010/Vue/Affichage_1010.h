
/** 
 * \file Affichage_1010.h
 * \brief Partie affichage du jeu 1010.
 * \author Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(AFFICHAGE_1010_H)
#define AFFICHAGE_1010_H


#ifdef __cplusplus
extern "C" {
#endif
    
    #include "../Modele/Couleur_1010.h"
    #include "../Modele/Panneau_1010.h"
    #include "../Modele/Piece_1010.h"
    
    /** 
     * \fn void affichage_panneau_to_string_1010()
     *\brief Affiche le panneau sous forme d'une chaine de caractère sur le terminal.
     */
    void affichage_panneau_to_string_1010();
    
    /** 
     * \fn void affichage_panneau_to_ascii_1010()
     * \brief Affiche le panneau sous forme d'un tableau d'ascii.
     */
    void affichage_panneau_to_ascii_1010();
    
    /** 
     * \fn void affichage_piece_to_string_1010(Piece_1010 piece)
     * \brief Affiche la piece passée en paramètre sous forme de chaine de caractère.
     * \param piece La piece à afficher.
     */
    void affichage_piece_to_string_1010(Piece_1010 piece);
    
    /** 
     * \fn void affichage_defaite_1010(unsigned int m_score)
     * \brief Affiche à l'utilisateur qu'il a perdu le jeu.
     * \param m_score Le score de l'utilisateur au moment de sa défaite.
     */
    void affichage_defaite_1010(unsigned int m_score);
    
    /** 
     * \fn void affichage_score_1010(unsigned int m_score)
     * \brief Affiche à l'utilisateur le score actuel dans le jeu.
     * \param m_score Le score de l'utilisateur au moment de l'affichage.
     */
    void affichage_score_1010(unsigned int m_score);
    
#ifdef __cplusplus
}
#endif


#endif /*!defined(AFFICHAGE_1010_H)*/
