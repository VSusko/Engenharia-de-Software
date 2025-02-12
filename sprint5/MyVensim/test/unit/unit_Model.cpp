#include "unit_Model.h"


void unit_Model::testModelDefaultConstructor() {
    ModelImpl model1;
    assert(model1.name == "");
}


void unit_Model::testModelParameterizedConstructor() {
    ModelImpl model2("model2");
    assert(model2.name == "model2");
}


void unit_Model::testModelSetters() {
    ModelImpl model1;
    model1.setName("setterTest");
    assert(model1.name == "setterTest");
}


void unit_Model::testModelAdd() {
    ModelImpl model1;
    SystemImpl s1("s1", 10);
    FlowUTest f1("f1",nullptr,nullptr);

    model1.add(&s1);
    model1.add(&f1);
    assert(model1.systems[0] == &s1);
    assert(model1.flows[0]   == &f1);
}


void unit_Model::testModelCopyConstructor() {
    ModelImpl model1;
    SystemImpl s1;
    FlowUTest f1;
    
    model1.name = "original";
    model1.systems.push_back(&s1);
    model1.flows.push_back(&f1);
    
    ModelImpl model2 = ModelImpl(model1);
    
    assert(model2.name       == "original");
    assert(model2.systems[0] == &s1);
    assert(model2.flows[0]   == &f1);
}

void unit_Model::testModelCopyOperator() {
    ModelImpl  model1;
    SystemImpl s1;
    FlowUTest  f1;
    
    model1.name = "original";
    model1.systems.push_back(&s1);
    model1.flows.push_back(&f1);
    ModelImpl model2 = model1;
    
    assert(model2.name       == "original");
    assert(model2.systems[0] == &s1);
    assert(model2.flows[0]   == &f1);
}


void unit_Model::testModelAssignmentOperator() {
    ModelImpl model1;
    model1.name = "model1";
    SystemImpl s1;
    model1.systems.push_back(&s1);

    model1 = model1;
    assert(model1.name       == "model1");
    assert(model1.systems[0] == &s1);
}


void unit_Model::testModelRemoveSystem() {
    ModelImpl  model1;
    SystemImpl s1;
    model1.systems.push_back(&s1);
    
    assert(model1.remove(&s1) == true);
    assert(model1.systems.empty());
}


void unit_Model::testModelRemoveFlow() {
    ModelImpl  model1;
    FlowUTest  f1;
    model1.flows.push_back(&f1);
    
    assert(model1.remove(&f1) == true);
    assert(model1.flows.empty());
}


void unit_Model::testModelAddDuplicatesSystem() {
    ModelImpl model1;
    SystemImpl s1;
    
    assert(model1.add(&s1) == true);
    assert(model1.add(&s1) == false);
}


void unit_Model::testModelAddDuplicatesFlow() {
    ModelImpl  model1;
    FlowUTest  f1;
    
    assert(model1.add(&f1) == true);
    assert(model1.add(&f1) == false); 
}


void unit_Model::testModelGetters() {
    ModelImpl model1;
    model1.name = "getterTest";
    SystemImpl s1("s1", 1);
    FlowUTest  f1("f1", nullptr, nullptr);

    model1.systems.push_back(&s1);
    model1.flows.push_back(&f1);
    
    assert(model1.getName()       == "getterTest");
    assert(model1.getSystem("s1") == &s1);
    assert(model1.getFlow("f1")   == &f1);
    assert(model1.getSystem("nonexistentSystem") == nullptr);
    assert(model1.getFlow("nonexistentFlow")     == nullptr);
}


void unit_Model::testModelExists() {
    ModelImpl model1;
    SystemImpl s1("s1", 10);
    FlowUTest f1("f1", nullptr, nullptr);

    model1.systems.push_back(&s1);
    model1.flows.push_back(&f1);

    assert(model1.exists(&s1) == true);
    assert(model1.exists(&f1) == true);

    SystemImpl s2("s2", 20);
    assert(model1.exists(&s2) == false);
}


void unit_Model::testModelClear() {
    ModelImpl model1;
    SystemImpl s1;
    FlowUTest f1;

    model1.systems.push_back(&s1);
    model1.flows.push_back(&f1);

    model1.clear();

    assert(model1.systems.size() == 1);
    assert(model1.flows.size() == 1);
}


void unit_Model::testModelSimulate() {
    ModelImpl model1;
    model1.simulate(0,10,1);
    assert(model1.clock == 11);
}


void unit_Model::runModelTests() {
    testModelDefaultConstructor();
    testModelParameterizedConstructor();
    testModelSetters();
    testModelAdd();
    testModelCopyConstructor();
    testModelCopyOperator();
    testModelAssignmentOperator();
    testModelRemoveSystem();
    testModelRemoveFlow();
    testModelAddDuplicatesSystem();
    testModelAddDuplicatesFlow();
    testModelGetters();
    testModelExists();
    testModelClear();
    testModelSimulate();
}
