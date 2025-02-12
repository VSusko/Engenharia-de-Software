#include "unit_Flow.h"

void unit_Flow::testFlowDefaultConstructor() {
    FlowUTest flow1;
    assert(flow1.name   == "");
    assert(flow1.source == nullptr);
    assert(flow1.target == nullptr);
}

void unit_Flow::testFlowParameterizedConstructor() {
    SystemImpl p1;
    SystemImpl p2;
    FlowUTest flow2("flow2", &p1, &p2);
    assert(flow2.name   == "flow2");
    assert(flow2.source == &p1);
    assert(flow2.target == &p2);
}

void unit_Flow::testFlowGetters() {
    SystemImpl p1;
    SystemImpl p2;
    FlowUTest flow;
    flow.name    = "getterTest";
    flow.source  = &p1;
    flow.target  = &p2;
    assert(flow.getName()   == "getterTest");
    assert(flow.getSource() == &p1);
    assert(flow.getTarget() == &p2);
}


void unit_Flow::testFlowSetters() {
    SystemImpl p1;
    SystemImpl p2;
    FlowUTest flow1;
    
    flow1.setName("setterTest");
    flow1.setSource(&p1);
    flow1.setTarget(&p2);
    assert(flow1.name   == "setterTest");
    assert(flow1.source == &p1);
    assert(flow1.target == &p2);
}


void unit_Flow::testFlowCopyConstructor() {
    SystemImpl p1;
    SystemImpl p2;
    FlowUTest flow2("copyConstructor", &p1, &p2);
    FlowUTest flow3(flow2);
    assert(flow3.name   == "copyConstructor");
    assert(flow3.source == &p1);
    assert(flow3.target == &p2);
}


void unit_Flow::testFlowCopyOperator() {
    SystemImpl p1;
    SystemImpl p2;
    FlowUTest flow1;
    FlowUTest flow2("copyOperator", &p1, &p2);
    flow1 = flow2;
    assert(flow1.name   == "copyOperator");
    assert(flow1.source == &p1);
    assert(flow1.target == &p2);
}


void unit_Flow::testFlowSelfAssignment() {
    SystemImpl p1;
    SystemImpl p2;
    FlowUTest flow;
    flow.name   = "selfAssign";
    flow.source = &p1;
    flow.target = &p2;
    flow = flow;
    assert(flow.name   == "selfAssign");
    assert(flow.source == &p1);
    assert(flow.target == &p2);
}


void unit_Flow::testFlowClear() {
    SystemImpl p1;
    SystemImpl p2;
    FlowUTest flow1("flow1", &p1, &p2);
    flow1.clear();
    assert(flow1.source == nullptr);
    assert(flow1.target == nullptr);
}


void unit_Flow::testFlowExecute() {
    SystemImpl p1;
    SystemImpl p2;
    FlowUTest flow;
    flow.source = &p1;
    flow.target = &p2;

    assert(flow.execute() == 0);
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
    testFlowExecute();
}
