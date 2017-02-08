
//  warrior.cpp
//  warriors and wizards 3
//
//  Created by Nicholas Genco on 4/10/14.
//  Copyright (c) 2014 Nicholas Genco. All rights reserved.
//

#include "vampire.h"
#include <iostream>
#include <string>

using namespace std;




Vampire::Vampire()

{

	blood_thirst = 0;

}

Vampire::~Vampire()

{
	if (weapon2 != NULL)
	{

		delete weapon2;

		weapon2 = NULL;
	}

}

Vampire::Vampire(string name, int level, int strength, int extra_powers)

:Player(name, level, strength)

{
	blood_thirst = extra_powers;

}

int Vampire::get_weapon_type()

{

	return weapon2->getWType();

}

int Vampire::get_weapon_durab()const

{

	return weapon2->getWDurablity();

}

int Vampire::get_weapon_level()

{

	return weapon2->getWLevel();

}

void Vampire::set_weapon_type(int newType)

{

	weapon2->setWType(newType);

}

void Vampire::set_weapon_durab(int newDur)

{

	weapon2->setWDurablity(newDur);

}

void Vampire::set_weapon_level(int newLev)

{

	weapon2->setWLevel(newLev);

}

void Vampire::ReadData()

{

string answer, garbage;

int supplement = 0;
cout << endl << endl;

cout << "Would like to increase the BLOOD THIRST or leave it at it's default setting? (yes or no )" << endl;

cin >> answer;
getline(cin, garbage);

if (answer == "yes" || answer == "Yes" || answer == "YES")

{

	do

	{

		cout << "How much would you like to increase the BLOOD THIRST by (keep in the range from 1 - 20): "<<endl;

		cin >> supplement;

	} while ((supplement <= 0) || (supplement > 20));

	blood_thirst += supplement;

	Player::ReadData(blood_thirst, 2);

}

else

{

	

	Player::ReadData(1);

}



}

void Vampire::display()

{

	cout << "Name: " << Player::getName() << endl;
	cout << "Player Strength: " << Player::getStrength() << endl;
	cout << "Player Level: " << Player::getLevel() << endl;
	cout << "Weapon Type: " << Player::get_weapon_type() << endl;
	cout << "Weapon Durability: " << Player::get_weapon_durab() << endl;
	cout << "Weapon Level: " << Player::get_weapon_level() << endl;
	cout << "Player Status: " << Player::getBool() << endl;

}