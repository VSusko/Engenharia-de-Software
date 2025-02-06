#include <iostream>
#include "system.h"

//Default construtor
System::System()
{ 
    this->name = "";
    this->value = 0;
}

//Constructor with name and 2 systems
System::System(const string _name, const double _value)
{ 
    this->name = _name;
    this->value = _value;
}

//Copy constructor
System::System(const System &other)
{
    if(this == &other)
        return;

    this->name = other.getName();
    this->value = other.getValue();
}

//Copy overload
System& System::operator=(const System &other)
{
    if(this == &other){
        return *this; 
    }

    this->name = other.name;
    this->value = other.value;

    return *this;
}

//Getters and setters
void System::setValue(double _value)
{
    this->value = _value;
}

double System::getValue() const
{
    return this->value;
}

void System::setName(const string& _name)
{
    this->name = _name;
}

string System::getName() const
{
    return this->name;
}

//Clear function
void System::clear()
{
    this->value = 0;
}