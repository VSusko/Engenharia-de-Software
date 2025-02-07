#include <iostream>
#include "flow.h"

/**
 * @brief Standard constructor
 * 
 * Initializes the flow with an empty name and null pointers for the source
 * and target systems.
 */
Flow::Flow()
{
    this->name = "";
    this->source = NULL; 
    this->target = NULL; 
}

/**
 * @brief Constructor with name and two systems
 * 
 * @param name Name of the flow
 * @param _source Pointer to the source system
 * @param _target Pointer to the target system
 */
Flow::Flow(string name, System* _source, System* _target)
{
    this->name = name;
    this->source = _source;
    this->target = _target;
}

/**
 * @brief Copy constructor
 * 
 * Creates a new Flow object by copying the data from the provided object.
 * 
 * @param other Flow object to be copied
 */
Flow::Flow(const Flow &other)
{
    this->name = other.name;
    this->source = other.source;
    this->target = other.target;
}

/**
 * @brief Assignment operator overload
 * 
 * Copies the data from one Flow object to another, ensuring no self-assignment occurs.
 * 
 * @param other Flow object to be copied
 * @return Reference to the Flow object after assignment
 */
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

//============Getters and setters
/**
 * @brief Sets the target system of the flow
 * 
 * @param s Pointer to the target system
 */
void Flow::setTarget(System* s) 
{ 
    this->target = s; 
}

/**
 * @brief Sets the source system of the flow
 * 
 * @param s Pointer to the source system
 */
void Flow::setSource(System* s) 
{ 
    this->source = s; 
}

/**
 * @brief Gets the target system of the flow
 * 
 * @return Pointer to the target system
 */
System* Flow::getTarget() const
{
    return this->target; 
}
 
/**
 * @brief Gets the source system of the flow
 * 
 * @return Pointer to the source system
 */       
System* Flow::getSource() const
{
    return this->source; 
}

/**
 * @brief Sets the name of the flow
 * 
 * @param _name Name of the flow
 */
void Flow::setName(string _name)
{
    this->name = _name;
}

/**
 * @brief Gets the name of the flow
 * 
 * @return Name of the flow
 */
string Flow::getName() const
{
    return this->name;
}

/**
 * @brief Clears the flow data
 * 
 * Resets the pointers to the source and target systems to NULL.
 */
void Flow::clear()
{
    this->source = NULL;
    this->target = NULL;
}