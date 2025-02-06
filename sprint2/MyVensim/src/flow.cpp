#include <iostream>
#include "flow.h"

//Standard constructor
Flow::Flow()
{
    this->name = "";
    this->source = NULL; 
    this->target = NULL; 
}

//Constructor with name and 2 systems
Flow::Flow(string name, System* _source, System* _target)
{
    this->name = name;
    this->source = _source;
    this->target = _target;
}

//Copy constructor
Flow::Flow(const Flow &other)
{
    if(this == &other)
        return;

    this->name = other.name;
    this->source = other.source;
    this->target = other.target;
}

//Copy operator overload
Flow& Flow::operator=(const Flow &other)
{
    if(this == &other){
        return *this; 
    }

    this->name = other.name;
    this->source = other.source;
    this->target = other.target;

    return *this;
}

//Getters and setters
void Flow::setTarget(System* s) 
{ 
    this->target = s; 
}

void Flow::setSource(System* s) 
{ 
    this->source = s; 
}

System* Flow::getTarget() const
{
    return this->target; 
}
        
System* Flow::getSource() const
{
    return this->source; 
}

void Flow::setName(string _name)
{
    this->name = _name;
}

string Flow::getName() const
{
    return this->name;
}

//Clear function
void Flow::clear()
{
    this->source = NULL;
    this->target = NULL;
}