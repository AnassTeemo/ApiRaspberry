/*
 * Entree_Front_Montant.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: youssef
 */

#include "../headers/Entree_Front_Montant.h"

#include <iostream>


Entree_Front_Montant::Entree_Front_Montant()
{
	//initialisation();
}

void Entree_Front_Montant::initialization()
{
	union_past.bit_32=0;
	union_present.bit_32=0;
}

void Entree_Front_Montant::detection()
{


	int present[32]={0};
	int past[32]={0};
	union_to_array(union_present, present);
	union_to_array(union_past, past);

	for(int i=0;i<32;i++)
	{
		if(present[i]!=past[i])
			{
				if(present[i]==1)
					std::cout <<"Front montant pour le bit :" << i << std::endl;
				else std::cout <<"Front descendant pour le bit :" << i << std::endl;
			}

	}
	union_past.bit_32=union_present.bit_32;

}

void Entree_Front_Montant::union_to_array(union_type change,int test[] )
{
		int remainder;
		long value=change.bit_32;
		int i=0;
		while (value > 0)
		            {
		                remainder = value % 2;
		               value /= 2;
		               test[i]=  remainder;

		               i++;
		            }

		test[31]=change.bit.b31;
}
