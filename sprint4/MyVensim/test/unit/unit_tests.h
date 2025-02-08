#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "../../src/model_impl.h"
#include "../../src/system_impl.h"
#include "../../src/flow_impl.h"

#include <cassert>
#include <cmath>

class FlowUTest : public FlowImpl {
public:
    FlowUTest() {}
    FlowUTest(string name, System* source, System* target)
        : FlowImpl(name, source, target) {}

    virtual double execute() override { 
        return getSource()->getValue() * 0.01;
    }
};



#endif
