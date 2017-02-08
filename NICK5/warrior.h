//
//  warrior.h
//  warriors and wizards 3
//
//  Created by Nicholas Genco on 4/10/14.
//  Copyright (c) 2014 Nicholas Genco. All rights reserved.
//

#ifndef WARRIOR_H
#define WARRIOR_H

#include "player.h"
#include "weapon.h"

#include <string>

using namespace std;

class Warrior : public Player

{

public:
    
	Warrior();

	~Warrior();
    
	Warrior(string, int, int, int);
	
	void ReadData();

	//Mutator Functions

	void set_power(int);

	virtual void set_weapon_type(int);

	virtual void set_weapon_durab(int);

	virtual void set_weapon_level(int);

	//Acessor Functions

	virtual int get_weapon_type();

	virtual int get_weapon_durab() const;

	virtual int get_weapon_level();

	int get_power();
	
	void display();
    
private:
    
	int adrenalin;
    
	Weapon * weapon2;
    
};
#endif