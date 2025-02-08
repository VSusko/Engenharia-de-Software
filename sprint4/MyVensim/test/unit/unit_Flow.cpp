#include "unit_Flow.h"

void unit_Flow::testFlowDefaultConstructor() {
    FlowUTests* flow1 = new FlowUTests();

    assert(flow1->name == "");
    assert(flow1->source == NULL);
    assert(flow1->target == NULL);
    
    delete flow1;
}

void unit_Flow::testFlowParameterizedConstructor() {
    System* p1 = new SystemImpl("p1", 0);
    System* p2 = new SystemImpl("p2", 100);
    FlowUTests* flow2 = new FlowUTests("flow2", p1, p2);

    assert(flow2->name == "flow2");
    assert(flow2->source == p1);
    assert(flow2->target == p2);

    delete flow2;
    delete p1;
    delete p2;
}


void unit_Flow::testFlowSetters() {
    System* p1 = new SystemImpl("p1", 0);
    System* p2 = new SystemImpl("p2", 100);
    FlowUTests* flow1 = new FlowUTests();

    flow1->setName("test");
    assert(flow1->name == "test");
    
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

    FlowUTests* flow2 = new FlowUTests("flow2", p1, p2);
    FlowUTests* flow3 = new FlowUTests(*flow2);

    assert(flow3->name == "flow2");
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
    FlowUTests* flow1 = new FlowUTests();
    FlowUTests* flow2 = new FlowUTests("flow2", p1, p2);

    *flow1 = *flow2;
    
    assert(flow1->name == "flow2");
    assert(flow1->source == p1);
    assert(flow1->target == p2);

    delete flow1;
    delete flow2;
    delete p1;
    delete p2;
}


void unit_Flow::testFlowClear() {
    SystemImpl* p1 = new SystemImpl("p1", 0);
    SystemImpl* p2 = new SystemImpl("p2", 100);
    FlowUTests* flow1 = new FlowUTests("flow1", p1, p2);

    flow1->clear();
    assert(flow1->source == NULL);
    assert(flow1->target == NULL);
    
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
