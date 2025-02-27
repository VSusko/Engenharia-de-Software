#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "../../src/model_impl.h"
#include <cassert>
#include <cmath>
#include <sstream>


/**
 * @class FlowUTest
 * @brief Derived class from FlowImpl that will be used on unitary tests
 * 
 * 
 */
class FlowUTest : public FlowHandle {
    public:
        FlowUTest() {}
        FlowUTest(string name, System* source, System* target) : FlowHandle(name, source, target){}
        double execute(){ 
            return (getSource()->getValue() * 0);
        };
    };
    

#endif
