#ifndef FLOW_H
#define FLOW_H

#include "system.h"

/**
 * @class Flow
 * @brief Interface for flow class
 * 
 * 
 */
class Flow
{
    public:
        //Destructor
        virtual ~Flow(){};
        
        //Getters and Setters
        virtual void setTarget(System* s) = 0;
        virtual void setSource(System* s) = 0;
        virtual void setName(string string) = 0;
        virtual System* getTarget() const = 0;
        virtual System* getSource() const = 0;
        virtual string getName() const = 0;
        
        //Class functions
        virtual double execute() = 0;
        virtual void clear() = 0;
};

#endif