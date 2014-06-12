/*
 * GPIO.cpp
 *
 *  Created on: 15 mai 2014
 *      Author: farid
 */

#include "../headers/GPIO.h"

int export_gpio(string gpionum) {
	string export_str = "/sys/class/gpio/export";
	ofstream exportgpio(export_str.c_str()); // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
	if (exportgpio < 0) {
		cout << " OPERATION FAILED: Unable to export GPIO" << gpionum << " ."
				<< endl;
		return -1;
	}

	exportgpio << gpionum; //write GPIO number to export
	exportgpio.close(); //close export file
	return 0;
}

int unexport_gpio(string gpionum) {
	string unexport_str = "/sys/class/gpio/unexport";
	ofstream unexportgpio(unexport_str.c_str()); //Open unexport file
	if (unexportgpio < 0) {
		cout << " OPERATION FAILED: Unable to unexport GPIO" << gpionum << " ."
				<< endl;
		return -1;
	}

	unexportgpio << gpionum; //write GPIO number to unexport
	unexportgpio.close(); //close unexport file
	return 0;
}

int setdir_gpio(string dir, string gpionum) {
	string setdir_str = "/sys/class/gpio/gpio" + gpionum + "/direction";
	ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
	if (setdirgpio < 0) {
		cout << " OPERATION FAILED: Unable to set direction of GPIO" << gpionum
				<< " ." << endl;
		return -1;
	}

	setdirgpio << dir; //write direction to direction file
	setdirgpio.close(); // close direction file
	return 0;
}

int setval_gpio(long val, string gpionum) {
	string setval_str = "/sys/class/gpio/gpio" + gpionum + "/value";
	ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
	if (setvalgpio < 0) {
		cout << " OPERATION FAILED: Unable to set the value of GPIO" << gpionum
				<< " ." << endl;
		return -1;
	}


	setvalgpio << NumberToString(val); //write value to value file
	setvalgpio.close(); // close value file
	return 0;
}

long getval_gpio(string gpionum) {

	long val;
	string getval_str = "/sys/class/gpio/gpio" + gpionum + "/value";
	ifstream getvalgpio(getval_str.c_str()); // open value file for gpio
	if (getvalgpio < 0) {
		cout << " OPERATION FAILED: Unable to get value of GPIO" << gpionum
				<< " ." << endl;
		return -1;
	}

	getvalgpio >> val;  //read gpio value

	if (val != 0)
		val = 1;
	else
		val = 0;

	getvalgpio.close(); //close the value file
	return val;
}

string getdir_gpio(string gpionum) {

	string val;

	string getval_str = "/sys/class/gpio/gpio" + gpionum + "/direction";
	ifstream getvalgpio(getval_str.c_str()); // open value file for gpio
	if (getvalgpio < 0) {
		cout << " OPERATION FAILED: Unable to get value of GPIO" << gpionum
				<< " ." << endl;
		return "-1";
	}

	getvalgpio >> val;  //read gpio value

	getvalgpio.close(); //close the value file
	return val;
}

template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

