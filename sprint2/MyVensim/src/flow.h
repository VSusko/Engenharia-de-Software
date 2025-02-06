#ifndef FLOW_H
#define FLOW_H

#include "system.h"

class Flow
{
    protected:
        string name;
        System* source;
        System* target;
        
    public:
        //Default construtor 
        Flow();

        //Constructor with name and 2 systems
        Flow(string _name, System* _source, System* _target);

        //Copy constructor
        Flow(const Flow &other);
        
        //Destructor
        virtual ~Flow(){};

        //Copy operator overload
        Flow& operator=(const Flow &other);

        //Getters and Setters
        void setTarget(System* s);
        void setSource(System* s);
        void setName(string _string);
        System* getTarget() const;
        System* getSource() const;
        string getName() const;
        
        //Class functions
        virtual double execute() = 0;
        void clear();
};

#endif