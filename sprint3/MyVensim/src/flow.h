#ifndef FLOW_H
#define FLOW_H

#include "system.h"

/**
 * @class Flow
 * @brief Changes the current state of a system by a mathematic expression. Needs inheritance to be used
 * 
 * 
 */
class Flow
{
    protected:
        string name; /**< Flow name */
        System* source; /**< Pointer for the source system */
        System* target; /**< Pointer for the target system */
    
    public:
        /**
         * @brief Default constructor
         */
        Flow();

        /**
         * @brief Constructor with name and 2 systems
         * @param _name Flow name
         * @param _source Source system pointer
         * @param _target Target system pointer
         */
        Flow(string _name, System* _source, System* _target);


        /**
         * @brief Copy constructor
         * 
         * @param other Flow copy object
         */
        Flow(const Flow &other);
        
        /**
         * @brief Destructor
         * 
         * @param other Flow copy object
         */
        virtual ~Flow(){};

        /**
         * @brief Assignment operator overload
         * 
         * Assigns the values from one Flow object to another.
         * 
         * @param other Flow object to be copied
         * @return Reference to the Flow object after assignment
         */
        Flow& operator=(const Flow &other);

        ////=============Getters and Setters

        /**
         * @brief Sets the target system of the flow
         * 
         * @param s Pointer to the target system
         */
        void setTarget(System* s);

        /**
         * @brief Sets the source system of the flow
         * 
         * @param s Pointer to the source system
         */
        void setSource(System* s);

        /**
         * @brief Sets the name of the flow
         * 
         * @param _string Name of the flow
         */
        void setName(string _string);

        /**
         * @brief Gets the target system of the flow
         * 
         * @return Pointer to the target system
         */
        System* getTarget() const;

        /**
         * @brief Gets the source system of the flow
         * 
         * @return Pointer to the source system
         */
        System* getSource() const;

        /**
         * @brief Gets the name of the flow
         * 
         * @return Name of the flow
         */
        string getName() const;
        

        //=============Class functions
        /**
         * @brief Virtual pure function to execute the flow
         * 
         * This function will be implemented in derived classes to execute
         * the specific logic for the flow.
         * 
         * @return Result of the flow execution
         */
        virtual double execute() = 0;

        /**
         * @brief Clears the flow data
         * 
         * Resets the pointers to the source and target systems.
         */
        void clear();
};

#endif