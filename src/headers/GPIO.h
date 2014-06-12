/*
 * GPIO.h
 *
 *  Created on: 13 mai 2014
 *      Author: CHKIRROU_HAFFANE_KHRIBECH
 *
 *  Provided "as is" free for use and modification, provided credit is given under the
 *  authorization of the authors
 */


#ifndef GPIO_H_
#define GPIO_H_

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

union union_type {
	struct {
		unsigned long b0 :1;
		unsigned long b1 :1;
		unsigned long b2 :1;
		unsigned long b3 :1;
		unsigned long b4 :1;
		unsigned long b5 :1;
		unsigned long b6 :1;
		unsigned long b7 :1;
		unsigned long b8 :1;
		unsigned long b9 :1;
		unsigned long b10 :1;
		unsigned long b11 :1;
		unsigned long b12 :1;
		unsigned long b13 :1;
		unsigned long b14 :1;
		unsigned long b15 :1;
		unsigned long b16 :1;
		unsigned long b17 :1;
		unsigned long b18 :1;
		unsigned long b19 :1;
		unsigned long b20 :1;
		unsigned long b21 :1;
		unsigned long b22 :1;
		unsigned long b23 :1;
		unsigned long b24 :1;
		unsigned long b25 :1;
		unsigned long b26 :1;
		unsigned long b27 :1;
		unsigned long b28 :1;
		unsigned long b29 :1;
		unsigned long b30 :1;
		unsigned long b31 :1;
	} bit;
	struct {
		unsigned long b0_1 :2;
		unsigned long b2_3 :2;
		unsigned long b4_5 :2;
		unsigned long b6_7 :2;
		unsigned long b8_9 :2;
		unsigned long b10_11 :2;
		unsigned long b12_13 :2;
		unsigned long b14_15 :2;
		unsigned long b16_17 :2;
		unsigned long b18_19 :2;
		unsigned long b20_21 :2;
		unsigned long b22_23 :2;
		unsigned long b24_25 :2;
		unsigned long b26_27 :2;
		unsigned long b28_29 :2;
		unsigned long b30_31 :2;
	} bit_2;
	struct {
		unsigned long b0_3 :4;
		unsigned long b4_7 :4;
		unsigned long b8_11 :4;
		unsigned long b12_15 :4;
		unsigned long b16_19 :4;
		unsigned long b20_23 :4;
		unsigned long b24_27 :4;
		unsigned long b28_31 :4;
	} bit_4;
	struct {
		unsigned long b0_7 :8;
		unsigned long b8_15 :8;
		unsigned long b16_23 :8;
		unsigned long b24_31 :8;
	} bit_8;
	struct {
		unsigned long b0_15 :16;
		unsigned long b16_31 :16;
	} bit_16;

	unsigned long bit_32;
	unsigned char cbit[32];
	//char cbit[32];

};

int export_gpio(string gpionum); // exports GPIO
int unexport_gpio(string gpionum); // unexport GPIO
int setdir_gpio(string dir, string gpionum); // Set GPIO Direction
string getdir_gpio(string gpionum); // Set GPIO Direction
int setval_gpio(long val, string gpionum); // Set GPIO Value (putput pins)
long getval_gpio(string gpionum); // Get GPIO Value (input/ output pins)
template <typename T>
  string NumberToString ( T Number );

#endif /* GPIO_H_ */
