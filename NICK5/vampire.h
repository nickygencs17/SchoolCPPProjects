//  vampire.h
//  warriors and wizards 3
//
//  Created by Nicholas Genco on 4/10/14.
//  Copyright (c) 2014 Nicholas Genco. All rights reserved.


#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "player.h"

#include "weapon.h"

#include <string>

using namespace std;


class Vampire : public Player
{

public:

	Vampire();

	~Vampire();

	Vampire(string, int, int, int);

	void ReadData();

	//Mutator Functions

	void setPower(int);

	virtual void set_weapon_type(int);
	
	virtual void set_weapon_durab(int);
	
	virtual void set_weapon_level(int);

	//Acessor Functions

	virtual int get_weapon_type();
	
	virtual int get_weapon_durab() const;
	
	virtual int get_weapon_level();

	int getPower();

	void display();
    
private:
    
	int blood_thirst;
    
	Weapon * weapon2;
    
};
#endif

