#include "flow_impl.h"


//===================Constructors===================//

FlowBody::FlowBody() 
{
    this->name   = "";
    this->source = nullptr; 
    this->target = nullptr; 
}

FlowBody::FlowBody(string name, System* source, System* target)
{
    this->name   = name;
    this->source = source;
    this->target = target;
}

FlowBody::FlowBody(const FlowBody &other)
{
    this->name   = other.name;
    this->source = other.source;
    this->target = other.target;
}

FlowBody& FlowBody::operator=(const FlowBody &other)
{
    if (this != &other)
    {
        name   = other.name;
        source = other.source;
        target = other.target;
    }
    return *this;
}

//===================Getters and Setters===================//

void FlowBody::setTarget(System* s) { target = s; }
void FlowBody::setSource(System* s) { source = s; }
void FlowBody::setName(string name) { this->name = name; }
System* FlowBody::getSource() const { return source; }
System* FlowBody::getTarget() const { return target; }
string  FlowBody::getName() const   { return name; }

//===================Class functions===================//

void FlowBody::clear() 
{
    source = nullptr;
    target = nullptr;
}
