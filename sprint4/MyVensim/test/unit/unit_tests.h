#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "../../src/model_impl.h"
#include "../../src/system_impl.h"
#include "../../src/flow_impl.h"

#include <cassert>
#include <cmath>
#define _approximate(_X)    (round(10000.0 * (_X)) / 10000.0)

/**
 * @class FlowUTests
 * @brief Derived class from Flow for the unitary tests 
 * 
 * 
 */
class FlowUTests : public FlowImpl {

public:
    FlowUTests(){}
    FlowUTests(string name, System* source, System* target) : FlowImpl(name, source, target){}
    virtual double execute() override { 
        return getSource()->getValue() * 0.01;
    }
};



#endif
