#include "model_impl.h"

//===================Constructors===================//

ModelImpl::ModelImpl() {}

ModelImpl::ModelImpl(const string name)
{
    this->name = name;
}

ModelImpl::ModelImpl(const ModelImpl &other)
{
    this->name = other.name;
    this->flows.insert(flows.begin(), other.flows.begin(), other.flows.end());
    this->systems.insert(systems.begin(), other.systems.begin(), other.systems.end());
}

ModelImpl ModelImpl::operator=(const ModelImpl &other)
{
    if(this == &other){
        return *this; 
    }

    this->clear();
    this->name = other.name;
    this->flows.insert(flows.begin(), other.flows.begin(), other.flows.end());
    this->systems.insert(systems.begin(), other.systems.begin(), other.systems.end());

    return *this;
}

//===================Getters and Setters===================//

void ModelImpl::setName(string name) { this->name = name; }
string ModelImpl::getName() const { return this->name; }
double ModelImpl::getClock() const { return this->clock; }

System* ModelImpl::getSystem(const string name) const
{
    for(auto system : systems){
        if(system->getName() == name)
            return system;
    }
    return nullptr;
}

Flow* ModelImpl::getFlow(const string name) const
{
    for(auto flow : flows){
        if(flow->getName() == name)
            return flow;
    }
    return nullptr;
}

//===================Class functions===================//

bool ModelImpl::exists(System* s)
{
    // Searching a system with same name
    for(auto system : systems)
    {
        if(system->getName() == s->getName())
            return true;
    }

    // Searching a flow with same name
    for(auto flow : flows){
        if(flow->getName() == s->getName())
            return true;
    }

    return false;
}

bool ModelImpl::exists(Flow* f)
{
    // Searching a system with same name
    for(auto system : systems){
        if(system->getName() == f->getName())
            return true;
    }

    // Searching a flow with same name
    for(auto flow : flows){
        if(flow->getName() == f->getName())
            return true;
    }

    return false;
}

bool ModelImpl::add(System* s)
{
    if(this->exists(s))
    {
        return false;
    }

    this->systems.push_back(s);
    return true;
}


bool ModelImpl::add(Flow* f)
{
    if(this->exists(f))
    {
        return false;
    }

    this->flows.push_back(f);
    return true;
}

bool ModelImpl::remove(Flow* f)
{
    for(auto iter = flows.begin(); iter != flows.end(); iter++)
    {
        if(*iter == f)
        {
            flows.erase(iter);
            return true;
        }
    }
    
    return false;
}

bool ModelImpl::remove(System* f)
{
    for(auto iter = systems.begin(); iter != systems.end(); iter++)
    {
        if(*iter == f)
        {
            systems.erase(iter);
            return true;
        }
    }
    
    return false;
}

void ModelImpl::clear()
{
    for(auto flow : flows)
        flow->clear();
    
    for(auto system : systems)
        system->clear();
}

void ModelImpl::report()
{
    for(auto system : systems)
    {
        cout << "System name: " << system->getName() << " | Value: " << system->getValue() << endl;
    }
}

void ModelImpl::simulate(const double start, const double end, const double lapse)
{
    double* expressions_results = new double[flows.size()];
    int j;
    clock = start;
    for(; clock <= end; clock += lapse)
    {
        j = 0;
        for(auto flow : flows)
        { 
            expressions_results[j++] = flow->execute();
        }

        j = 0;
        for(auto flow : flows) 
        {
            flow->getSource()->setValue(flow->getSource()->getValue() - expressions_results[j]);

            flow->getTarget()->setValue(flow->getTarget()->getValue() + expressions_results[j++]);
        }
    }

    delete [] expressions_results;
}