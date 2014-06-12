/*
 * Entree_Front_Montant.h
 *
 *  Created on: 29 mai 2014
 *      Author: youssef
 */

#ifndef ENTREE_FRONT_MONTANT_H_
#define ENTREE_FRONT_MONTANT_H_

#include "../headers/GPIO.h"

class Entree_Front_Montant{
public :
	Entree_Front_Montant();
	~Entree_Front_Montant(){};
	void initialization();
	void detection();
	void union_to_array(union_type , int []);

public :
	union_type union_past;
	union_type union_present;
};



#endif /* ENTREE_FRONT_MONTANT_H_ */
