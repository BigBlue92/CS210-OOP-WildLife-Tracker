/*
 * Animal.h
 *
 *  Created on: Aug 13, 2020
 *      Author: 1750932_snhu
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>
using namespace std;

class Animal {
public:
	Animal();
	void SetTrack(string t_track);
	void SetName(string t_name);
	void SetType(string t_Type);
	void SetSubtype(string t_subtype);
	string GetTrack();
	string GetName();
	string GetType();
	string GetSubtype();
	int GetNurse();
	int GetEggs();
protected:
	string m_track = "-1";
	string m_name = "";
	string m_type = "";
	string m_subtype = "";
	int m_eggs = 0;
	int m_nurse = 0;
};

#endif /* ANIMAL_H_ */
