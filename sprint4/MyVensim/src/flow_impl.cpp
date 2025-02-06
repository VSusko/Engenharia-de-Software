#include <iostream>
#include "flow_impl.h"

//Standard constructor
FlowImpl::FlowImpl()
{
    this->name = "";
    this->source = nullptr; 
    this->target = nullptr;
}

//Constructor with name and 2 systems
FlowImpl::FlowImpl(string name, System* source, System* target)
{
    this->name = name;
    this->source = source;
    this->target = target;
}

//Copy constructor
FlowImpl::FlowImpl(const FlowImpl &other)
{
    this->name = other.name;
    this->source = other.source;
    this->target = other.target;
}

//Copy operator overload
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

//Getters and setters
void FlowImpl::setTarget(System* s) { target = s; }
void FlowImpl::setSource(System* s) { source = s; }
void FlowImpl::setName(string name) { this->name = name; }

System* FlowImpl::getTarget() const { return target; }
System* FlowImpl::getSource() const { return source; }
string  FlowImpl::getName() const { return name; }

//Clear function
void FlowImpl::clear() 
{
    source = nullptr;
    target = nullptr;
}