#include "unit_Flow.h"

void unit_Flow::testFlowDefaultConstructor() {
    FlowUTest* flow1 = new FlowUTest();
    assert(flow1->name == "");
    assert(flow1->source == nullptr);
    assert(flow1->target == nullptr);
    delete flow1;
}

void unit_Flow::testFlowParameterizedConstructor() {
    System* p1 = new SystemImpl("p1", 0);
    System* p2 = new SystemImpl("p2", 100);
    FlowUTest* flow2 = new FlowUTest("flow2", p1, p2);
    assert(flow2->name == "flow2");
    assert(flow2->source == p1);
    assert(flow2->target == p2);
    delete flow2;
    delete p1;
    delete p2;
}

void unit_Flow::testFlowGetters() {
    System* p1 = new SystemImpl("p1", 0);
    System* p2 = new SystemImpl("p2", 100);
    FlowUTest* flow = new FlowUTest("getterTest", p1, p2);
    assert(flow->getName() == "getterTest");
    assert(flow->getSource() == p1);
    assert(flow->getTarget() == p2);
    delete flow;
    delete p1;
    delete p2;
}


void unit_Flow::testFlowSetters() {
    System* p1 = new SystemImpl("p1", 0);
    System* p2 = new SystemImpl("p2", 100);
    FlowUTest* flow1 = new FlowUTest();
    flow1->setName("setterTest");
    assert(flow1->name == "setterTest");
    flow1->setSource(p1);
    assert(flow1->source == p1);
    flow1->setTarget(p2);
    assert(flow1->target == p2);
    delete flow1;
    delete p1;
    delete p2;
}


void unit_Flow::testFlowCopyConstructor() {
    System* p1 = new SystemImpl("p1", 0);
    System* p2 = new SystemImpl("p2", 100);
    FlowUTest* flow2 = new FlowUTest("copyConstructor", p1, p2);
    FlowUTest* flow3 = new FlowUTest(*flow2);
    assert(flow3->name == "copyConstructor");
    assert(flow3->source == p1);
    assert(flow3->target == p2);
    delete flow2;
    delete flow3;
    delete p1;
    delete p2;
}


void unit_Flow::testFlowCopyOperator() {
    System* p1 = new SystemImpl("p1", 0);
    System* p2 = new SystemImpl("p2", 100);
    FlowUTest* flow1 = new FlowUTest();
    FlowUTest* flow2 = new FlowUTest("copyOperator", p1, p2);
    *flow1 = *flow2;
    assert(flow1->name == "copyOperator");
    assert(flow1->source == p1);
    assert(flow1->target == p2);
    delete flow1;
    delete flow2;
    delete p1;
    delete p2;
}

void unit_Flow::testFlowSelfAssignment() {
    System* p1 = new SystemImpl("p1", 0);
    System* p2 = new SystemImpl("p2", 100);
    FlowUTest* flow = new FlowUTest("selfAssign", p1, p2);
    *flow = *flow;
    assert(flow->name == "selfAssign");
    assert(flow->source == p1);
    assert(flow->target == p2);
    delete flow;
    delete p1;
    delete p2;
}



void unit_Flow::testFlowClear() {
    SystemImpl* p1 = new SystemImpl("p1", 0);
    SystemImpl* p2 = new SystemImpl("p2", 100);
    FlowUTest* flow1 = new FlowUTest("flow1", p1, p2);
    flow1->clear();
    assert(flow1->source == nullptr);
    assert(flow1->target == nullptr);
    delete flow1;
    delete p1;
    delete p2;
}

void unit_Flow::testFlowEdgeCases() {
    FlowUTest* flow = new FlowUTest("", nullptr, nullptr);
    assert(flow->name == "");
    assert(flow->source == nullptr);
    assert(flow->target == nullptr);

    System* p1 = new SystemImpl("p1", -100);
    flow->setSource(p1);
    assert(flow->getSource() == p1);

    delete flow;
    delete p1;
}

void unit_Flow::testFlowExecute() {
    System* p1 = new SystemImpl("source", 50);
    System* p2 = new SystemImpl("target", 100);
    FlowUTest* flow = new FlowUTest("executeTest", p1, p2);
    
    double result = flow->execute();
    assert(result >= 0);
    
    delete flow;
    delete p1;
    delete p2;
}



void unit_Flow::runFlowTests() {
    testFlowDefaultConstructor();
    testFlowParameterizedConstructor();
    testFlowGetters();
    testFlowSetters();
    testFlowCopyConstructor();
    testFlowCopyOperator();
    testFlowSelfAssignment();
    testFlowClear();
    testFlowEdgeCases();
    testFlowExecute();
}
