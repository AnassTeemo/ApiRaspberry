/*
 * Coeur.cpp
 *
 *  Created on: 14 mai 2014
 *      Author: youssef
 */





#include "../headers/Coeur.h"
#include "../headers/GPIO.h"
#include "../headers/Calcul.h"
#include "../headers/Calcul_GPIO.h"
#include "../headers/Calcul_Carrefour.h"
#include "../headers/Calcul_Chenillard.h"
#include <signal.h>
#include <pthread.h>


//Calcul calcul;
#ifdef GPIO
Calcul_Gpio calcul_gpio;
#endif
#ifdef CARREFOUR
Calcul_Carrefour calcul_Carrefour;
#endif
#ifdef CHENILLARD
Calcul_Chenillard calcul_chenillard;
#endif


enum state {
	Initialisation, Execution, ReadAll,WriteAll,Done
};
state current_state;

pthread_mutex_t timer_mutex;
pthread_cond_t timer_condition_variable;

pthread_t threadTimer;
pthread_t threadExecution;

Coeur::Coeur() {
}

void Coeur::initialization() {
	//calcul.initialization();
}

void verification(int sig) {
	if (current_state != 4) {
		pthread_cond_signal(&timer_condition_variable);
		pthread_mutex_unlock(&timer_mutex);
	} else {
		signal(SIGALRM, verification);
		#ifdef CARREFOUR
		alarm(1);
		current_state = WriteAll;
		calcul_Carrefour.writeAll();
		current_state = Done;
		#endif

		#ifdef GPIO
		alarm(6);
		current_state = ReadAll;
		calcul_gpio.readAll();
		current_state = Execution;
		cout << "Phase Execution " << endl;
		calcul_gpio.execution();
		current_state = WriteAll;
		calcul_gpio.writeAll();
		current_state = Done;
		#endif

		#ifdef CHENILLARD
		alarm(5);
		current_state = WriteAll;
		calcul_chenillard.writeAll();
		current_state = Done;
		#endif
	}
}

void *thread_execution(void *arg) {
	printf("Nous sommes dans le thread_execution.\n");

	signal(SIGALRM, verification);
	alarm(1);
	cout << "Initialisation !! " << endl;
	current_state = Initialisation;
	cout << "Phase initialisation !! " << endl;

	#ifdef GPIO
	calcul_gpio.initialization();
	#endif

	#ifdef CARREFOUR
	calcul_Carrefour.initialization();
	#endif

	#ifdef CHENILLARD
	calcul_chenillard.initialization();
	#endif

	current_state = Done;
	cout << "Current State in thread_execution : " << current_state << endl;
	pthread_mutex_lock(&timer_mutex);
	pthread_cond_wait(&timer_condition_variable, &timer_mutex);
	cout << "Exit due to indeterminated issue !!" << endl;
	//calcul.sortie.termination();
	//calcul.entree.termination();
	//calcul.sortie.write();

	/* Pour enlever le warning */
	pthread_exit(NULL);
}

void Coeur::execution() {

	if (pthread_create(&threadExecution, NULL, thread_execution, NULL)) {
		perror("pthread_execution_create");
	}

	if (pthread_join(threadExecution, NULL)) {
		perror("pthread_execution_join");
	}

}

