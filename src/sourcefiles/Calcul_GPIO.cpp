/*
 * Calcul_Gpio.cpp
 *
 *  Created on: 27 mai 2014
 *      Author: youssef
 */

#include "../headers/Calcul_GPIO.h"
#include "../headers/Sortie_Locale.h"
#include <pthread.h>
#include <cmath>

Entree_Distante entree_distante;
pthread_t t1;
pthread_mutex_t timer_mutexs;
pthread_cond_t timer_condition_variables;

Calcul_Gpio::Calcul_Gpio():tempo(5) {

}

void Calcul_Gpio::initialization() {
	entree_distante.union_Entree_Distante.bit_32 = 0;
	entree_distante.initialization();
	sortie.union_sortie_locale.bit_32 = 0;
	sortie.initializationAll();
	sortie.writeAll();
	front_montant.initialization();
}

void *thread_Entree_Distant(void *arg) {
	pthread_mutex_lock(&timer_mutexs);
	pthread_cond_wait(&timer_condition_variables, &timer_mutexs);
	entree_distante.read();
	pthread_exit(NULL);
}

void Calcul_Gpio::readAll() {
	pthread_create(&t1, NULL, thread_Entree_Distant, NULL);
	////pthread_join(t1, NULL);

}

void Calcul_Gpio::execution() {

	if(sortie.union_sortie_locale.bit_32 ==
			entree_distante.union_Entree_Distante.bit_32)
	{
		if(tempo.test())
		{
			sortie.union_sortie_locale.bit_32=0;
			tempo.initialization();
			std::cout<<"On est dans le cas tempo passé: "<<sortie.union_sortie_locale.bit_32<<std::endl;
		}
	}
	else

		{
			tempo.initialization();
			sortie.union_sortie_locale.bit_32 =
			entree_distante.union_Entree_Distante.bit_32;
			std::cout<<"on recommence : "<<sortie.union_sortie_locale.bit_32<<std::endl;
		}




	front_montant.union_present.bit_32 = sortie.union_sortie_locale.bit_32  ;
	front_montant.detection();

}

void Calcul_Gpio::writeAll() {

	sortie.writeAll();
}
