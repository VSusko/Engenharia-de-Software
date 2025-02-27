#include "model_impl.h"

//===================Constructors & Destructor===================//

ModelImpl::ModelImpl(){ name = ""; }

ModelImpl::ModelImpl(const string name){ this->name = name; }

ModelImpl::ModelImpl(const ModelImpl &other)
{
    name = other.name;
    flows.insert(flows.begin(), other.flows.begin(), other.flows.end());
    systems.insert(systems.begin(), other.systems.begin(), other.systems.end());
}

ModelImpl::~ModelImpl()
{
    for(System* system : systems)
        delete system;

    systems.clear();
    
    for(Flow* flow : flows)
        delete flow;

    flows.clear();

    delete this;
}

ModelImpl ModelImpl::operator=(const ModelImpl &other)
{
    if(this == &other){
        return *this; 
    }

    this->clear();
    name = other.name;
    flows.insert(flows.begin(), other.flows.begin(), other.flows.end());
    systems.insert(systems.begin(), other.systems.begin(), other.systems.end());

    return *this;
}


//===================Getters and Setters===================//

void ModelImpl::setName(const string name)  { this->name = name; }
string ModelImpl::getName() const           { return this->name; }
double ModelImpl::getClock() const          { return this->clock; }

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


void ModelImpl::add(System* s)
{
    this->systems.push_back(s);
}


void ModelImpl::add(Flow* f)
{
    this->flows.push_back(f);
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

bool ModelImpl::remove(System* s)
{
    for(auto iter = systems.begin(); iter != systems.end(); iter++)
    {
        if(*iter == s)
        {
            systems.erase(iter);
            return true;
        }
    }
    
    return false;
}

void ModelImpl::clear()
{
    for(System* system : systems)
        delete system;

    systems.clear();
    
    for(Flow* flow : flows)
        delete flow;

    flows.clear();
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

//Model instance
ModelImpl* ModelImpl::instance = nullptr;

Model* ModelImpl::createModel(const string name) {
    if (instance == nullptr) {
        instance = new ModelImpl(name);
    }
    else{   
        instance->clear();
        instance->setName(name);
    }

    return instance;
}

Model* Model::createModel(const string name) {
    return ModelImpl::createModel(name);
}

System* ModelImpl::createSystem(string name, double value)
{
    System* system = new SystemHandle(name, value);
    add(system);
    return system;
}