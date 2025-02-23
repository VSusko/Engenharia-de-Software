#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include "flow.h"

/**
 * @class FlowImpl
 * @brief Changes the current state of a system by a mathematic expression. Needs inheritance to be used
 * 
 * 
 */
class FlowImpl : public Flow
{
    friend class unit_Flow;
    friend class FlowUTest;
    friend class ModelFactory;
    
    protected:
        string name; /**< Flow name */
        System* source; /**< Pointer for the source system */
        System* target; /**< Pointer for the target system */
        
    public:
    
        //===================Constructors===================//
        
        /**
         * @brief Standard constructor
         * 
         * Initializes the flow with an empty name and null pointers for the source
         * and target systems.
         */
        FlowImpl();

        /**
         * @brief Constructor with name and two systems
         * 
         * @param name Name of the flow
         * @param _source Pointer to the source system
         * @param _target Pointer to the target system
         */
        FlowImpl(string _name, System* _source, System* _target);

        /**
         * @brief Copy constructor
         * 
         * Creates a new Flow object by copying the data from the provided object.
         * 
         * @param other Flow object to be copied
         */
        FlowImpl(const FlowImpl &other);
        
        //Destructor
        virtual ~FlowImpl(){};

        /**
         * @brief Assignment operator overload
         * 
         * Copies the data from one Flow object to another, ensuring no self-assignment occurs.
         * 
         * @param other Flow object to be copied
         * @return Reference to the Flow object after assignment
         */
        FlowImpl& operator=(const FlowImpl &other);

        //===================Getters and Setters===================//

        /**
         * @brief Sets the target system of the flow
         * 
         * @param s Pointer to the target system
         */
        void setTarget(System* s) override;

        /**
         * @brief Sets the source system of the flow
         * 
         * @param s Pointer to the source system
         */
        void setSource(System* s) override;

        /**
         * @brief Sets the name of the flow
         * 
         * @param _string Name of the flow
         */
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
        
        //===================Class functions===================//
        
        virtual double execute() = 0;
        
        /**
         * @brief Clears the flow data
         * 
         * Resets the pointers to the source and target systems to NULL.
         */
        void clear();
};

#endif