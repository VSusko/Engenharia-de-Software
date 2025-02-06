#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include "flow.h"
#include "system.h"

class FlowImpl : public Flow
{
    protected:
        string name;
        System* source;
        System* target;
        
    public:
        //Default construtor 
        FlowImpl();

        //Constructor with name and 2 systems
        FlowImpl(string _name, System* _source, System* _target);

        //Copy constructor
        FlowImpl(const FlowImpl &other);
        
        //Destructor
        virtual ~FlowImpl(){};

        //Copy operator overload
        FlowImpl& operator=(const FlowImpl &other);

        //Getters and Setters
        void setTarget(System* s) override;
        void setSource(System* s) override;
        void setName(string _name) override;
        System* getTarget() const override;
        System* getSource() const override;
        string getName() const override;
        
        //Class functions
        virtual double execute() = 0;
        void clear();
};

#endif