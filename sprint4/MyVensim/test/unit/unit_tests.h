#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "../../src/model_impl.h"
#include "../../src/system_impl.h"
#include "../../src/flow_impl.h"


class Expression : public FlowImpl {
    public:
        Expression(){}
        Expression(string _name, SystemImpl* _source, SystemImpl* _target) : FlowImpl(_name, _source, _target){}
        virtual double execute(){ return (source->getValue() * 0.01); }
};


void runSystemTests();
void runFlowTests();
void runModelTests();

#endif