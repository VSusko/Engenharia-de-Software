#include "funcional_tests.h"
#include <cassert>
#include <cmath>

//Execute for the exponential class
double Exponential::execute()
{
    return (source->getValue() * 0.01);
}

//Execute for the logistical class
double Logistical::execute()
{
    return (target->getValue() * 0.01 * (1 - target->getValue() / 70));
}

//Execute for the complex class
double Complex::execute()
{
    return (source->getValue() * 0.01);
}

//Exponential test
void exponentialFuncionalTest()
{
    System* pop1 = new System("pop1", 100);
    System* pop2 = new System("pop2", 0);

    Exponential* flow = new Exponential("exp", pop1, pop2);

    Model model = Model("model");

    model.add(pop1);
    model.add(pop2);
    model.add(flow);
    
    model.simulate(0,99,1);

    assert(_approximate(fabs(pop1->getValue() - 36.6032) < 0.0001));
    assert(_approximate(fabs(pop2->getValue() - 63.3968) < 0.0001));

    delete pop1; 
    delete pop2; 
    delete flow;
}

//Logical test
void logisticalFuncionalTest()
{
    System* p1 = new System("p1", 100);
    System* p2 = new System("p2", 10);

    Logistical* flow = new Logistical("exp", p1, p2);

    Model model = Model("model");

    model.add(p1);
    model.add(p2);
    model.add(flow);
    
    model.simulate(0,99,1);

    assert(_approximate(fabs(p1->getValue() - 88.2167) < 0.0001));
    assert(_approximate(fabs(p2->getValue() - 21.7833) < 0.0001));

    delete p1; 
    delete p2; 
    delete flow;
}

//Complex test
void complexFuncionalTest()
{
    System* q1 = new System("q1", 100);
    System* q2 = new System("q2", 0);
    System* q3 = new System("q3", 100);
    System* q4 = new System("q4", 0);
    System* q5 = new System("q5", 0);

    Complex* flowG = new Complex("g", q1, q3);
    Complex* flowF = new Complex("f", q1, q2);
    Complex* flowR = new Complex("r", q2, q5);
    Complex* flowT = new Complex("t", q2, q3);
    Complex* flowU = new Complex("u", q3, q4);
    Complex* flowV = new Complex("v", q4, q1);

    Model model = Model("model");

    model.add(q1); model.add(q2); model.add(q3);
    model.add(q4); model.add(q5);
    model.add(flowG); model.add(flowF); model.add(flowR);
    model.add(flowT); model.add(flowU); model.add(flowV);

    model.simulate(0,99,1);

    assert(_approximate(fabs(q1->getValue() - 31.8513) < 0.0001));
    assert(_approximate(fabs(q2->getValue() - 18.4003) < 0.0001));
    assert(_approximate(fabs(q3->getValue() - 77.1143) < 0.0001));
    assert(_approximate(fabs(q4->getValue() - 56.1728) < 0.0001));
    assert(_approximate(fabs(q5->getValue() - 16.4612) < 0.0001));

    delete q1; delete q2; delete q3; 
    delete q4; delete q5; 
    delete flowG; delete flowF; delete flowR; 
    delete flowT; delete flowU; delete flowV; 
}