/*
 * Calcul_Carrefour.h
 *
 *  Created on: 5 juin 2014
 *      Author: youssef
 */

#ifndef CALCUL_CARREFOUR_H_
#define CALCUL_CARREFOUR_H_

#include "../headers/Sortie_Distante.h"
#include "../headers/Temporisation.h"
class Calcul_Carrefour
{
public :
	Calcul_Carrefour();
	~Calcul_Carrefour(){};
	void initialization();
	void execution();
	void readAll();
	void writeAll();
	void termination();
private :
	Sortie_Distante sortie;
	Temporisation first;
	Temporisation second;
	Temporisation third;
	Temporisation fourth;
	Temporisation fifth;



};



#endif /* CALCUL_CARREFOUR_H_ */
