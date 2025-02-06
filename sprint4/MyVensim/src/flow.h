#ifndef FLOW_H
#define FLOW_H

#include "system.h"

class Flow
{
    public:
        //Default construtor
        Flow();

        //Constructor with name and 2 systems
        Flow(string name, System* source, System* target);

        //Copy constructor
        Flow(const Flow &other);
        
        //Destructor
        virtual ~Flow(){};

        //Copy operator overload
        Flow& operator=(const Flow &other);

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