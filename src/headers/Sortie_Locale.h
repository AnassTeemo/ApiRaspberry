/*
 * Sortie_Locale.h
 *
 *  Created on: 13 mai 2014
 *      Author: CHKIRROU_HAFFANE_KHRIBECH
 *
 *  Provided "as is" free for use and modification, provided credit is given under the
 *  authorization of the authors
 */

#ifndef SORTIE_LOCALE_H_
#define SORTIE_LOCALE_H_

# include "Sortie.h"
#include "GPIO.h"

#include <iostream>
#include <vector>

class Sortie_Locale:Sortie
{
public :
	Sortie_Locale();
	virtual ~Sortie_Locale(){};

	union_type  getUnionSortieLocale() ;
	void  setUnionSortieLocale(union_type) ;

	void  initialization() ;
	void initializationAll();
	void  write() ;
	void writeAll();
	void  termination();

public :
	 union_type union_sortie_locale;
};




#endif /* SORTIE_LOCALE_H_ */
