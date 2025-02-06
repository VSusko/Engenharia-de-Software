#include "unit_Model.h"

//Constructor with name and 2 systems test
void testModelDefaultConstructor() {
    ModelImpl* model1 = new ModelImpl();
    assert(model1->getName() == "");
    delete model1;
}

//Constructor with name 
void testModelParameterizedConstructor() {
    ModelImpl* model2 = new ModelImpl("model2");
    assert(model2->getName() == "model2");
    delete model2;
}

//Setters test
void testModelSetters() {
    ModelImpl* model1 = new ModelImpl();
    model1->setName("model1");
    assert(model1->getName() == "model1");
    delete model1;
}

//Add test
void testModelAdd() {
    ModelImpl* model1 = new ModelImpl();
    SystemImpl* p1 = new SystemImpl("p1", 100);
    model1->add(p1);
    assert(model1->getSystem("p1") == p1);
    delete model1;
    delete p1;
}

//Simulate test
void testModelSimulate() {
    ModelImpl* model1 = new ModelImpl();
    SystemImpl* p1 = new SystemImpl("p1", 100);
    SystemImpl* p2 = new SystemImpl("p2", 5);
    Expression* flow1 = new Expression("flow1", p1, p2);
    model1->add(p1);
    model1->add(p2);
    model1->add(flow1);
    model1->simulate(0, 9, 1);
    assert(fabs(p1->getValue() - 90.4382) < 0.0001);
    assert(fabs(p2->getValue() - 14.5618) < 0.0001);
    delete model1;
    delete p1;
    delete p2;
    delete flow1;
}

// Running all tests
void runModelTests() {
    testModelDefaultConstructor();
    testModelParameterizedConstructor();
    testModelSetters();
    testModelAdd();
    testModelSimulate();
}
