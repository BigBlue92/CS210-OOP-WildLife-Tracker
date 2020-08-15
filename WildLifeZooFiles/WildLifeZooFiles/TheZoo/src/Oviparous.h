/*
 * Oviparous.h
 *
 *  Created on: Aug 13, 2020
 *      Author: 1750932_snhu
 */

#ifndef OVIPAROUS_H_
#define OVIPAROUS_H_

#include "Animal.h"

class Oviparous: public Animal {
public:
	Oviparous();
	void SetEggs(int t_eggs);
	virtual ~Oviparous();
};

#endif /* OVIPAROUS_H_ */
