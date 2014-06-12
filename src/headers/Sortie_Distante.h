/*
 * Sortie_Distante.h
 *
 *  Created on: 13 mai 2014
 *      Author: CHKIRROU_HAFFANE_KHRIBECH
 *
 *  Provided "as is" free for use and modification, provided credit is given under the
 *  authorization of the authors
 */

#ifndef SORTIE_DISTANTE_H_
#define SORTIE_DISTANTE_H_

# include "Sortie.h"
#include "../headers/GPIO.h"
#include "../headers/Client.h"

class Sortie_Distante:Sortie
{
public :
	Sortie_Distante();
	virtual ~Sortie_Distante(){};
	void initialization();
	void write();
	void termination();
	void union_to_array(union_type , int []);
public :
	union_type union_Sortie_Distante;
	Client c;
};



#endif /* SORTIE_DISTANTE_H_ */
