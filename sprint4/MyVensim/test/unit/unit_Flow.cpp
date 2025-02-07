#include "unit_Flow.h"

void unit_Flow::testFlowDefaultConstructor() {
    Expression* flow1 = new Expression();
    assert(flow1->getName() == "");
    assert(flow1->getSource() == NULL);
    assert(flow1->getTarget() == NULL);
    delete flow1;
}

void unit_Flow::testFlowParameterizedConstructor() {
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


void unit_Flow::testFlowSetters() {
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


void unit_Flow::testFlowCopyConstructor() {
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


void unit_Flow::testFlowCopyOperator() {
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


void unit_Flow::testFlowClear() {
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


void unit_Flow::runFlowTests() {
    testFlowDefaultConstructor();
    testFlowParameterizedConstructor();
    testFlowSetters();
    testFlowCopyConstructor();
    testFlowCopyOperator();
    testFlowClear();
}
