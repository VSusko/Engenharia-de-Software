#include "model.h"

//Default constructor
Model::Model()
{
    this->name = "";
}

//Name construtor
Model::Model(const string _name)
{
    this->name = _name;
}

//Copy constructor
Model::Model(const Model &other)
{
    this->name = other.name;
    this->flows.insert(flows.begin(), other.flows.begin(), other.flows.end());
    this->systems.insert(systems.begin(), other.systems.begin(), other.systems.end());
}

//Copy operator overload
Model Model::operator=(const Model &other)
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

//Getters and setters
void Model::setName(string _name)
{
    this->name = _name;
}

string Model::getName() const
{
    return this->name;
}

bool Model::exists(System* s)
{
    for(auto system : systems){
        if(system->getName() == s->getName())
            return true;
    }
    
    for(auto flow : flows){
        if(flow->getName() == s->getName())
            return true;
    }

    return false;
}

bool Model::exists(Flow* f)
{
    for(auto system : systems){
        if(system->getName() == f->getName())
            return true;
    }
    
    for(auto flow : flows){
        if(flow->getName() == f->getName())
            return true;
    }

    return false;
}

System* Model::getSystem(const string _name)
{
    for(auto system : systems){
        if(system->getName() == _name)
            return system;
    }
    return NULL;
}

Flow* Model::getFlow(const string _name)
{
    for(auto flow : flows){
        if(flow->getName() == _name)
            return flow;
    }
    return NULL;
}


//Add function for systems
bool Model::add(System* s)
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
bool Model::add(Flow* f)
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
bool Model::remove(Flow* f)
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
bool Model::remove(System* f)
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
void Model::clear()
{
    this->flows.clear();
    this->systems.clear();
}

//Report function
void Model::report()
{
    for(auto system : systems)
    {
        cout << "System name: " << system->getName() << " | Value: " << system->getValue() << endl;
    }
}

//Simulate function
void Model::simulate(const double start, const double end, const double lapse)
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