
/*
 * Calcul_Chenillard.h
 *
 *  Created on: 27 mai 2014
 *      Author: youssef
 */

#ifndef CALCUL_CHENILLARD_H_
#define CALCUL_CHENILLARD_H_

#include "../headers/Sortie_Distante.h"
#include "../headers/Sortie_Locale.h"
#include "../headers/Entree_Front_Montant.h"
#include "../headers/Temporisation.h"

class Calcul_Chenillard
{
public :
	Calcul_Chenillard();
	~Calcul_Chenillard(){};
	void initialization();
	void execution();
	void readAll();
	void writeAll();
	void termination();
private :
	Sortie_Distante sortie;


};



#endif /* Calcul_Chenillard_H_ */
