/****************************************************
 *  Affichage_1010.c                                         
 *  Created on: oct.-2015                     
 *  Implementation of the Class Affichage       
 *  Original author: Valentin Pichavant                     
 ****************************************************/

#include "Affichage_1010.h"


void affichage_panneau_to_string_1010(){
    int i;
    int j;
    puts("Affichage du panneau :");
    for(i = 0;i<10;i++){
        for(j = 0;j<10;j++){
            printf("Il y a en (%d,%d) un element de position (%d,%d)",i,j,m_panneau[i][j].m_Position.m_x,m_panneau[i][j].m_Position.m_y);
            switch(m_panneau[i][j].m_Couleur){
                case JAUNE:
                    puts(" et de couleur jaune.");
                    break;
                case ROUGE:
                    puts(" et de couleur rouge.");
                    break;
                case BLEU:
                    puts(" et de couleur bleu.");
                    break;
                case VERT:
                    puts(" et de couleur vert.");
                    break;
                case CYAN:
                    puts(" et de couleur cyan.");
                    break;
                case VIOLET:
                    puts(" et de couleur violet.");
                    break;
                case BLANC:
                    puts(" et de couleur blanc.");
                    break;
                case NOIR:
                    puts(" et de couleur noir.");
                    break;
                default:
                    puts(" et de couleur inconnue.");
                    break;
            }
        }
    }
    puts("Fin de l'affichage du panneau.");
}

void affichage_panneau_to_ascii_1010(){
    int i;
    int j;
    clrscr();
    puts("Affichage du panneau :");
    puts(" 0123456789");
    for(j = 0;j<10;j++){
        printf("%d",j);
        for(i = 0;i<10;i++){
            switch(m_panneau[i][j].m_Couleur){
                case JAUNE:
                    couleur("33");
                    break;
                case ROUGE:
                    couleur("31");
                    break;
                case BLEU:
                    couleur("34");
                    break;
                case VERT:
                    couleur("32");
                    break;
                case CYAN:
                    couleur("36");
                    break;
                case VIOLET:
                    couleur("35");
                    break;
                case BLANC:
                    couleur("37");
                    break;
                case NOIR:
                    couleur("30");
                    break;
                default:
                    couleur("0");
                    break;
            }
            if(m_panneau[i][j].m_Position.m_x == -1 || m_panneau[i][j].m_Position.m_y == -1)
                printf(" ");
            else
                printf("X");
        }
        couleur("0");
        printf("-");
        puts("");
    }
    puts(" ----------");
    couleur("0");
    puts("Fin de l'affichage du panneau.");
}

void affichage_piece_to_string_1010(Piece_1010 piece){
    switch(piece.m_Type){
        case I:
            printf("Je suis une piece de type I.\n");
            break;
        case J:
            printf("Je suis une piece de type J.\n");
            break;
        case L:
            printf("Je suis une piece de type L.\n");
            break;
        case O:
            printf("Je suis une piece de type O.\n");
            break;
        case T:
            printf("Je suis une piece de type T.\n");
            break;
        case S:
            printf("Je suis une piece de type S.\n");
            break;
        case Z:
            printf("Je suis une piece de type Z.\n");
            break;
    }
}

void affichage_defaite_1010(unsigned int m_score){
    printf("Vous avez perdu :'( Votre score est de %d\n",m_score);
}

void affichage_score_1010(unsigned int m_score){
    printf("Votre score est de %d.\n",m_score);

}
