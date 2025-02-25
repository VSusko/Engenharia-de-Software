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
    public:
    
        /**
         * @brief Destructor
         * 
         * Destroys the Flow object. The destructor does not need to free resources explicitly,
         * as the class uses managed resources.
         */
        virtual ~Flow(){};
        
        //===================Getters and Setters===================//

        /**
         * @brief Sets the target system of the flow
         * 
         * @param s Pointer to the target system
         */
        virtual void setTarget(System* s) = 0;

        /**
         * @brief Sets the source system of the flow
         * 
         * @param s Pointer to the source system
         */
        virtual void setSource(System* s) = 0;

        /**
         * @brief Sets the name of the flow
         * 
         * @param _string Name of the flow
         */
        virtual void setName(string string) = 0;

        /**
         * @brief Gets the target system of the flow
         * 
         * @return Pointer to the target system
         */
        virtual System* getTarget() const = 0;

        /**
         * @brief Gets the source system of the flow
         * 
         * @return Pointer to the source system
         */ 
        virtual System* getSource() const = 0;

        /**
         * @brief Gets the name of the flow
         * 
         * @return Name of the flow
         */
        virtual string getName() const = 0;

        
        //===================Class functions===================//

        virtual double execute() = 0;

        /**
         * @brief Clears the flow data
         * 
         * Resets the pointers to the source and target systems to NULL.
         */
        virtual void clear() = 0;
};

#endif