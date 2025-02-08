#include "flow_impl.h"


//===================Constructors===================//

FlowImpl::FlowImpl() 
{
    this->name = "";
    this->source = nullptr; 
    this->target = nullptr; 
}

FlowImpl::FlowImpl(string name, System* source, System* target)
{
    this->name = name;
    this->source = source;
    this->target = target;
}

FlowImpl::FlowImpl(const FlowImpl &other)
{
    this->name = other.name;
    this->source = other.source;
    this->target = other.target;
}

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

//===================Getters and Setters===================//

void FlowImpl::setTarget(System* s) { target = s; }
void FlowImpl::setSource(System* s) { source = s; }
void FlowImpl::setName(string name) { this->name = name; }
System* FlowImpl::getSource() const { return source; }
System* FlowImpl::getTarget() const { return target; }
string  FlowImpl::getName() const { return name; }

//===================Class functions===================//

void FlowImpl::clear() 
{
    source = nullptr;
    target = nullptr;
}
