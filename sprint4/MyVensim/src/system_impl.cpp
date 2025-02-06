#include <iostream>
#include "system_impl.h"

//Default construtor
SystemImpl::SystemImpl()
{ 
    this->name = "";
    this->value = 0;
}

//Constructor with name and 2 systems
SystemImpl::SystemImpl(const string name, const double value)
{ 
    this->name = name;
    this->value = value;
}

//Copy constructor
SystemImpl::SystemImpl(const SystemImpl &other)
{
    this->name = other.getName();
    this->value = other.getValue();
}

//Copy overload
SystemImpl& SystemImpl::operator=(const SystemImpl &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->value = other.value;
    }

    return *this;
}

//Getters and setters
void SystemImpl::setValue(double value)
{
    this->value = value;
}

double SystemImpl::getValue() const
{
    return this->value;
}

void SystemImpl::setName(const string& name)
{
    this->name = name;
}

string SystemImpl::getName() const
{
    return this->name;
}

//Clear function
void SystemImpl::clear()
{
    this->value = 0;
}