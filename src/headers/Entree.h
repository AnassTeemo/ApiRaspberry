/*
 * Entree.h
 *
 *  Created on: 13 mai 2014
 *      Author: CHKIRROU_HAFFANE_KHRIBECH
 *
 *  Provided "as is" free for use and modification, provided credit is given under the
 *  authorization of the authors
 */

#ifndef ENTREE_H_
#define ENTREE_H_


#include "GPIO.h"

class Entree
{
public :
	virtual ~Entree(){};
	void virtual read() =0;
	void virtual initialization() =0;
	void virtual termination()=0;

};





#endif /* ENTREE_H_ */
