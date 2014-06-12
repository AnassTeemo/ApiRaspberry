/*
 * Coeur.h
 *
 *  Created on: 13 mai 2014
 *      Author: CHKIRROU_HAFFANE_KHRIBECH
 *
 *  Provided "as is" free for use and modification, provided credit is given under the
 *  authorization of the authors
 */

#ifndef COEUR_H_
#define COEUR_H_

#include "Calcul.h"
#include "Timer.h"

class Coeur
{
public :
	Coeur();
	virtual ~Coeur(){};
	void initialization();
	void execution();
	void termination();
	//void watchdog(int);


};



#endif /* COEUR_H_ */
