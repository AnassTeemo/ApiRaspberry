/*
 * Calcul_Gpio.h
 *
 *  Created on: 27 mai 2014
 *      Author: youssef
 */

#ifndef CALCUL_GPIO_H_
#define CALCUL_GPIO_H_

#include "../headers/Entree_Distante.h"
#include "../headers/Sortie_Locale.h"
#include "../headers/Entree_Front_Montant.h"
#include "../headers/Temporisation.h"

class Calcul_Gpio
{
public :
	Calcul_Gpio();
	~Calcul_Gpio(){};
	void initialization();
	void execution();
	void readAll();
	void writeAll();

private :
	Sortie_Locale sortie;
	std::vector<string> gpios_calcul;
	Entree_Front_Montant front_montant;
	Temporisation tempo;

};



#endif /* Calcul_Gpio_H_ */
