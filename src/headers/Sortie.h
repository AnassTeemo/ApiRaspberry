/*
 * Sortie.h
 *
 *  Created on: 13 mai 2014
 *      Author: CHKIRROU_HAFFANE_KHRIBECH
 *
 *  Provided "as is" free for use and modification, provided credit is given under the
 *  authorization of the authors
 */

#ifndef SORTIE_H_
#define SORTIE_H_

class Sortie
{
public:
	virtual ~Sortie(){};
	void virtual write() =0;
	void virtual initialization() =0;
	void virtual termination()=0;
};




#endif /* SORTIE_H_ */
