#ifndef SYSTEM_IMPL_H
#define SYSTEM_IMPL_H

#include "system.h"

using namespace std;

/**
 * @class System
 * @brief Represents a system with a name and value.
 * 
 * This class defines a system with a name and a value. It provides methods
 * for getting and setting the system's properties, as well as operations
 * like clearing the system's value.
 */
class SystemImpl : public System
{
    friend class unit_System;

    private:
        string name; /**< Name of the system */
        double value; /**< Value of the system */

    public:

        //===================Constructors===================//

        /**
         * @brief Standard constructor
         * 
         * Initializes the system with an empty name and value set to 0.
         */
        SystemImpl();

        /**
         * @brief Constructor with name and initial value
         * 
         * Initializes the system with a specified name and value.
         * 
         * @param _name Name of the system
         * @param _value Initial value of the system
         */
        SystemImpl(const string name, const double value);

        /**
         * @brief Copy constructor
         * 
         * Creates a new System object by copying data from the provided object.
         * 
         * @param other System object to be copied
         */
        SystemImpl(const SystemImpl &other);

        /**
         * @brief Destructor
         * 
         * Destroys the System object. The destructor does not need to free resources explicitly,
         * as the class uses managed resources.
         */
        virtual ~SystemImpl(){};

        /**
         * @brief Copy assignment operator overload
         * 
         * Copies the data from one System object to another, ensuring no self-assignment occurs.
         * 
         * @param s System object to be copied
         * @return A reference to the current System object after assignment
         */
        SystemImpl& operator=(const SystemImpl &s);

        //===================Getters and Setters===================//
        
        /**
         * @brief Sets the value of the system
         * 
         * @param _time The value to be set for the system
         */
        void setValue(double time);
        
        /**
         * @brief Sets the name of the system
         * 
         * @param _name The name to be set for the system
         */
        void setName(const string& name);
        
        /**
         * @brief Gets the value of the system
         * 
         * @return The current value of the system
         */
        double getValue() const;

        /**
         * @brief Gets the name of the system
         * 
         * @return The name of the system
         */
        string getName() const;

        //===================Class functions===================//

        /**
         * @brief Clears the system's value
         * 
         * Resets the system's value to 0.
         */
        void clear();       
};

#endif