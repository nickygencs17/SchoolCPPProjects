//
//  player.h
//  warriors and wizards 1
//
//  Created by Nicholas Genco on 3/4/14.
//  Copyright (c) 2014 Nicholas Genco. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include "weapon.h"
#include <string>


using namespace std;


class Player
{
    public:
    
		//constructors
    
		Player();
    
		Player(string pplayerName, int  plevel, int pstrength);
    
		~Player();

    
    //mutator
    
		void setWeapon(Weapon pweapon1);
    
		void setPlayerName(string pplayerName);
    
		void setLevel(int plevel);
    
		void setStrength(int pstrength);
    
		void setBool(bool tf1);
	
		virtual void set_weapon_type(int);
	
		virtual void set_weapon_durab(int);
	
		virtual void set_weapon_level(int);

    //acessor
    
   virtual int get_weapon_type();
   virtual int get_weapon_durab();
   virtual int get_weapon_level();
    string getName();
    int getStrength();
    int getLevel();
    bool getBool();
    
    // Validation Function

	virtual void ReadData();
 
	virtual void ReadData(int);
 
    virtual void ReadData(int p, int pt);



    //Read Function
   virtual  void display();
    
    private:
    
    Weapon * weapon1;
    
	string Playername;
    
	int randGenerator1();
    
	int randGenerator2();
	
	void Validation(int, int);
    
	int level;
    
	int strength;
    
	bool tf;
	
	Player& operator = (Player& p)
	{

		Playername = p.Playername;

		strength = p.strength;

		level = p.level;

		tf = p.tf;

		weapon1 = p.weapon1;

		return *this;

	}
	
	friend ostream& operator << (ostream& out, Player* p);
	
	friend istream& operator >> (istream& in, Player* p);


};

#endif