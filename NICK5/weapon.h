//
//  weapon.h
//  warriors and wizards 1
// xcode
//  Created by Nicholas Genco on 3/4/14.
//  Copyright (c) 2014 Nicholas Genco. All rights reserved.
//

#ifndef WEAPON_h
#define WEAPON_h

#include <string>

using namespace std;

//Weapon Class Definiton

class Weapon

{
    public:
        //constructors
    Weapon();
    Weapon(int wtype, int wdurablity, int wLevelrequired);
    Weapon(Weapon const &);
 
    
    //mutator
    
    void setWType (int wtype);
    void setWDurablity (int wdurablity);
    void setWLevel (int wLevelrequired);
    
    //acessor
    int getWType() const;
    int getWDurablity() const;
    int getWLevel() const;
    
private:
    int type;
    int durablity;
    int Levelrequired;
};



#endif
