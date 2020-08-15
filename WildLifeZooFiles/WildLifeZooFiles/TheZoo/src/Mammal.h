/*
 * Mammal.h
 *
 *  Created on: Aug 14, 2020
 *      Author: 1750932_snhu
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_

#include "Animal.h"

class Mammal: public Animal {
public:
	Mammal();
	void SetNurse(int t_nurse);
};

#endif /* MAMMAL_H_ */
