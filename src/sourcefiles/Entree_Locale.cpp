/*
 * Entree_Locale.cpp
 *
 *  Created on: 13 mai 2014
 *      Author: CHKIRROU_HAFFANE_KHRIBECH
 *
 *  Provided "as is" free for use and modification, provided credit is given under the
 *  authorization of the authors
 */

#include "../headers/Entree_Locale.h"
#include "../headers/GPIO.h"

using namespace std;

Entree_Locale::Entree_Locale() {
	initialization();
}

union_type Entree_Locale::getUnionEntreeLocale() {

	return this->union_entree_locale;
}

void Entree_Locale::setUnionEntreeLocale(union_type _union_entree) {
	this->union_entree_locale = _union_entree;
}

void Entree_Locale::initialization() {
	export_gpio("4");
	export_gpio("17");
	export_gpio("18");
	export_gpio("21");
	setdir_gpio("in", "4");
	setdir_gpio("in", "17");
	setdir_gpio("in", "18");
	setdir_gpio("in", "21");
}

void Entree_Locale::read() {
	union_entree_locale.bit.b0 = getval_gpio("4");
	union_entree_locale.bit.b1 = getval_gpio("17");
	union_entree_locale.bit.b2 = getval_gpio("18");
	union_entree_locale.bit.b3 = getval_gpio("21");

}

void Entree_Locale::termination() {
	union_entree_locale.bit_32 = 0;
	unexport_gpio("4");
	unexport_gpio("17");
	unexport_gpio("18");
	unexport_gpio("21");

}
