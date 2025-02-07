#include <iostream>
#include "system.h"

/**
 * @brief Default constructor
 * 
 * Initializes the system with an empty name and value set to 0.
 */
System::System()
{ 
    this->name = "";
    this->value = 0;
}

/**
 * @brief Constructor with name and value
 * 
 * Initializes the system with a specified name and value.
 * 
 * @param _name Name of the system
 * @param _value Value of the system
 */
System::System(const string _name, const double _value)
{ 
    this->name = _name;
    this->value = _value;
}

/**
 * @brief Copy constructor
 * 
 * Creates a new System object by copying data from the provided object.
 * 
 * @param other System object to be copied
 */
System::System(const System &other)
{
    this->name = other.getName();
    this->value = other.getValue();
}

/**
 * @brief Copy assignment operator overload
 * 
 * Copies the data from one System object to another, ensuring no self-assignment occurs.
 * 
 * @param other System object to be copied
 * @return A reference to the current System object after assignment
 */
System& System::operator=(const System &other)
{
    if(this == &other){
        return *this; 
    }

    this->name = other.name;
    this->value = other.value;

    return *this;
}

//============Getters and setters

/**
 * @brief Sets the value of the system
 * 
 * @param _value The value to be set for the system
 */
void System::setValue(double _value)
{
    this->value = _value;
}

/**
 * @brief Gets the value of the system
 * 
 * @return The current value of the system
 */
double System::getValue() const
{
    return this->value;
}

/**
 * @brief Sets the name of the system
 * 
 * @param _name The name to be set for the system
 */
void System::setName(const string& _name)
{
    this->name = _name;
}

/**
 * @brief Gets the name of the system
 * 
 * @return The name of the system
 */
string System::getName() const
{
    return this->name;
}

/**
 * @brief Clears the system's value
 * 
 * Resets the system's value to 0.
 */
void System::clear()
{
    this->value = 0;
}