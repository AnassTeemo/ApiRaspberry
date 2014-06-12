/*
 * Calcul.h
 * Entree.h
 *
 *  Created on: 13 mai 2014
 *      Author: CHKIRROU_HAFFANE_KHRIBECH
 *
 *  Provided "as is" free for use and modification, provided credit is given under the
 *  authorization of the authors
 */

#ifndef CALCUL_H_
#define CALCUL_H_

#include "Entree_Locale.h"
#include "Sortie_Locale.h"

class Calcul {
public :
	Calcul();
	virtual ~Calcul(){};
	void initialization();
	void execution();
public :
	Sortie_Locale sortie;
	Entree_Locale entree;
};




#endif /* CALCUL_H_ */
