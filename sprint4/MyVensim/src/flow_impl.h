#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include "flow.h"
#include "system.h"

/**
 * @class FlowImpl
 * @brief Changes the current state of a system by a mathematic expression. Needs inheritance to be used
 * 
 * 
 */
class FlowImpl : public Flow
{
    protected:
        string name; /**< Flow name */
        System* source; /**< Pointer for the source system */
        System* target; /**< Pointer for the target system */
        
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

        /**
         * @brief Gets the target system of the flow
         * 
         * @return Pointer to the target system
         */
        System* getTarget() const override;
        
        /**
         * @brief Gets the source system of the flow
         * 
         * @return Pointer to the source system
         */  
        System* getSource() const override;

        /**
         * @brief Gets the name of the flow
         * 
         * @return Name of the flow
         */
        string getName() const override;
        
        //Class functions
        virtual double execute() = 0;
        
        /**
         * @brief Clears the flow data
         * 
         * Resets the pointers to the source and target systems to NULL.
         */
        void clear();
};

#endif