/*
 * Temporisation.h
 *
 *  Created on: 30 mai 2014
 *      Author: youssef
 */

#ifndef TEMPORISATION_H_
#define TEMPORISATION_H_

class Temporisation{
public :
	Temporisation(int );
	~Temporisation(){};
	bool test();
	void initialization();
private :
	bool finish;
	int tempo;
	int delay;
};



#endif /* TEMPORISATION_H_ */
