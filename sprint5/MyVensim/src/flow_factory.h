#ifndef FLOW_FACTORY_H
#define FLOW_FACTORY_H

#include "flow_impl.h"

/**
 * @class FlowMainTest
 * @brief Derived class from FlowImpl that will be used on a main test
 * 
 * 
 */
class FlowMainTest : public FlowImpl {
    public:
        FlowMainTest() {}
        FlowMainTest(string name, System* source, System* target)
            : FlowImpl(name, source, target) {}
    
        virtual double execute() override { 
            return (getSource()->getValue() * 0);
        }
    };



/**
 * @class FlowFactory
 * @brief Factory class to create Flow instances.
 */
class FlowFactory {
public:
    /**
     * @brief Creates a new Flow instance.
     * @return Pointer to the newly created Flow.
     */
    static Flow* createFlow() {
        return new FlowMainTest();
    }

    /**
     * @brief Creates a new Flow instance with a name.
     * @param name The name of the Flow.
     * @return Pointer to the newly created Flow.
     */
    static Flow* createFlow(const string& name, System* source, System* target) {
        return new FlowMainTest(name, source, target);
    }
};

#endif
