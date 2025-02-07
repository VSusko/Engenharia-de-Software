#include "model_impl.h"

//Default constructor
ModelImpl::ModelImpl() {}

//Name construtor
ModelImpl::ModelImpl(const string name)
{
    this->name = name;
}

//Getters and setters
void ModelImpl::setName(string name)
{
    this->name = name;
}

string ModelImpl::getName() const
{
    return this->name;
}

bool ModelImpl::exists(System* s)
{
    for(auto system : systems){
        if(system->getName() == s->getName())
            return true;
    }
    /*
    for(auto flow : flows){
        if(flow->getName() == s->getName())
            return true;
    }
    */
    return false;
}

bool ModelImpl::exists(Flow* f)
{
    /*
    for(auto system : systems){
        if(system->getName() == f->getName())
            return true;
    }
    */
    
    for(auto flow : flows){
        if(flow->getName() == f->getName())
            return true;
    }

    return false;
}

System* ModelImpl::getSystem(const string name) const
{
    for(auto system : systems){
        if(system->getName() == name)
            return system;
    }
    return NULL;
}

Flow* ModelImpl::getFlow(const string name) const
{
    for(auto flow : flows){
        if(flow->getName() == name)
            return flow;
    }
    return NULL;
}


//Add function for systems
bool ModelImpl::add(System* s)
{
    if(this->exists(s))
    {
        cout << "ERROR! A COMPONENT NAMED "<< s->getName() << " ALREADY EXISTS!" << endl;
        return false;
    }

    this->systems.push_back(s);
    return true;
}

//Add function for flows
bool ModelImpl::add(Flow* f)
{
    if(this->exists(f))
    {
        cout << "ERROR! A COMPONENT NAMED "<< f->getName() << " ALREADY EXISTS!" << endl;
        return false;
    }

    this->flows.push_back(f);
    return true;
}

//Remove function for flows
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

//Remove function for systems
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

//Clear function
void ModelImpl::clear()
{
    this->flows.clear();
    this->systems.clear();
}

//Report function
void ModelImpl::report()
{
    for(auto system : systems)
    {
        cout << "System name: " << system->getName() << " | Value: " << system->getValue() << endl;
    }
}

//Simulate function
void ModelImpl::simulate(const double start, const double end, const double lapse)
{
    double* expressions_results = new double[flows.size()];
    int j;

    for(double i = start; i <= end; i += lapse)
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