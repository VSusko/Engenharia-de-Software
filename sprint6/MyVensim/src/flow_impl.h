#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include "flow.h"
#include "handlebody.h"

/**
 * @class FlowBody
 * @brief Represents the body for the Flow class
 * 
 */
class FlowBody : public Body
{
    friend class unit_Flow;
    friend class FlowUTest;
    friend class ModelFactory;
    
    protected:
        string name;    /**< Flow name */
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
        FlowBody();

        /**
         * @brief Constructor with name and two systems
         * 
         * @param name Name of the flow
         * @param source Pointer to the source system
         * @param target Pointer to the target system
         */
        FlowBody(string name, System* source, System* target);

        /**
         * @brief Copy constructor
         * 
         * Creates a new Flow object by copying the data from the provided object.
         * 
         * @param other Flow object to be copied
         */
        FlowBody(const FlowBody &other);
        
        //Destructor
        virtual ~FlowBody(){};

        /**
         * @brief Assignment operator overload
         * 
         * Copies the data from one Flow object to another, ensuring no self-assignment occurs.
         * 
         * @param other Flow object to be copied
         * @return Reference to the Flow object after assignment
         */
        FlowBody& operator=(const FlowBody &other);

        //===================Getters and Setters===================//

        /**
         * @brief Sets the target system of the flow
         * 
         * @param s Pointer to the target system
         */
        void setTarget(System* s);

        /**
         * @brief Sets the source system of the flow
         * 
         * @param s Pointer to the source system
         */
        void setSource(System* s);

        /**
         * @brief Sets the name of the flow
         * 
         * @param string Name of the flow
         */
        void setName(const string name);

        /**
         * @brief Gets the target system of the flow
         * 
         * @return Pointer to the target system
         */
        System* getTarget();
        
        /**
         * @brief Gets the source system of the flow
         * 
         * @return Pointer to the source system
         */  
        System* getSource();

        /**
         * @brief Gets the name of the flow
         * 
         * @return Name of the flow
         */
        string getName();
        
        //===================Class functions===================//
        
        /**
         * @brief Clears the flow data
         * 
         * Resets the pointers to the source and target systems to NULL.
         */
        void clear();
};

/**
 * @class FlowHandle
 * @brief Represents the handle for the Flow class.
 * 
 */
class FlowHandle : public Flow, public Handle<FlowBody>
{
    public:

        FlowHandle()
        {
            pImpl_->setName("");
            pImpl_->setSource(nullptr);
            pImpl_->setTarget(nullptr);
        };

        FlowHandle(const string name, System* source, System* target)
        {
            pImpl_->setName(name);
            pImpl_->setSource(source);
            pImpl_->setTarget(target);
        };

        void setName(const string name)  { pImpl_->setName(name);      }
        void setSource(System* s)        { pImpl_->setSource(s);       }
        void setTarget(System* s)        { pImpl_->setTarget(s);       }
        System* getTarget()              { return pImpl_->getTarget(); }
        System* getSource()              { return pImpl_->getSource(); }
        string getName()                 { return pImpl_->getName();   }
        void clear()                     { pImpl_->clear();            }

};

#endif