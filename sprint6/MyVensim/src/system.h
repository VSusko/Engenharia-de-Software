#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @class System
 * @brief Interface for System class
 * 
 * This class defines a system with a name and a value. It provides methods
 * for getting and setting the system's properties, as well as operations
 * like clearing the system's value.
 */
class System
{
    public:
        /**
         * @brief Destructor
         * 
         * Destroys the System object. The destructor does not need to free resources explicitly,
         * as the class uses managed resources.
         */
        virtual ~System(){};

        //===================Getters and Setters===================//

        /**
         * @brief Sets the value of the system
         * 
         * @param _time The value to be set for the system
         */
        virtual void setValue(double time) = 0;

        /**
         * @brief Sets the name of the system
         * 
         * @param _name The name to be set for the system
         */
        virtual void setName(const string& name) = 0;

        /**
         * @brief Gets the value of the system
         * 
         * @return The current value of the system
         */
        virtual double getValue() const = 0;

        /**
         * @brief Gets the name of the system
         * 
         * @return The name of the system
         */
        virtual string getName() const = 0;


        //===================Class Functions===================//

        /**
         * @brief Clears the system's value
         * 
         * Resets the system's value to 0.
         */
        virtual void clear() = 0;
};

#endif