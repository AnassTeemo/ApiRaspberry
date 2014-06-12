/*
 * Calcul_Chenillard.cpp
 *
 *  Created on: 2 juin 2014
 *      Author: youssef
 */

#include "../headers/Calcul_Chenillard.h"


Calcul_Chenillard::Calcul_Chenillard()
{

}


void Calcul_Chenillard::initialization()
{
	sortie.initialization();

}

void Calcul_Chenillard::writeAll()
{
	sortie.union_Sortie_Distante.bit.b0=1;
	sortie.union_Sortie_Distante.bit.b3=0;
	sortie.write();
	sleep(1);

	for (int i = 0; i < 3; i++) {

		sortie.union_Sortie_Distante.bit_4.b0_3 *= 2;
		sortie.write();
		sleep(1);
	}
}
