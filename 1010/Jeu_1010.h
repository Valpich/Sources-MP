
/** 
 * \file Jeu_1010.h
 * \brief Permet de jouer au jeu, possède le point d'entré du programme avec la méthode main.
 * \author Romain Hamon Valentin Pichavant
 * \version 1.0
 * \date Octobre 2015
 */
#if !defined(JEU_1010_H)
#define JEU_1010_H


#ifdef __cplusplus
extern "C" {
#endif
    
    #include "Vue/Affichage_1010.h"
    #include "Modele/Panneau_1010.h"
    #include "Controlleur/Controlleur_1010.h"
    
    /**
     * \fn int jeu_1010_lancer()
     * \brief Permet de lancer le jeu, peut être appelé sans la méthode main par un autre programme.
     * \return La valeur du jeu, indique une erreur si différent de 0.
     */
    int jeu_1010_lancer();

#ifdef __cplusplus
}
#endif


#endif /*!defined(JEU_1010_H)*/
 
