/*
 * Entree_Distante.cpp
 *
 *  Created on: 26 mai 2014
 *      Author: youssef
 */

#include "../headers/Entree_Distante.h"
#include "../headers/GPIO.h"
#include <iostream>
#include <vector>
#include <cmath>


Entree_Distante::Entree_Distante():c(9090)
{
 //c=Client(9090);
}



void Entree_Distante::termination()
{

}

void Entree_Distante::initialization()
{
	c.start();
}


void Entree_Distante::read()
{
	long somme=0;
	char vrr[33];
	c.receive(vrr);
	for(int i=0;i<31;i++)
	{
		//std::cout<< "valeur :" << vrr[i];
		somme += (vrr[i]-'0')*pow(2,i);
	}

	union_Entree_Distante.bit_32=somme;
	union_Entree_Distante.bit.b31=vrr[31];
}






