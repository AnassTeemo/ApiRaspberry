/*

 * Calcul.cpp
 *
 *  Created on: 14 mai 2014
 *      Author: youssef
 */

#include "../headers/Calcul.h"
#include "../headers/GPIO.h"
#include <unistd.h>



Calcul::Calcul() {

}




void Calcul::initialization() {

	entree.initialization();
	union_type union_entree = entree.getUnionEntreeLocale();
	union_entree.bit.b0 = 0;
	union_entree.bit.b1 = 0;
	union_entree.bit.b2 = 0;
	union_entree.bit.b3 = 0;
	entree.setUnionEntreeLocale(union_entree);

	sortie.initialization();
	union_type union_sortie = sortie.getUnionSortieLocale();
	union_sortie.bit.b0 = 0;
	union_sortie.bit.b1 = 0;
	union_sortie.bit.b2 = 0;
	union_sortie.bit.b3 = 0;
	sortie.setUnionSortieLocale(union_sortie);

}

void Calcul::execution() {
	//union_type union_entree = entree.getUnionEntreeLocale();
	//union_type union_sortie = sortie.getUnionSortieLocale();
	sortie.union_sortie_locale.bit.b0 = 1;
	sortie.union_sortie_locale.bit.b1 = 0;
	sortie.union_sortie_locale.bit.b2 = 0;
	sortie.union_sortie_locale.bit.b3 = 0;
	sortie.write();
	sleep(1);

	for (int i = 0; i < 3; i++) {
		sortie.union_sortie_locale.bit_4.b0_3 *= 2;
		sortie.write();
		sleep(1);
	}

	//sortie.union_sortie_locale.bit.b2 = 0;
	//sortie.union_sortie_locale.bit.b3 = 0;

	//union_entree.bit.b0 = union_sortie.bit.b0;
	//union_sortie.bit.b1 = 1 - union_entree.bit.b0;
	//sortie.setUnionSortieLocale(union_sortie);
	//entree.setUnionEntreeLocale(union_entree);

}

