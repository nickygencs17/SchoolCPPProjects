//
//  weapon.cpp
//  warriors and wizards 1
// xcode
//  Created by Nicholas Genco on 3/4/14.
//  Copyright (c) 2014 Nicholas Genco. All rights reserved.
//

#include "weapon.h"


#include <string>

using namespace std;

//constructor

Weapon::Weapon()
{
    type = 1;
    durablity = 25;
    Levelrequired = 1;
}
Weapon::Weapon( int wtype, int wdurablity, int wLevelrequired)
{
    type = wtype;
    durablity = wdurablity;
    Levelrequired = wLevelrequired;
}
Weapon::Weapon(Weapon const & w2)
{
    type=w2.type;
    durablity=w2.durablity;
    Levelrequired=w2.Levelrequired;
    
    
}

//mutator functions
void Weapon::setWType (int wtype)
{
    type=wtype;
    
}
void Weapon::setWDurablity (int wdurablity)
{
    durablity=wdurablity;
}
void Weapon::setWLevel (int wLevelrequired)
{
    Levelrequired=wLevelrequired;
}

//accessor functions

int Weapon::getWType() const
{
    return type;
}
int Weapon::getWDurablity() const
{
    return durablity;
}

int Weapon::getWLevel() const
{
    return Levelrequired;
}

