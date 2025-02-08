#ifndef SYSTEM_H
#define SYSTEM_H

#include "mySim.h"

/**
 * @class System
 * @brief Interface for System class
 * 
 * 
 */
class System
{
    public:
        //Destructor
        virtual ~System(){};

        //===================Getters and Setters===================//
        virtual void setValue(double time) = 0;
        virtual double getValue() const = 0;
        virtual void setName(const string& name) = 0;
        virtual string getName() const = 0;

        //===================Class Functions===================//
        virtual void clear() = 0;
};

#endif