#include "unit_Flow.h"

//Default constructor test
void testFlowDefaultConstructor() {
    Expression* flow1 = new Expression();
    assert(flow1->getName() == "");
    assert(flow1->getSource() == NULL);
    assert(flow1->getTarget() == NULL);
    delete flow1;
}

//Constructor with name and 2 systems test
void testFlowParameterizedConstructor() {
    System* p1 = new SystemImpl("p1", 0);
    System* p2 = new SystemImpl("p2", 100);
    Expression* flow2 = new Expression("flow2", p1, p2);
    assert(flow2->getName() == "flow2");
    assert(flow2->getSource() == p1);
    assert(flow2->getTarget() == p2);
    delete flow2;
    delete p1;
    delete p2;
}

//Setters test
void testFlowSetters() {
    System* p1 = new SystemImpl("p1", 0);
    System* p2 = new SystemImpl("p2", 100);
    Expression* flow1 = new Expression();
    flow1->setName("test");
    assert(flow1->getName() == "test");
    flow1->setSource(p1);
    assert(flow1->getSource() == p1);
    flow1->setTarget(p2);
    assert(flow1->getTarget() == p2);
    delete flow1;
    delete p1;
    delete p2;
}

//Copy constructor test
void testFlowCopyConstructor() {
    System* p1 = new SystemImpl("p1", 0);
    System* p2 = new SystemImpl("p2", 100);
    Expression* flow2 = new Expression("flow2", p1, p2);
    Expression* flow3 = new Expression(*flow2);
    assert(flow3->getName() == "flow2");
    assert(flow3->getSource() == p1);
    assert(flow3->getTarget() == p2);
    delete flow2;
    delete flow3;
    delete p1;
    delete p2;
}

//Copy operator test
void testFlowCopyOperator() {
    System* p1 = new SystemImpl("p1", 0);
    System* p2 = new SystemImpl("p2", 100);
    Expression* flow1 = new Expression();
    Expression* flow2 = new Expression("flow2", p1, p2);
    *flow1 = *flow2;
    assert(flow1->getName() == "flow2");
    assert(flow1->getSource() == p1);
    assert(flow1->getTarget() == p2);
    delete flow1;
    delete flow2;
    delete p1;
    delete p2;
}

//Clear test
void testFlowClear() {
    SystemImpl* p1 = new SystemImpl("p1", 0);
    SystemImpl* p2 = new SystemImpl("p2", 100);
    Expression* flow1 = new Expression("flow1", p1, p2);
    flow1->clear();
    assert(flow1->getSource() == NULL);
    assert(flow1->getTarget() == NULL);
    delete flow1;
    delete p1;
    delete p2;
}

// Running all tests
void runFlowTests() {
    testFlowDefaultConstructor();
    testFlowParameterizedConstructor();
    testFlowSetters();
    testFlowCopyConstructor();
    testFlowCopyOperator();
    testFlowClear();
}
