#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"


class Expression : public Flow {
    public:
        Expression(){}
        Expression(string _name, System* _source, System* _target) : Flow(_name,_source,_target){}
        virtual double execute();
};


void systemTest();
void flowTest();
void modelTest();

#endif