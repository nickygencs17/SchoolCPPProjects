//
//  VechicleV.cpp
//  project1DS
//
//  Created by Nicholas Genco on 9/10/14.
//  Copyright (c) 2014 ___NickGencoDEV___. All rights reserved.
//

#include<iostream>
#include<string>
#include"vechicleV.h"
#include<cassert>


using namespace vechicle;

vechicleV::vechicleV()
{
    speedUnits = 'm';
    speed1 = 0.00;
    name1 = " ";
}
vechicleV::vechicleV(char su, float s,std::string n)
{
    speedUnits=su;
    speed1=s;
    name1 =n;
}
vechicleV::~vechicleV()
{
   
}
std::string vechicleV:: getName()
{
    return name1;
}
float vechicleV::getSpeed()
{
    return speed1;
}
char vechicleV::getUnits()
{
return speedUnits;
}
void vechicleV::setName(std::string n)
{
    if (n == " ")
    {name1= n;}
    else
    {name1 = n;}

}
void vechicleV::set_speed(float newSpeed, char unit)
{
    char miles = 'm', kilom = 'k';
    
    assert(newSpeed >= 0.0);
    assert(unit == miles || unit == kilom);
    if (speedUnits == miles || speedUnits == kilom)
    {
        speed1 = newSpeed;
        
        speedUnits = unit;
        
    }
 
}
void vechicleV::setSpeedUnit(char su)
{
    char miles = 'm';
    char kilometers = 'k';


assert(su == miles || su == kilometers);
if (su == kilometers)
    {   if (speedUnits == miles)
        speed1 = (speed1 * 1.608);
        speedUnits = su;
    }

else
    {   if (speedUnits == kilometers)
    speed1 = (speed1 / 1.608);
    speedUnits = su;
    }
        

}

void vechicleV::setSpeed(float s)
{
    assert(s >= 0.0);
    {speed1 = s;}
}
bool vechicleV::operator <(vechicleV& one)
{
    if (this->getSpeed() < one.getSpeed())
    {return true;}
    else
    {return !true;}
}
bool vechicleV::operator ==(vechicleV& one)
{
    if (this->getSpeed() == one.getSpeed())
    {return  true;}
    else
    {return !true;}
}
