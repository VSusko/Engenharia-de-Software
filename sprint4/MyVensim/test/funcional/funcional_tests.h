#ifndef FUNCIONAL_TESTS
#define FUNCIONAL_TESTS

#include "../../src/model_impl.h"
#include "../../src/system_impl.h"
#include "../../src/flow_impl.h"
#define _approximate(_X)    (round(10000.0 * (_X)) / 10000.0)

//===================Flow Derived Classes===================//

/**
 * @class Exponential
 * @brief Derived class from Flow that will do the Exponential functional test
 * 
 * 
 */
class Exponential : public FlowImpl {
    public:
        Exponential(){}
        Exponential(string _name, System* _source, System* _target) : FlowImpl(_name,_source,_target){}
        virtual double execute();
};

/**
 * @class Logistical
 * @brief Derived class from Flow that will do the Logistical functional test
 * 
 * 
 */
class Logistical : public FlowImpl {
    public:
        Logistical(){}
        Logistical(string _name, System* _source, System* _target) : FlowImpl(_name,_source,_target){}
        virtual double execute();
};

/**
 * @class Complex
 * @brief Derived class from Flow that will do the Complex functional test
 * 
 * 
 */
class Complex : public FlowImpl {
    public:
        Complex(){}
        Complex(string _name, System* _source, System* _target) : FlowImpl(_name,_source,_target){}
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