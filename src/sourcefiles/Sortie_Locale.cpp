/*
 * Sortie_Locale.cpp
 *
 *  Created on: 14 mai 2014
 *      Author: CHKIRROU_HAFFANE_KHRIBECH
 *
 *  Provided "as is" free for use and modification, provided credit is given under the
 *  authorization of the authors
 */

#include "../headers/Sortie_Locale.h"
#include "../headers/GPIO.h"
#include <sstream>
Sortie_Locale::Sortie_Locale() {
	this->initialization();
}




void Sortie_Locale::writeAll()
{


	/*for (int i=0;i<liste.size();i++)
		{
		    setval_gpio(union_sortie_locale.cbit[i], liste[i]);
		}*/
	 setval_gpio(union_sortie_locale.bit.b6, "4");
	 setval_gpio(union_sortie_locale.bit.b10, "17");
	 setval_gpio(union_sortie_locale.bit.b11, "18");
	 setval_gpio(union_sortie_locale.bit.b12, "21");
	 setval_gpio(union_sortie_locale.bit.b14, "22");
	 setval_gpio(union_sortie_locale.bit.b15, "23");
	 setval_gpio(union_sortie_locale.bit.b17, "24");
	 setval_gpio(union_sortie_locale.bit.b21, "25");

}



void Sortie_Locale::initializationAll()
{

	/*for (int i=0;i<liste.size();i++)
		{
		    export_gpio(liste[i]);
		    setdir_gpio("out", liste[i]);
		}*/

    export_gpio("4");
    setdir_gpio("out", "4");
    export_gpio("17");
    setdir_gpio("out", "17");
    export_gpio("18");
    setdir_gpio("out", "18");
    export_gpio("21");
    setdir_gpio("out", "21");
    export_gpio("22");
    setdir_gpio("out", "22");
    export_gpio("23");
    setdir_gpio("out", "23");
    export_gpio("24");
    setdir_gpio("out", "24");
    export_gpio("25");
    setdir_gpio("out", "25");


}



union_type Sortie_Locale::getUnionSortieLocale() {
	return this->union_sortie_locale;
}

void Sortie_Locale::setUnionSortieLocale(union_type union_sortie_locale) {
	this->union_sortie_locale = union_sortie_locale;
}

void Sortie_Locale::write() {

	setval_gpio(union_sortie_locale.bit.b0, "22");
	setval_gpio(union_sortie_locale.bit.b1, "23");
	setval_gpio(union_sortie_locale.bit.b2, "24");
	setval_gpio(union_sortie_locale.bit.b3, "25");

}

void Sortie_Locale::initialization() {

	export_gpio("22");
	export_gpio("23");
	export_gpio("24");
	export_gpio("25");
	setdir_gpio("out", "22");
	setdir_gpio("out", "23");
	setdir_gpio("out", "24");
	setdir_gpio("out", "25");
}

void Sortie_Locale::termination() {
	union_sortie_locale.bit_32 = 0;
	/*unexport_gpio("22");
	unexport_gpio("23");
	unexport_gpio("24");
	unexport_gpio("25");*/
}

