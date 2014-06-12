/*
 * Entree_Locale.h
 *
 *  Created on: 13 mai 2014
 *      Author: CHKIRROU_HAFFANE_KHRIBECH
 *
 *  Provided "as is" free for use and modification, provided credit is given under the
 *  authorization of the authors
 */

#ifndef ENTREE_LOCALE_H_
#define ENTREE_LOCALE_H_

# include "Entree.h"
#include "GPIO.h"

class Entree_Locale :Entree{
public:
	Entree_Locale();
	virtual ~Entree_Locale(){};

	union_type  getUnionEntreeLocale() ;
	void  setUnionEntreeLocale(union_type) ;

	void  initialization() ;
	void  read() ;
	void  termination();

public :
	union_type union_entree_locale;
};




#endif /* ENTREE_LOCALE_H_ */
