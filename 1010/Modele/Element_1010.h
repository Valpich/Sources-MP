
/** 
 * \file Element_1010.h
 * \brief Defini un element du jeu 1010.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(ELEMENT_1010_H)
#define ELEMENT_1010_H


#ifdef __cplusplus
extern "C" {
#endif
    
    #include "Position_1010.h"
    #include "Couleur_1010.h"
    #include "Bool_1010.h"
    
    /** 
     * \def DEFAULT_POS_X
     * \brief La position par défaut en x d'un element, ici de valeur -1.
     */
    #define DEFAULT_POS_X -1
    
    /**
     * \def DEFAULT_POS_Y
     * \brief La position par défaut en y d'un element, ici de valeur -1.
     */
    #define DEFAULT_POS_Y -1
    
    /** 
     * \def DEFAULT_COLOR
     * \brief La couleur par défaut d'un element, ici de valeur 8.
     */
    #define DEFAULT_COLOR 8

    /**
     * \struct Element_1010
     * \brief Definie la structure Element_1010.
     */
    typedef struct Element_1010{
        Couleur_1010 m_Couleur;      /*!< La couleur de l'element */
        Position_1010 m_Position;    /*!< La position de l'element */
        Bool_1010 m_a_supprimer;     /*!< Si l'element doit être supprimé au prochain tour de jeu */
    }Element_1010;
    
    /** 
     * \fn Element element_creation
     * \brief Retourne un nouvel element bien initialisé.
     * \return L'element créé par la fonction.
     */
    Element_1010 element_creation_1010();

#ifdef __cplusplus
}
#endif


#endif /*!defined(ELEMENT_1010_H)*/
 