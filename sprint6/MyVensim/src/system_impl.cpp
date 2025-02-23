#include "system_impl.h"


//===================Constructors===================//

SystemBody::SystemBody() 
{
    this->name = "";
    this->value = 0;
}

SystemBody::SystemBody(const string name, const double value)
{ 
    this->name = name;
    this->value = value;
}

SystemBody::SystemBody(const SystemBody &other)
{
    this->name = other.getName();
    this->value = other.getValue();
}

SystemBody& SystemBody::operator=(const SystemBody &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->value = other.value;
    }

    return *this;
}

//===================Getters and Setters===================//

void SystemBody::setValue(double value) { this->value = value; }
void SystemBody::setName(const string& name) { this->name = name; }
double SystemBody::getValue() const { return this->value; }
string SystemBody::getName() const { return this->name; }

//===================Class functions===================//

void SystemBody::clear() { this->value = 0; }