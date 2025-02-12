#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "../../src/model_impl.h"
#include "../../src/system_impl.h"
#include "../../src/flow_impl.h"

#include <cassert>
#include <cmath>
#include <sstream>

/**
 * @class FlowUTest
 * @brief Derived class from FlowImpl that will be used on unitary tests
 * 
 * 
 */
class FlowUTest : public FlowImpl {
public:
    FlowUTest() {}
    FlowUTest(string name, System* source, System* target)
        : FlowImpl(name, source, target) {}

    virtual double execute() override { 
        return (getSource()->getValue() * 0);
    }
};



#endif
