



/*
 ****************************************************************************
 Name: Nicholas Genco
 Date: 3/26/14
 COMSC 110 Computer Programming II
 Assignment: warriors and wizards 3
 File Name: warriors and wizards 3. xcodeproj
 Compiler Used:Xcode
 ****************************************************************************
 
 Problem Statement **********************************************************
 COMSC 110 Computer Programming II Professor Branca
 DESIGNING CLASSES III 50 points
 OBJECTIVES
 Use class inheritance (“is a”, derived class), composition (“has a”, container class), field and base class initialization, polymorphic vector with pointers and virtual functions.
 ANALYSIS AND DESIGN INSTRUCTIONS
 All analysis and design documentation must be in the source code files. It should include data requirements and algorithms for each class and for the main function program.
 DESIGNING AND MODIFYING CLASSES FOR THE WARRIORS AND WIZARDS GAME Player Class and Derived Classes
 Specifications and Changes for Attributes and Methods of the Player Class
  The type property should be removed from the Player class. The methods that manipulate the type property
 should be removed. This includes any references to the type property in the constructors, accessor, mutator,
 read and display functions for the type property.
  The playerName, level, strength and status properties stays in the Player class.
  Move the *weapon1 pointer property to the derived classes. You will need to keep the functions that
 manipulate the weapon object in the Player class as abstract virtual functions that will be implemented in the derived classes, so you can create a polymorphic collection of derived class player objects.
 Specifications for Derived Classes
  Create two derived classes from the Player class (choose 2 of the four types of players used in previous
 assignments – Warrior, Wizard, Vampire and Sorceress)
 o Include appropriate constructors, destructors, mutator, accessor, read and display functions in each
 derived class. Don’t forget base class and field initialization in the constructors.
 o Implement the functions to manipulate the Weapon object that was moved to the derived classes.
 These functions must be the implementations of the abstract virtual functions in the player class. The weapon will now be specific to the derived player type. For example, a Warrior player would be limited to using a sword or fireball weapon. A Wizard might be limited to using staff or sword weapon. If you want to create a new type of weapon specific to the player type you can. Validation for weapon type should be included in to verify that the type of weapon chosen is appropriate for the player type.
 o Add a least one new property to each derived class that is specific to that class. For example, Wizard player objects may have a property that the other classes wouldn’t have, like magic, or Sorceress player objects may have a poison property. Include the necessary functions to manipulate this property. Set a default value that the added property should start at.
 Other Specifications for the Base and Derived Classes.
  The read and display functions for both the base and derived classes should be named the same -- read and
 display.
  Be sure to use virtual functions for any base and derived class functions that have the same name. Do Not Make Any Changes to the Weapon Class at This Time
 ￼￼￼￼￼￼￼￼(Turn Over for Game Simulation Description)
 WARRIOR AND WIZARDS GAME SIMULATION
 Create a C++ program which does the following -- NOT A DRIVER, A COMPLETE PROGRAM. Also note that there
 are additional functions that need to be created.
 This simulation is the same as the previous assignment.
  Use a vector or dynamic array to store pointers to derived class player objects.
  Create a new function which will display a description of the game.
  Create a new function, which will ask the user how many players they want to play the game and validate that
 they enter 0-10. If they enter 0, the game should end. If they enter an invalid number, they should have to enter it
 again.
  Use the new read method to read player data that is entered by the user.
  Use repetition and a random number generation function to simulate game playing.
 Run the following routine at least 20 times on each player that is still active in the game. Do not modify any player whose status is false, which means the player is a loser.
 o Modify each player’s strength value by increasing it or decreasing it randomly (generate random negative and positive numbers, in the range of -20 to +20).
  If player strength is increased by more than 15 points, increase the player level by one (1). o Modify each player’s weapon durability value by increasing it or decreasing it randomly (generate
 random negative and positive numbers, in the range of -10 to +10).
 o Each time a player has been modified, test the property values and implement the following conditions.
  If player’s strength <= 0, the player is out of the game and is a loser—status changes.
  If a player’s weapon durability <= 0, the player is out of the game and is a loser—status
 changes.
  If a player’s strength >= 200 and the weapon durability is > 0, the player wins the game and the
 game is over.
  If there are no winners, the player with the highest player positive strength value > 0 is the winner, all others are
 losers.
  It is possible that there will be no winners – meaning everyone player has a strength value < 0.
  Display the data for the winner if there is one first. If there is no winner, display a message indicating that.
  Display the data for all the losers after the winner.
 ￼￼
 
 Data Requirements **********************************************************
 Input Variables
 int ptype = 0;
 int pstrength = 0;
 int plevel = 0;
 int wtype = 0;
 int wdurability = 0;
 int levelrequired = 0;
 int how many;
 
 Output Variables
 string pplayerName
 int ptype,
 int  plevel,
 int pstrength
 int type;
 int durablity = 25;
 int Levelrequired = 1;
 bool tf
 vector<int> winner1(size)
 int winner;
 
 Processing Variables
 int i
 string garbage
 int size
 int mdurablity
 int mstrength
 
 Relevant Formulas
 
 Algorithm Design ***********************************************************
 
 1.0 Find out how many players are playing
 1.1 if 0 end program
 1.2 Declare vector
 2.0 store default construtor to vector position
 2.1 overwrite default with user imput
 2.2 prompt user to pick type of player 
 2.3 prompt user if they want to change special power
 3.0 Prompt and read/validate player name
 3.1 prompt and read/validate player type
 3.2 prompt and read/validate player strength
 3.3 prompt and read/validate player level
 3.4 prompt and read/validate weapon type
 3.5 prompt and read/validate weapon level
 3.6 prompt and read/validate weapon durablity
 4.1 have random generator function run 20 times and change strength
 4.2 if player strength is generated over +15 player levels up
 4.3 have random generator function run 20 times and change durablity
 4.4 if player strength is over 200 and durablity is over 0 player wins game ends delete pointers
 4.5 if durablity or generator are =<0 kill player
 4.6 determine winner out of alive players
 4.7 if all players are dead cout no winners
 5.0 delete pointers
 
 Testing Specifications *****************************************************
 Welcome to warriors and wizards. This is a game luck, chance and read functions. YOU MAY PASS BUT ONLY IF YOU CAN...!
 
 How many people are going to play?(0-10) 5
 
 Please choose 1 for Vampire or 2 for Warrior1
 
 
 Would like to increase the BLOOD THIRST or leave it at it's default setting? (yes or no )
 1
 1
 Please enter Player name: 1
 Please enter a Player Level. Please Enter a Number (1-100):
 1
 Please enter a Player Strength(1-100):
 1
 Please enter a Weapon Type:
 
 1 = Fangs, 2 =  Bat
 Which one would you like?
 1
 Please enter a Weapon Durablity: (1-100)
 1
 Please enter a Weapon Level: (1-100)
 1
 
 Please choose 1 for Vampire or 2 for Warrior1
 
 
 Would like to increase the BLOOD THIRST or leave it at it's default setting? (yes or no )
 yes
 How much would you like to increase the BLOOD THIRST by (keep in the range from 1 - 20): 20
 Please enter Player name: nick2
 Please enter a Player Level. Please Enter a Number (1-100):
 9
 Please enter a Player Strength(1-100):
 9
 Please enter a Weapon Type:
 
 1 = Sword, 2 =  Bow
 Which one would you like?
 99
 Please enter a Weapon Type:
 
 1 = Sword, 2 =  Bow
 Which one would you like?
 9
 Please enter a Weapon Type:
 
 1 = Sword, 2 =  Bow
 Which one would you like?
 92
 Please enter a Weapon Type:
 
 1 = Sword, 2 =  Bow
 Which one would you like?
 2
 Please enter a Weapon Durablity: (1-100)
 99
 Please enter a Weapon Level: (1-100)
 9
 
 Please choose 1 for Vampire or 2 for Warrior1
 
 
 Would like to increase the BLOOD THIRST or leave it at it's default setting? (yes or no )
 yes
 How much would you like to increase the BLOOD THIRST by (keep in the range from 1 - 20): 20
 Please enter Player name: nick3
 Please enter a Player Level. Please Enter a Number (1-100):
 99
 Please enter a Player Strength(1-100):
 99
 Please enter a Weapon Type:
 
 1 = Sword, 2 =  Bow
 Which one would you like?
 99
 Please enter a Weapon Type:
 
 1 = Sword, 2 =  Bow
 Which one would you like?
 2
 Please enter a Weapon Durablity: (1-100)
 99
 Please enter a Weapon Level: (1-100)
 99
 
 Please choose 1 for Vampire or 2 for Warrior99
 Please choose 1 for Vampire or 2 for Warrior2
 
 
 Would like to increase the ADRENALIN or leave it at it's default setting? (yes or no)
 no
 
 Please enter Player name: 90
 Please enter a Player Level. Please Enter a Number (1-100):
 90
 Please enter a Player Strength(1-100):
 0
 Please enter a Player Strength(1-100):
 90
 Please enter a Weapon Type:
 
 1 = Sword, 2 =  Bow
 Which one would you like?
 2
 Please enter a Weapon Durablity: (1-100)
 90
 Please enter a Weapon Level: (1-100)
 90
 
 Please choose 1 for Vampire or 2 for Warrior2
 
 
 Would like to increase the ADRENALIN or leave it at it's default setting? (yes or no)
 2
 2
 2Please enter Player name: 2
 Please enter a Player Level. Please Enter a Number (1-100):
 2
 Please enter a Player Strength(1-100):
 2
 Please enter a Weapon Type:
 
 1 = Sword, 2 =  Bow
 Which one would you like?
 2
 Please enter a Weapon Durablity: (1-100)
 2
 Please enter a Weapon Level: (1-100)
 2
 
 This player is dead:
 
 1. Name: 1
 Player Strength: 78
 Player Level: 1
 Weapon Type: 1
 Weapon Durability: -1
 Weapon Level: 1
 Player Status: 0
 
 winner
 Name: nick2
 Player Strength: 405
 Player Level: 10
 Weapon Type: 2
 Weapon Durability: 113
 Weapon Level: 9
 Player Status: 1
 
 Press enter once or twice to end program.

 // Compiler directives : libraries and namespaces **************************
 
 */

#include "player.h"
#include "warrior.h"
#include "vampire.h"
#include "weapon.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

int winners(vector<Player *> players, int &winner);//winner function

void description();//description function

bool operator >=(Player& p1, Player& p2);

Player& operator += (Player&, Player&);

int main()
{
    
	srand(time(0));
	
	int howmany = 0, winner = 0;//intaliazing variables
    
	description();
    
	int p;
    
	string garbage;
    
	//declaring vector with size 3
	vector<Player*> pl;
	
	vector<int> winner1;//declaring winner vector
    
    
    do
    
	{
    
		cout<<"How many people are going to play?(0-10) ";//prompt and reading how many players
        
		cin>>howmany;
    
	}while(howmany < 0 || howmany > 10);
    
    
	
    
    getline(cin, garbage);//clearing garbage
    
    cout<<endl;
    
    if(howmany > 0)//if howmany is greater then 0 run program
    
	{
        
		for (int i = 0; i < howmany; ++i) //adding players to the vector
        
		{  
		
		do
        
		{
    
		cout<<"Please choose 1 for Vampire or 2 for Warrior";
        
		cin>>p;
        
	}while(p < 1 || p > 2);
        
      
	if (p == 2)
        
	{
	
            pl.push_back(new Warrior());//player equals defualt
            
			cin >> pl[i];
           
        }
        
	else
        
	{
		    pl.push_back(new Vampire);//player equals defualt
            
			cin >> pl[i];
    }
   
        
    }
       
        
        winners(pl, winner);//sending to winner function
        
        for (int i = 0; i<howmany; ++i)//clearing pointers using destructor
        {
            
        pl[i]->~Player();
        }
        cout << "Press enter once or twice to end program.";//end pf program statements
        cin.ignore().get();
        return EXIT_SUCCESS;
}
    else
{
    cout<< "Program ended"<<endl;
    //end of program statements
   
    cout << "Press enter once or twice to end program.";
    cin.ignore().get();
    return EXIT_SUCCESS;
    
}
    
	
}

void description()//description function

{

	cout<<"Welcome to warriors and wizards. This is a game luck, chance and read functions. YOU MAY PASS BUT ONLY IF YOU CAN...!"<< endl <<endl;

}


int winners(vector<Player *> pl, int &winner)
{
    
	
	winner=0;//winner equals 0
	int size = pl.size();//intalizing size so i dont have to keep calling function
    
	for(int i = 0;i < size;i++)
    {
        int pstrength = pl[i]->getStrength();
        int pwdurab = pl[i]->get_weapon_durab();
        
        if(pstrength >= 200)
    	{
            if(pwdurab>0)
            {
                cout<<"WINNER:"<<endl<<endl;//display winner
            cout << pl[i];
           
           
            cout << endl;
            pl[i]->~Player();//clearing vector
            
            cout << "Press enter once or twice to end program.";//end of program statments
            cin.ignore().get();
            return EXIT_SUCCESS;
            
            }
            
		}
    	
    else if(pl[i]->getBool()==0)//if player is dead he is being displayed
        
        {
        
            cout << "This player is dead: " << endl << endl;
            
            cout << i+1 << ". " ;
            
            
            cout << pl[i];
            
            cout << endl;
        }
        
    else if(pl[i]->getBool()==1)//if player is alive he is being displayed
    {
        winner=winner+1;//loop is being counted for all alive players
        cout << "This player is alive: " << endl << endl;
        
        cout << i+1 << ": " ;
        
        
       cout << pl[i];
        
        cout << endl;
    }
	
	
    }
    
if(winner >= 2)//if there is more then one winner if statement it being run
        
{
        vector<int> winner1(size);//new vector
        for(int i = 0; i < size; i++)//intalizing new vector of ints with player strengths
            
		{
            winner1[i]= pl[i]->getStrength();
	    }
        
        sort(winner1.begin(),winner1.end());//sorting vector
        for(int i = 0; i < size; i++)//if player strength equals amount of vector he has won
        {
            
            {
            if(pl[i]->getStrength() == winner1[size-1])
                {
                if (pl[i]->getBool()==1)
                {
                    cout<<"Multiple Winners: Player With Highest Strength and still alive is:"<<endl<<endl;
                   
					cout << pl[i];
                    
					break;
                }
                //break if more then one player has same strength
                }
            size=size-1;
            }
        }
    if (winner ==0)
        {
        cout<<" There are no winners: Play Again!";
        }
    }
    
	for (int i = 0; i < size; i++)//clearing using desrtuctor

	{
		pl[i]->~Player();

	}
    cout <<endl<< "Press enter once or twice to end program.";//end pf program statments
    cin.ignore().get();
    return EXIT_SUCCESS;


}

bool operator >=(Player& p1, Player& p2)
{

	if (p1.getStrength() >= p2.getStrength())
		return true;
	else
		return false;

}

Player& operator +=(Player& p1, Player& p2)
{

	p1.setStrength(p1.getStrength() + p2.getStrength());

	return p1;

}