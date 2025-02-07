#include "model.h"

/**
 * @brief Default constructor
 * 
 * Initializes the model with an empty name.
 */
Model::Model()
{
    this->name = "";
}

/**
 * @brief Constructor with a name
 * 
 * @param _name Name of the model
 */
Model::Model(const string _name)
{
    this->name = _name;
}

/**
 * @brief Copy constructor
 * 
 * Creates a new Model object by copying the data from the provided object.
 * 
 * @param other Model object to be copied
 */
Model::Model(const Model &other)
{
    this->name = other.name;
    this->flows.insert(flows.begin(), other.flows.begin(), other.flows.end());
    this->systems.insert(systems.begin(), other.systems.begin(), other.systems.end());
}

/**
 * @brief Copy assignment operator overload
 * 
 * Copies the data from one Model object to another, ensuring no self-assignment occurs.
 * 
 * @param other Model object to be copied
 * @return A reference to the current Model object after assignment
 */
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

//==========Getters and setters
/**
 * @brief Sets the name of the model
 * 
 * @param _name Name of the model
 */
void Model::setName(string _name)
{
    this->name = _name;
}

/**
 * @brief Gets the name of the model
 * 
 * @return Name of the model
 */
string Model::getName() const
{
    return this->name;
}

/**
 * @brief Checks if a system exists in the model
 * 
 * This function checks if a system is present in the model by name.
 * 
 * @param s Pointer to the system to check
 * @return True if the system exists, false otherwise
 */
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

/**
 * @brief Checks if a flow exists in the model
 * 
 * This function checks if a flow is present in the model by name.
 * 
 * @param f Pointer to the flow to check
 * @return True if the flow exists, false otherwise
 */
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

/**
 * @brief Gets a system by its name
 * 
 * Searches for a system in the model by name.
 * 
 * @param _name Name of the system to search for
 * @return Pointer to the system if found, NULL otherwise
 */
System* Model::getSystem(const string _name)
{
    for(auto system : systems){
        if(system->getName() == _name)
            return system;
    }
    return NULL;
}

/**
 * @brief Gets a flow by its name
 * 
 * Searches for a flow in the model by name.
 * 
 * @param _name Name of the flow to search for
 * @return Pointer to the flow if found, NULL otherwise
 */
Flow* Model::getFlow(const string _name)
{
    for(auto flow : flows){
        if(flow->getName() == _name)
            return flow;
    }
    return NULL;
}

/**
 * @brief Adds a system to the model
 * 
 * Adds a system to the model if it doesn't already exist.
 * 
 * @param s Pointer to the system to add
 * @return True if the system was added, false if it already exists
 */
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

/**
 * @brief Adds a flow to the model
 * 
 * Adds a flow to the model if it doesn't already exist.
 * 
 * @param f Pointer to the flow to add
 * @return True if the flow was added, false if it already exists
 */
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

/**
 * @brief Removes a flow from the model
 * 
 * Removes the specified flow from the model.
 * 
 * @param f Pointer to the flow to remove
 * @return True if the flow was removed, false if it wasn't found
 */
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

/**
 * @brief Removes a system from the model
 * 
 * Removes the specified system from the model.
 * 
 * @param f Pointer to the system to remove
 * @return True if the system was removed, false if it wasn't found
 */
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

/**
 * @brief Clears all systems and flows from the model
 * 
 * Removes all systems and flows from the model.
 */
void Model::clear()
{
    this->flows.clear();
    this->systems.clear();
}

/**
 * @brief Reports the details of all systems in the model
 * 
 * Prints the name and value of each system in the model.
 */
void Model::report()
{
    for(auto system : systems)
    {
        cout << "System name: " << system->getName() << " | Value: " << system->getValue() << endl;
    }
}

/**
 * @brief Simulates the flow of values over a period of time
 * 
 * This function simulates the flow of values in the model's systems over a given time range,
 * applying the flow execution at regular time intervals.
 * 
 * @param start Starting time for the simulation
 * @param end Ending time for the simulation
 * @param lapse Time step between each simulation iteration
 */
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