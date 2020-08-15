/*
 * Animal.cpp
 *
 *  Created on: Aug 13, 2020
 *      Author: 1750932_snhu
 */

#include "Animal.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Animal::Animal() {
   // TODO Auto-generated constructor stub
}
void Animal::SetTrack(string t_track) {
	//below sets track# to 6 digits.
    t_track.insert(t_track.begin(), 6 - t_track.length(), '0');
	m_track = t_track;
}

void Animal::SetName(string t_name){
	//Makes it so name takes up 15 characters
    m_name = t_name.append(16 - t_name.length(), ' ');
}

void Animal::SetType(string t_type){
	m_type = t_type.append(16 - t_type.length(), ' ');
}

void Animal::SetSubtype(string t_subtype){
	m_subtype = t_subtype.append(16 - t_subtype.length(), ' ');
}

string Animal::GetTrack() {
	return m_track;
}

string Animal::GetName() {
	return m_name;
}

string Animal::GetType() {
	return m_type;
}

string Animal::GetSubtype() {
	return m_subtype;
}

int Animal::GetNurse(){
	return m_nurse;
}
int Animal::GetEggs() {
	return m_eggs;
}
