#ifndef FUNCIONAL_TESTS
#define FUNCIONAL_TESTS

#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#define _approximate(_X)    (round(10000.0 * (_X)) / 10000.0)

class Exponential : public Flow {
    public:
        Exponential(){}
        Exponential(string _name, System* _source, System* _target) : Flow(_name,_source,_target){}
        virtual double execute();
};


class Logistical : public Flow {
    public:
        Logistical(){}
        Logistical(string _name, System* _source, System* _target) : Flow(_name,_source,_target){}
        virtual double execute();
};

class Complex : public Flow {
    public:
        Complex(){}
        Complex(string _name, System* _source, System* _target) : Flow(_name,_source,_target){}
        virtual double execute();
};


void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif