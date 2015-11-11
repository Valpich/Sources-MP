/*
 * appli.h
 *
 *  Created on: 1 avr. 2015
 *      Author: Nirgal
 */

#ifndef APPLI_H_
#define APPLI_H_


/*
 * @brief Initialisation de notre application, et des p�riph�riques qu'elle utilise.
 * @pre : cette fonction doit �tre appel�e pr�alablement � tout autre appel de fonction de cette classe.
 */
void APPLI_init(void);

/*
 * @brief Boucle de t�che de fond de l'application
 * @pre : doit �tre appel�e r�guli�rement.
 */
void APPLI_process_main(void);

/*
 * @brief Routine d'it de l'application.
 * @pre : cette fonction doit �tre appel�e toutes les ms.
 */
void APPLI_process_1ms(void);


#endif /* APPLI_H_ */
