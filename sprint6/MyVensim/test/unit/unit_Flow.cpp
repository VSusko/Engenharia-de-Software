#include "unit_Flow.h"

void unit_Flow::testFlowDefaultConstructor() {
    Model* model = Model::createModel("model");
    Flow *flow1 = model->createFlow<FlowUTest>("", nullptr, nullptr);
    assert(dynamic_cast<FlowUTest*>(flow1)->name == "");
    assert(dynamic_cast<FlowUTest*>(flow1)->source == nullptr);
    assert(dynamic_cast<FlowUTest*>(flow1)->target == nullptr);
}

void unit_Flow::testFlowParameterizedConstructor() {
    Model* model = Model::createModel("model");
    System *p1 = model->createSystem("", 0);
    System *p2 = model->createSystem("", 0);
    Flow *flow2 = model->createFlow<FlowUTest>("flow2", p1, p2);
    assert(dynamic_cast<FlowUTest*>(flow2)->name == "flow2");
    assert(dynamic_cast<FlowUTest*>(flow2)->source == p1);
    assert(dynamic_cast<FlowUTest*>(flow2)->target == p2);
}

void unit_Flow::testFlowGetters() {
    Model* model = Model::createModel("model");
    Flow *flow = model->createFlow<FlowUTest>("", nullptr, nullptr);
    System *p1 = model->createSystem("", 0);
    System *p2 = model->createSystem("", 0);
    flow->setName("getterTest");
    flow->setSource(p1);
    dynamic_cast<FlowUTest*>(flow)->target = p2;
    assert(flow->getName() == "getterTest");
    assert(flow->getSource() == p1);
    assert(flow->getTarget() == p2);
}

void unit_Flow::testFlowSetters() {
    Model* model = Model::createModel("model");
    Flow *flow1 = model->createFlow<FlowUTest>("", nullptr, nullptr);
    System *p1 = model->createSystem("", 0);
    System *p2 = model->createSystem("", 0);
    flow1->setName("setterTest");
    flow1->setSource(p1);
    flow1->setTarget(p2);
    assert(dynamic_cast<FlowUTest*>(flow1)->name == "setterTest");
    assert(dynamic_cast<FlowUTest*>(flow1)->source == p1);
    assert(dynamic_cast<FlowUTest*>(flow1)->target == p2);
}

void unit_Flow::testFlowClear() {
    Model* model = Model::createModel("model");
    Flow *flow1 = model->createFlow<FlowUTest>("flow1", nullptr, nullptr);
    dynamic_cast<FlowUTest*>(flow1)->clear();
    assert(dynamic_cast<FlowUTest*>(flow1)->source == nullptr);
    assert(dynamic_cast<FlowUTest*>(flow1)->target == nullptr);
}

void unit_Flow::testFlowExecute() {
    Model* model = Model::createModel("model");
    Flow *flow = model->createFlow<FlowUTest>("", nullptr, nullptr);
    System *p1 = model->createSystem("", 0);
    System *p2 = model->createSystem("", 0);
    dynamic_cast<FlowUTest*>(flow)->source = p1;
    dynamic_cast<FlowUTest*>(flow)->target = p2;
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
