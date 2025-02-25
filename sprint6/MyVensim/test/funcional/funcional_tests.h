#ifndef FUNCIONAL_TESTS
#define FUNCIONAL_TESTS

#include "../../src/model.h"
#include "../../src/flow_impl.h"
#include <cassert>
#include <cmath>

#define _approximate(_X)    (round(10000.0 * (_X)) / 10000.0)

//===================Flow Derived Classes===================//

/**
 * @class Exponential
 * @brief Derived class from Flow that will do the Exponential functional test
 * 
 * 
 */
class Exponential : public FlowHandle {
    public:
        Exponential(){}
        Exponential(string name, System* source, System* target) : FlowHandle(name,source,target){}
        virtual double execute();
};

/**
 * @class Logistical
 * @brief Derived class from Flow that will do the Logistical functional test
 * 
 * 
 */
class Logistical : public FlowHandle {
    public:
        Logistical(){}
        Logistical(string name, System* source, System* target) : FlowHandle(name,source,target){}
        virtual double execute();
};

/**
 * @class Complex
 * @brief Derived class from Flow that will do the Complex functional test
 * 
 * 
 */
class Complex : public FlowHandle {
    public:
        Complex(){}
        Complex(string name, System* source, System* target) : FlowHandle(name,source,target){}
        virtual double execute();
};

//===================Functional Test functions===================//

/**
 * @brief Function that makes the exponential test
 * 
 */
void exponentialFuncionalTest();

/**
 * @brief Function that makes the logistical test
 * 
 */
void logisticalFuncionalTest();

/**
 * @brief Function that makes the complex test
 * 
 */
void complexFuncionalTest();

#endif