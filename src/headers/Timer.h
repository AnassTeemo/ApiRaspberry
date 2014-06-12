/*
 * Timer.h
 *
 *  Created on: 13 mai 2014
 *      Author: CHKIRROU_HAFFANE_KHRIBECH
 *
 *  Provided "as is" free for use and modification, provided credit is given under the
 *  authorization of the authors
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <ctime>

class Timer {
public :
	Timer(){};
	virtual ~Timer(){};

	int SetTimer(struct timeval &tv, time_t sec);
	int CheckTimer(struct timeval &tv, time_t sec);
};




#endif /* TIMER_H_ */
