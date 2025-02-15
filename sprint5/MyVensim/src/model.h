#ifndef MODEL_H
#define MODEL_H

#include "flow.h"

/**
 * @class Model
 * @brief Interface for Model class
 * 
 * 
 */
class Model
{
    public:
        /**
         * @brief Destructor
         * 
         * Destroys the Model object. The destructor does not need to free resources explicitly,
         * as the class uses smart pointers or managed resources.
         */
        virtual ~Model(){};

        //===================Getters and Setters===================//

        /**
         * @brief Sets the name of the model
         * 
         * @param _string Name of the model
         */
        virtual void setName(string string) = 0;

        /**
         * @brief Gets the name of the model
         * 
         * @return The name of the model
         */
        virtual string getName() const = 0;

        /**
         * @brief Gets the value of the clock
         * 
         * @return Clock value
         */
        virtual double getClock() const = 0;

        /**
         * @brief Gets a system by its name
         * 
         * Searches for a system in the model by its name.
         * 
         * @param _name Name of the system to search for
         * @return Pointer to the system if found, nullptr otherwise
         */
        virtual System* getSystem(const string name) const = 0;


        /**
         * @brief Gets a flow by its name
         * 
         * Searches for a flow in the model by its name.
         * 
         * @param _name Name of the flow to search for
         * @return Pointer to the flow if found, nullptr otherwise
         */
        virtual Flow* getFlow(const string name) const = 0;

        //===================Class functions===================//

        /**
         * @brief Simulates the flow of values between systems over time
         * 
         * Simulates the system model by updating the systems' values based on the flow of data
         * over a given time period.
         * 
         * @param initial Initial time for the simulation
         * @param final Final time for the simulation
         * @param lapse Time step between each iteration in the simulation
         */
        virtual void simulate(double initial, double final, double lapse) = 0;

        /**
         * @brief Clears the model's systems and flows
         * 
         * Removes all systems and flows from the model.
         */
        virtual void clear() = 0;

        /**
         * @brief Reports the current state of all systems in the model
         * 
         * Prints the name and value of each system currently in the model.
         */
        virtual void report() = 0;

        /**
         * @brief Adds a system to the model
         * 
         * Adds a system to the model if it does not already exist.
         * 
         * @param s Pointer to the system to be added
         * @return True if the system was added, false if it already exists
         */
        virtual bool add(System* s) = 0;

        /**
         * @brief Adds a flow to the model
         * 
         * Adds a flow to the model if it does not already exist.
         * 
         * @param f Pointer to the flow to be added
         * @return True if the flow was added, false if it already exists
         */
        virtual bool add(Flow* f) = 0;

        /**
         * @brief Removes a system from the model
         * 
         * Removes the specified system from the model.
         * 
         * @param s Pointer to the system to be removed
         * @return True if the system was removed, false if it was not found
         */
        virtual bool remove(System* s) = 0;

        /**
         * @brief Removes a flow from the model
         * 
         * Removes the specified flow from the model.
         * 
         * @param f Pointer to the flow to be removed
         * @return True if the flow was removed, false if it was not found
         */
        virtual bool remove(Flow* f) = 0;

        /**
         * @brief Checks if a flow exists in the model
         * 
         * Searches for a flow in the model by name.
         * 
         * @param f Pointer to the flow to be checked
         * @return True if the flow exists, false otherwise
         */
        virtual bool exists(Flow* f) = 0;

        /**
         * @brief Checks if a system exists in the model
         * 
         * Searches for a system in the model by name.
         * 
         * @param f Pointer to the system to be checked
         * @return True if the system exists, false otherwise
         */
        virtual bool exists(System* f) = 0;
};


#endif