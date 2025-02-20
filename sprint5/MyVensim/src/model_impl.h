#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include "model.h"
#include "flow_impl.h"
#include "system_impl.h"

/**
 * @class ModelImpl
 * @brief Represents a system model consisting of systems and flows.
 * 
 * The Model class defines a model that holds systems and flows. It provides
 * methods to manage the components (add, remove) and perform operations such
 * as simulation and reporting.
 */
class ModelImpl : public Model
{
    friend class unit_Model;

    private:
        string name; /**< Name of the model */
        double clock; /**< Clock of the model */
        vector<System*> systems; /**< List of systems in the factory */
        vector<Flow*> flows; /**< List of flows in the factory */
        static vector<Model*> models; /**< List of models in the factory */

    protected:

        /**
         * @brief Default constructor
         * 
         * Initializes the model with an empty name and no systems or flows.
         */
         ModelImpl();

         /**
          * @brief Constructor with a model name
          * 
          * Initializes the model with a specified name.
          * 
          * @param _name Name of the model
          */
         ModelImpl(const string name);

    public:

        /**
         * @brief Destructor
         * 
         * Destroys the Model object. The destructor does not need to free resources explicitly,
         * as the class uses smart pointers or managed resources.
         */
        virtual ~ModelImpl();

        //===================Getters and Setters===================//

        /**
         * @brief Sets the name of the model
         * 
         * @param _string Name of the model
         */
        void setName(string string);

        //static ModelImpl& getInstance();

        /**
         * @brief Gets the name of the model
         * 
         * @return The name of the model
         */
        string getName() const;

        /**
         * @brief Gets the value of the clock
         * 
         * @return Clock value
         */
        double getClock() const;
        
        /**
         * @brief Gets a system by its name
         * 
         * Searches for a system in the model by its name.
         * 
         * @param _name Name of the system to search for
         * @return Pointer to the system if found, nullptr otherwise
         */
        System* getSystem(const string name) const;
        
        /**
         * @brief Gets a flow by its name
         * 
         * Searches for a flow in the model by its name.
         * 
         * @param _name Name of the flow to search for
         * @return Pointer to the flow if found, nullptr otherwise
         */
        Flow* getFlow(const string name) const;

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
        void simulate(double initial, double final, double lapse);

        /**
         * @brief Clears the model's systems and flows
         * 
         * Removes all systems and flows from the model.
         */
        void clear();

        /**
         * @brief Reports the current state of all systems in the model
         * 
         * Prints the name and value of each system currently in the model.
         */
        void report();

        /**
         * @brief Removes a system from the model
         * 
         * Removes the specified system from the model.
         * 
         * @param s Pointer to the system to be removed
         * @return True if the system was removed, false if it was not found
         */
        bool remove(System* s);

        /**
         * @brief Removes a flow from the model
         * 
         * Removes the specified flow from the model.
         * 
         * @param f Pointer to the flow to be removed
         * @return True if the flow was removed, false if it was not found
         */
        bool remove(Flow* f);

        /**
         * @brief Creates a new system
         * 
         * @param name System name
         * @param value System value
         * @return A pointer of System class
         */
        System* createSystem(string name = "", double value = 0);

        /**
         * @brief Creates a new model
         * 
         * @param name Model name
         * @return A pointer of model Model class
         */
        static Model* createModel(const string name);

    private:

        /**
        * @brief Adds a system to the model
        * 
        * Adds a system to the model if it does not already exist.
        * 
        * @param s Pointer to the system to be added
        * @return True if the system was added, false if it already exists
        */
        void add(Model* s);

        /**
        * @brief Adds a system to the model
        * 
        * Adds a system to the model if it does not already exist.
        * 
        * @param s Pointer to the system to be added
        * @return True if the system was added, false if it already exists
        */
        void add(System* s);
 
        /**
        * @brief Adds a flow to the model
        * 
        * Adds a flow to the model if it does not already exist.
        * 
        * @param f Pointer to the flow to be added
        * @return True if the flow was added, false if it already exists
        */
        void add(Flow* f);

        /**
         * @brief Copy assignment operator overload
         * 
         * Copies data from one Model object to another, ensuring no self-assignment occurs.
         * 
         * @param other Model object to be copied
         * @return A reference to the current Model object after assignment
         */
        ModelImpl operator=(const ModelImpl &other);

        /**
         * @brief Copy constructor
         * 
         * Creates a new Model object by copying data from the provided object.
         * 
         * @param other Model object to be copied
         */
        ModelImpl(const ModelImpl &other);
};


#endif