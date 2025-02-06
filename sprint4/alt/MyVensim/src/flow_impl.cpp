#include <iostream>
#include "flow_impl.h"


/**
 * @brief Standard constructor
 * 
 * Initializes the flow with an empty name and null pointers for the source
 * and target systems.
 */
FlowImpl::FlowImpl() {}

/**
 * @brief Constructor with name and two systems
 * 
 * @param name Name of the flow
 * @param _source Pointer to the source system
 * @param _target Pointer to the target system
 */
FlowImpl::FlowImpl(string name, System* source, System* target)
{
    this->name = name;
    this->source = source;
    this->target = target;
}

/**
 * @brief Copy constructor
 * 
 * Creates a new Flow object by copying the data from the provided object.
 * 
 * @param other Flow object to be copied
 */
FlowImpl::FlowImpl(const FlowImpl &other)
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
FlowImpl& FlowImpl::operator=(const FlowImpl &other)
{
    if (this != &other)
    {
        name = other.name;
        source = other.source;
        target = other.target;
    }
    return *this;
}

//============Getters and setters
/**
 * @brief Sets the target system of the flow
 * 
 * @param s Pointer to the target system
 */
void FlowImpl::setTarget(System* s) { target = s; }

/**
 * @brief Sets the source system of the flow
 * 
 * @param s Pointer to the source system
 */
void FlowImpl::setSource(System* s) { source = s; }


/**
 * @brief Sets the name of the flow
 * 
 * @param _name Name of the flow
 */
void FlowImpl::setName(string name) { this->name = name; }


System* FlowImpl::getSource() const { return source; }


System* FlowImpl::getTarget() const { return target; }


string  FlowImpl::getName() const { return name; }


void FlowImpl::clear() 
{
    source = nullptr;
    target = nullptr;
}