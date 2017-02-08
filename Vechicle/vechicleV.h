//
//  vechicleV.h
//  project1DS
//
//  Created by Nicholas Genco on 9/10/14.
//  Copyright (c) 2014 ___NickGencoDEV___. All rights reserved.
//

#ifndef vechicleV_h
#define vechicleV_h
#include<iostream>
#include<cassert>
#include<string>

namespace vechicle
{
class vechicleV
{

public:
    vechicleV();
    vechicleV(char su, float s,std::string n);
    ~vechicleV();
    std::string getName();
    float getSpeed();
    char getUnits();
    void setName(std::string n);
    void setUnits(char su);
    void setSpeed(float s);
    void set_speed(float newSpeed, char unit);
    void setSpeedUnit(char su);
    
    bool operator <(vechicleV& one);
    bool operator ==(vechicleV& one);
    
private:
    char speedUnits;
    float speed1;
    std::string name1;

};

}

#endif
