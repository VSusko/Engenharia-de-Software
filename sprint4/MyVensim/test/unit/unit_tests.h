#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "../../src/model_impl.h"
#include "../../src/system_impl.h"
#include "../../src/flow_impl.h"

#include <cassert>
#include <cmath>

class Expression : public FlowImpl {
public:
    Expression() {}
    Expression(string _name, System* _source, System* _target)
        : FlowImpl(_name, _source, _target) {}

    virtual double execute() override { 
        return getSource()->getValue() * 0.01;
    }
};



#endif
