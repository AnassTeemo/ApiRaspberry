/*
 * Timer.cpp
 *
 *  Created on: May 16, 2014
 *      Author: anass
 */

#include "../headers/Timer.h"
#include<sys/time.h>
#include<stdio.h>

int Timer::SetTimer(struct timeval &tv, time_t sec)
{
    gettimeofday(&tv,NULL);
    tv.tv_sec+=sec;

    return 1;
}

int Timer::CheckTimer(struct timeval &tv, time_t sec)
{
    struct timeval ctv;
    gettimeofday(&ctv,NULL);

    if( (ctv.tv_sec > tv.tv_sec) )
    {
        gettimeofday(&tv,NULL);
        tv.tv_sec+=sec;
        return 1;
    }
    else
        return 0;
}


