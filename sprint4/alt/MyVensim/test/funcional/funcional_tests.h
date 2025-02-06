#ifndef FUNCIONAL_TESTS
#define FUNCIONAL_TESTS

#include "../../src/model_impl.h"
#include "../../src/system_impl.h"
#include "../../src/flow_impl.h"
#define _approximate(_X)    (round(10000.0 * (_X)) / 10000.0)

class Exponential : public FlowImpl {
    public:
        Exponential(){}
        Exponential(string _name, System* _source, System* _target) : FlowImpl(_name,_source,_target){}
        virtual double execute();
};


class Logistical : public FlowImpl {
    public:
        Logistical(){}
        Logistical(string _name, System* _source, System* _target) : FlowImpl(_name,_source,_target){}
        virtual double execute();
};

class Complex : public FlowImpl {
    public:
        Complex(){}
        Complex(string _name, System* _source, System* _target) : FlowImpl(_name,_source,_target){}
        virtual double execute();
};


void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif