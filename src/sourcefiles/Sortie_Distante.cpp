/*
 * Sortie_Distante.cpp
 *
 *  Created on: 2 juin 2014
 *      Author: youssef
 */


#include "../headers/Sortie_Distante.h"

Sortie_Distante::Sortie_Distante():c(9090)
{

}


void Sortie_Distante::initialization()
{
	c.start();
	union_Sortie_Distante.bit_32=0;


}


void Sortie_Distante::write()
{
	int tab[32]={0};
	char tabs[32];
    union_to_array(union_Sortie_Distante, tab);
    for(int i=0;i<32;i++)
    {
    	tabs[i]=tab[i]+'0';
    }

	std::cout << "my 32 bits word is: ";
	for (int j = 0; j < 32; j++)
		std::cout << ' ' << tabs[j];
	std::cout << '\n';

	c.sifet(tabs);
}

void Sortie_Distante::union_to_array(union_type change,int test[] )
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

void Sortie_Distante::termination()
{

}
