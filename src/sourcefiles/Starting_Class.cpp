/*
 * Starting_Class.cpp
 *
 *  Created on: 14 mai 2014
 *      Author: youssef
 */

#include <stdlib.h>
#include <iostream>

#include "../headers/Coeur.h"

using namespace std;

int main() {
	Coeur coeur;
	//thread first (WatchMe());
	//first.join();
	coeur.initialization();
	coeur.execution();
}

