/*
 * Calcul_Carrefour.cpp
 *
 *  Created on: 5 juin 2014
 *      Author: youssef
 */

#include "../headers/Calcul_Carrefour.h"
#include "../headers/Temporisation.h"

Calcul_Carrefour::Calcul_Carrefour():
first(5),second(3),third(2),fourth(5),fifth(3)
{
}

void Calcul_Carrefour::initialization() {
	sortie.initialization();
	first.initialization();
	second.initialization();
	third.initialization();
	fourth.initialization();

}

void Calcul_Carrefour::writeAll() {

	/*sortie.union_Sortie_Distante.bit_32=0;
	 sortie.union_Sortie_Distante.bit.b0=1;
	 sortie.union_Sortie_Distante.bit.b3=1;
	 sortie.union_Sortie_Distante.bit.b8=1;
	 sortie.union_Sortie_Distante.bit.b9=1;
	 sortie.write();
	 sleep(5);
	 sortie.union_Sortie_Distante.bit.b0=0;
	 sortie.union_Sortie_Distante.bit.b1=1;
	 sortie.union_Sortie_Distante.bit.b8=0;
	 sortie.union_Sortie_Distante.bit.b7=1;
	 sortie.write();
	 sleep(2);
	 sortie.union_Sortie_Distante.bit.b3=0;
	 sortie.union_Sortie_Distante.bit.b9=0;
	 sortie.union_Sortie_Distante.bit.b1=0;
	 sortie.union_Sortie_Distante.bit.b7=0;
	 sortie.union_Sortie_Distante.bit.b2=1;
	 sortie.union_Sortie_Distante.bit.b5=1;
	 sortie.union_Sortie_Distante.bit.b6=1;
	 sortie.union_Sortie_Distante.bit.b11=1;
	 sortie.write();
	 sleep(5);
	 sortie.union_Sortie_Distante.bit.b5=0;
	 sortie.union_Sortie_Distante.bit.b11=0;
	 sortie.union_Sortie_Distante.bit.b4=1;
	 sortie.union_Sortie_Distante.bit.b10=1;
	 sortie.write();
	 sleep(2);*/

	if (first.test() == false) {
		sortie.union_Sortie_Distante.bit_32 = 0;
		sortie.union_Sortie_Distante.bit.b0 = 1;
		sortie.union_Sortie_Distante.bit.b3 = 1;
		sortie.union_Sortie_Distante.bit.b8 = 1;
		sortie.union_Sortie_Distante.bit.b9 = 1;
		sortie.write();
	} else {
		if (second.test() == false) {
			sortie.union_Sortie_Distante.bit_32 = 0;
			sortie.union_Sortie_Distante.bit.b9 = 1;
			sortie.union_Sortie_Distante.bit.b1 = 1;
			sortie.union_Sortie_Distante.bit.b3 = 1;
			sortie.union_Sortie_Distante.bit.b7 = 1;
			sortie.write();
		} else {
			if (!third.test()) {
				sortie.union_Sortie_Distante.bit_32 = 0;
				sortie.union_Sortie_Distante.bit.b9 = 1;
				sortie.union_Sortie_Distante.bit.b2 = 1;
				sortie.union_Sortie_Distante.bit.b3 = 1;
				sortie.union_Sortie_Distante.bit.b6 = 1;
				sortie.write();
			} else {
				if (!fourth.test()) {
					sortie.union_Sortie_Distante.bit_32 = 0;
					sortie.union_Sortie_Distante.bit.b2 = 1;
					sortie.union_Sortie_Distante.bit.b6 = 1;
					sortie.union_Sortie_Distante.bit.b5 = 1;
					sortie.union_Sortie_Distante.bit.b11 = 1;
					sortie.write();
				} else {
					if (!fifth.test()) {
						sortie.union_Sortie_Distante.bit_32 = 0;
						sortie.union_Sortie_Distante.bit.b2 = 1;
						sortie.union_Sortie_Distante.bit.b6 = 1;
						sortie.union_Sortie_Distante.bit.b10 = 1;
						sortie.union_Sortie_Distante.bit.b4 = 1;
						sortie.write();
					} else {
						sortie.union_Sortie_Distante.bit_32 = 0;
						sortie.union_Sortie_Distante.bit.b2 = 1;
						sortie.union_Sortie_Distante.bit.b3 = 1;
						sortie.union_Sortie_Distante.bit.b6 = 1;
						sortie.union_Sortie_Distante.bit.b9 = 1;
						sortie.write();
						first.initialization();
						second.initialization();
						third.initialization();
						fourth.initialization();
						fifth.initialization();
					}

				}

			}
		}
	}

}
