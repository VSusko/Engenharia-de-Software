#include "funcional_tests.h"

//===================Execute overriding===================//

// Execute for the Exponential class
double Exponential::execute() {
    return (source->getValue() * 0.01);
}

// Execute for the Logistical class
double Logistical::execute() {
    return (target->getValue() * 0.01 * (1 - target->getValue() / 70));
}

// Execute for the Complex class
double Complex::execute() {
    return (source->getValue() * 0.01);
}

//===================Functional Tests===================//

void exponentialFuncionalTest() {
    Model* model = Model::createModel("model");

    System* pop1 = model->createSystem("pop1", 100);
    System* pop2 = model->createSystem("pop2", 0);

    Flow* flow = model->createFlow<Exponential>("exp", pop1, pop2);

    model->simulate(0, 99, 1);
    
    assert(_approximate(fabs(pop1->getValue() - 36.6032) < 0.0001));
    assert(_approximate(fabs(pop2->getValue() - 63.3968) < 0.0001));

    model->clear();
}

void logisticalFuncionalTest() {
    Model* model = Model::createModel("model");
    
    System* p1 = model->createSystem("p1", 100);
    System* p2 = model->createSystem("p2", 10);

    //Flow* flow = model->getInstance().createFlow<Logistical>("log", p1, p2);
    Flow* flow = model->createFlow<Logistical>("log", p1, p2);
    
    model->simulate(0, 99, 1);

    assert(_approximate(fabs(p1->getValue() - 88.2167) < 0.0001));
    assert(_approximate(fabs(p2->getValue() - 21.7833) < 0.0001));

    model->clear();
}

void complexFuncionalTest() {
    Model* model = Model::createModel("model");

    System* q1 = model->createSystem("q1", 100);
    System* q2 = model->createSystem("q2", 0);
    System* q3 = model->createSystem("q3", 100);
    System* q4 = model->createSystem("q4", 0);
    System* q5 = model->createSystem("q5", 0);

    Flow* flowG = model->createFlow<Complex>("g", q1, q3);
    Flow* flowF = model->createFlow<Complex>("f", q1, q2);
    Flow* flowR = model->createFlow<Complex>("r", q2, q5);
    Flow* flowT = model->createFlow<Complex>("t", q2, q3);
    Flow* flowU = model->createFlow<Complex>("u", q3, q4);
    Flow* flowV = model->createFlow<Complex>("v", q4, q1);

    model->simulate(0, 99, 1);

    assert(_approximate(fabs(q1->getValue() - 31.8513) < 0.0001));
    assert(_approximate(fabs(q2->getValue() - 18.4003) < 0.0001));
    assert(_approximate(fabs(q3->getValue() - 77.1143) < 0.0001));
    assert(_approximate(fabs(q4->getValue() - 56.1728) < 0.0001));
    assert(_approximate(fabs(q5->getValue() - 16.4612) < 0.0001));
}
