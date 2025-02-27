#ifndef MODEL_H
#define MODEL_H

#include "flow.h"

/**
 * @class Model
 * @brief Interface for Model class
 * 
 * The Model class defines a model that holds systems and flows. It provides
 * methods to manage the components (add, remove) and perform operations such
 * as simulation and reporting.
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
         * @param string Name of the model
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
         * @param name Name of the system to search for
         * @return Pointer to the system if found, nullptr otherwise
         */
        virtual System* getSystem(const string name) const = 0;


        /**
         * @brief Gets a flow by its name
         * 
         * Searches for a flow in the model by its name.
         * 
         * @param name Name of the flow to search for
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
         */
        virtual void add(System* s) = 0;

        /**
         * @brief Adds a flow to the model
         * 
         * Adds a flow to the model if it does not already exist.
         * 
         * @param f Pointer to the flow to be added
         */
        virtual void add(Flow* f) = 0;

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
         * @brief Creates a new model
         * 
         * @param name Model name
         * @return A pointer of model Model class
         */
        static Model* createModel(const string name = "");

        /**
         * @brief Creates a new system
         * 
         * @param name System name
         * @param value System value
         * @return A pointer of System class
         */
        virtual System* createSystem(string name = "", double value = 0) = 0;

        /**
         * @brief Creates a new flow
         * 
         * @param name Flow name
         * @param src Source system
         * @param trg Target system
         * @return A pointer of Flow class
         */
        template <typename T_FLOW_IMPL>
        Flow* createFlow(string name = "", System* src = NULL, System* trg = NULL)
        {
            Flow* f = new T_FLOW_IMPL(name,src,trg);
            add(f);
            return f;
        }
};


#endif