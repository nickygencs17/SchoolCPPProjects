//compliar directives

#include "weapon.h"
#include "player.h"
#include <string>
#include <iostream>

using namespace std;

//constructors

Player::Player()//default
{
 
    
    level = 1;
    
    strength = 25;
    
    weapon1 =  new Weapon(1, 1, 25);
    
    tf=true;
    
    
    
}

Player::Player(string pplayerName, int  plevel, int pstrength)//with parameters

{

    Playername = pplayerName;
    
    level = plevel;
    
    strength = pstrength;
    
    tf=true;

}
Player::~Player()//destructor
{
    
    if(weapon1 != NULL)
        
    {
        
        delete weapon1;
        
        weapon1 = NULL;
        
    }
    

    
}


//mutator fucntions

void Player::setWeapon(Weapon pweapon1)

{

    weapon1 = new Weapon(pweapon1);
    
}

void Player::setPlayerName(string pplayerName)

{

    Playername = pplayerName;
    
}



void Player::setLevel(int plevel)

{

    level = plevel;

}

void Player::setStrength(int pstrength)
{
    strength=pstrength;
}

void Player::setBool(bool tf1)
{
    tf= tf1;
}

//acessor functions

int Player::get_weapon_type()

{

	return weapon1->getWType();

}

int Player::get_weapon_durab()

{

	return weapon1->getWDurablity();

}

int Player::get_weapon_level()

{

	return weapon1->getWLevel();

}

void Player::set_weapon_type(int newType)

{

	weapon1->setWType(newType);

}

void Player::set_weapon_durab(int newDur)

{

	weapon1->setWDurablity(newDur);

}

void Player::set_weapon_level(int newLev)

{

	weapon1->setWLevel(newLev);

}

string Player::getName()
{
    return Playername;
}

int Player::getStrength()
{
    return strength;
}
int Player::getLevel()
{
    return level;
}
bool Player::getBool()
{
    return tf;
}

void Player::ReadData()

{


}


void Player::ReadData(int p, int pt)

{
	//declaring data types

	int pstrength = 0;
	int plevel = 0;
	int wdurability = 0;
	int wtype = 0;
	int levelrequired = 0;
	string garbage;
    getline(cin,garbage);

	cout << "Please enter Player name: ";//read and prompt player name
	getline(cin, Playername);




	do //validate/read and prompt player level
	{
		cout << "Please enter a Player Level. Please Enter a Number (1-100): " << endl;
		cin >> plevel;
		level = plevel;

	} while (plevel < 1 || plevel > 100);

	do
	{

		cout << "Please enter a Player Strength(1-100): " << endl;
		cin >> strength;


	} while (strength < 1 || strength > 100);

	if (pt == 2)

	{

		do {//validate/read and prompt weapon type

			cout << "Please enter a Weapon Type: " << endl;
			cout << endl << "1 = Sword, 2 =  Bow " << endl;
			cout << "Which one would you like? " << endl;

			cin >> wtype;

		} while ((wtype < 1 || wtype > 2));

	}
	
	if(pt == 1)
	
	{
	
	 do 
	 
	 {//validate/read and prompt weapon type
	
	cout<<"Please enter a Weapon Type: "<<endl;
	cout<<endl<<"1 = Fangs, 2 =  Bat "<<endl;
	cout<< "Which one would you like? "<<endl;
	
	cin >> wtype;


	} while((wtype < 1 || wtype > 2) );
	
	}
	

	do

	{
		cout << "Please enter a Weapon Durablity: (1-100)" << endl;
		cin >> wdurability;

	} while (wdurability < 1 || wdurability > 100);


	do//validate/read and prompt level required

	{

		cout << "Please enter a Weapon Level: (1-100)" << endl;
		cin >> levelrequired;
		cout << endl;

	} while (levelrequired < 1 || levelrequired > 100);

	getline(cin, garbage);//collecting junk

	for (int i = 0; i < 20; ++i)//calling random generator and adding it to total strength
	{
        pstrength=randGenerator1();
        
		if (pstrength <= 15)
		{
			level++;
		}

		strength = strength + pstrength + p;

		wdurability = wdurability + randGenerator2();

	}

	Validation(strength, wdurability);

	weapon1 = new Weapon(wtype, wdurability, levelrequired);//making weapon
    
 
 
}




	 void Player::ReadData(int pt)

	 {
		 //declaring data types
         int strengthr = 0;
		 int pstrength = 0;
		 int plevel = 0;
		 int wdurability = 0;
		 int wtype = 0;
		 int levelrequired = 0;
		 string garbage;
         getline(cin,garbage);

		 cout << "Please enter Player name: ";//read and prompt player name
		 getline(cin, Playername);


		 do //validate/read and prompt player level
		 {
			 cout << "Please enter a Player Level. Please Enter a Number (1-100): " << endl;
			 cin >> plevel;
			 level = plevel;

		 } while (plevel < 1 || plevel > 100);

		 do
		 {

			 cout << "Please enter a Player Strength(1-100): " << endl;
			 cin >> strength;


		 } while (strength < 1 || strength > 100);

		 if (pt == 2)

		 {

			 do {//validate/read and prompt weapon type

				 cout << "Please enter a Weapon Type: " << endl;
				 cout << endl << "1 = Sword, 2 =  Bow " << endl;
				 cout << "Which one would you like? " << endl;

				 cin >> wtype;

			 } while ((wtype < 1 || wtype > 2));

		 }

		 if (pt == 1)

		 {

			 do

			 {//validate/read and prompt weapon type

				 cout << "Please enter a Weapon Type: " << endl;
				 cout << endl << "1 = Fangs, 2 =  Bat " << endl;
				 cout << "Which one would you like? " << endl;

				 cin >> wtype;


			 } while ((wtype < 1 || wtype > 2));

		 }

		 do

		 {
			 cout << "Please enter a Weapon Durablity: (1-100)" << endl;
			 cin >> wdurability;

		 } while (wdurability < 1 || wdurability > 100);


		 do//validate/read and prompt level required

		 {

			 cout << "Please enter a Weapon Level: (1-100)" << endl;
			 cin >> levelrequired;
			 cout << endl;

		 } while (levelrequired < 1 || levelrequired > 100);

		 getline(cin, garbage);//collecting junk

		 for (int i = 0; i < 20; ++i)//calling random generator and adding it to total strength
		 {
             strengthr=randGenerator1();
			 strength = strength + strengthr;

			 if (strengthr <= 15)
			 {
				 level++;
			 }

			 wdurability = wdurability + randGenerator2();

		 }

		 Validation(strength, wdurability);
	 
		 weapon1 = new Weapon(wtype, wdurability, levelrequired);//making weapon
}


void Player::display()//display function

{

cout<<"Name: "<<   getName()<<endl;
cout<<"Player Strength: "<<getStrength()<<endl;
cout<<"Player Level: " <<getLevel()<<endl;
cout << "Weapon Type: " << get_weapon_type() << endl;
cout<<"Weapon Level: "<< get_weapon_level() << endl;
cout<<"Weapon Durablity: "<< get_weapon_durab() << endl;
cout<<"Player Status: "<<getBool()<<endl;

}

int Player::randGenerator1()//rand generator 1

    {
        int minNum = -20;
        int maxNum = 20;
        int x;
        
        x = minNum + rand() % (maxNum - minNum + 1);
        
        return x;
        
    }

int Player::randGenerator2()//rand generator 2

{
    int minNum = -10;
    int maxNum = 10;
    int x;
    
    x = minNum + rand() % (maxNum - minNum + 1);
    
    return x;
}

void Player::Validation(int str, int dur)
{
	if (str > 0 && dur > 0)
	{
		tf = 1;
	}

	else
    {
		tf = 0;

	}

}


istream& operator >> (istream& in, Player* p)
{

	p->ReadData();

	return in;
}

ostream& operator << (ostream& out, Player* p)
{
	/*
	out << "Name: " << p.getName() << endl;
	out << "Player Strength: " << p.getStrength() << endl;
	out << "Player Level: " << p.getLevel() << endl;
	out << "Weapon Type: " << p.get_weapon_type() << endl;
	out << "Weapon Level: " << p.get_weapon_level() << endl;
	out << "Weapon Durablity: " << p.get_weapon_durab() << endl;
	out << "Player Status: " << p.getBool() << endl;
	
	*/

	p->display();

	return out;

}