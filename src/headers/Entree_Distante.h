/*
 * Entree_Distante.h
 *
 *  Created on: 13 mai 2014
 *      Author: CHKIRROU_HAFFANE_KHRIBECH
 *
 *  Provided "as is" free for use and modification, provided credit is given under the
 *  authorization of the authors
 */

#ifndef ENTREE_DISTANTE_H_
#define ENTREE_DISTANTE_H_
#include "GPIO.h"
#include "../headers/Client.h"

# include "Entree.h"
#include <iostream>
#include <vector>

class Entree_Distante:public Entree{
public:

	Entree_Distante();
	virtual ~Entree_Distante(){};
	//void Lecture_donée(std::vector<string>);
	void termination();
	void initialization();
	void read();

public :
	union_type union_Entree_Distante;
	std::vector<string> gpios;
	Client c;
};





#endif /* ENTREE_DISTANTE_H_ */
