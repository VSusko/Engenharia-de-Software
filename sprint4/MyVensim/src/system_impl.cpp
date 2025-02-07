#include <iostream>
#include "system_impl.h"


//===================Constructors===================//

SystemImpl::SystemImpl() 
{
    this->name = "";
    this->value = 0;
}

SystemImpl::SystemImpl(const string name, const double value)
{ 
    this->name = name;
    this->value = value;
}

SystemImpl::SystemImpl(const SystemImpl &other)
{
    this->name = other.getName();
    this->value = other.getValue();
}

SystemImpl& SystemImpl::operator=(const SystemImpl &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->value = other.value;
    }

    return *this;
}

//===================Getters and Setters===================//

void SystemImpl::setValue(double value) { this->value = value; }
void SystemImpl::setName(const string& name) { this->name = name; }
double SystemImpl::getValue() const { return this->value; }
string SystemImpl::getName() const { return this->name; }

//===================Class functions===================//

void SystemImpl::clear() { this->value = 0; }