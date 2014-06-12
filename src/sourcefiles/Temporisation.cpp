/*
 * Temporisation.cpp
 *
 *  Created on: 30 mai 2014
 *      Author: youssef
 */

#include "../headers/Temporisation.h"

Temporisation::Temporisation(int _delay):
finish(false),tempo(0),delay(_delay)
{

}

bool Temporisation::test()
{
	tempo++;
	if(tempo>=delay)
	{
		tempo=0;
		finish=true;

	}

	return finish;
}


void Temporisation::initialization()
{
	finish=false;
	tempo=0;
}


