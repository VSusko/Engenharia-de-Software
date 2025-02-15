#include "unit_Flow.h"

void unit_Flow::testFlowDefaultConstructor() {
    Flow *flow1 = ModelFactory::createFlow();
    assert(dynamic_cast<FlowTest*>(flow1)->name == "");
    assert(dynamic_cast<FlowTest*>(flow1)->source == nullptr);
    assert(dynamic_cast<FlowTest*>(flow1)->target == nullptr);
}

void unit_Flow::testFlowParameterizedConstructor() {
    SystemImpl p1;
    SystemImpl p2;
    Flow *flow2 = ModelFactory::createFlow("flow2", &p1, &p2);
    assert(dynamic_cast<FlowTest*>(flow2)->name == "flow2");
    assert(dynamic_cast<FlowTest*>(flow2)->source == &p1);
    assert(dynamic_cast<FlowTest*>(flow2)->target == &p2);
}

void unit_Flow::testFlowGetters() {
    Flow *flow = ModelFactory::createFlow();
    SystemImpl p1;
    SystemImpl p2;
    dynamic_cast<FlowTest*>(flow)->name = "getterTest";
    dynamic_cast<FlowTest*>(flow)->source = &p1;
    dynamic_cast<FlowTest*>(flow)->target = &p2;
    assert(flow->getName() == "getterTest");
    assert(flow->getSource() == &p1);
    assert(flow->getTarget() == &p2);
}

void unit_Flow::testFlowSetters() {
    Flow *flow1 = ModelFactory::createFlow();
    SystemImpl p1;
    SystemImpl p2;
    flow1->setName("setterTest");
    flow1->setSource(&p1);
    flow1->setTarget(&p2);
    assert(dynamic_cast<FlowTest*>(flow1)->name == "setterTest");
    assert(dynamic_cast<FlowTest*>(flow1)->source == &p1);
    assert(dynamic_cast<FlowTest*>(flow1)->target == &p2);
}

void unit_Flow::testFlowClear() {
    Flow *flow1 = ModelFactory::createFlow("flow1", nullptr, nullptr);
    dynamic_cast<FlowTest*>(flow1)->clear();
    assert(dynamic_cast<FlowTest*>(flow1)->source == nullptr);
    assert(dynamic_cast<FlowTest*>(flow1)->target == nullptr);
}

void unit_Flow::testFlowExecute() {
    Flow *flow = ModelFactory::createFlow();
    SystemImpl p1;
    SystemImpl p2;
    dynamic_cast<FlowTest*>(flow)->source = &p1;
    dynamic_cast<FlowTest*>(flow)->target = &p2;
    assert(flow->execute() == 0);
}

void unit_Flow::runFlowTests() {
    testFlowDefaultConstructor();
    testFlowParameterizedConstructor();
    testFlowGetters();
    testFlowSetters();
    testFlowClear();
    testFlowExecute();
}
