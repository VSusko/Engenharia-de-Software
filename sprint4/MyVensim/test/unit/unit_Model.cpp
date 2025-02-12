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
    SystemImpl p1;
    model1.add(&p1);
    assert(model1.systems[0] == &p1);
}


void unit_Model::testModelCopyConstructor() {
    ModelImpl model1;
    SystemImpl s1;
    FlowUTest f1;
    
    model1.name = "original";
    model1.systems.push_back(&s1);
    model1.flows.push_back(&f1);
    //model1.systems[0] = &s;
    //model1.flows[0]   = &f;
    
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
    assert(!model1.systems.empty());
    assert(!model1.flows.empty());
    //assert(model2.systems[0] != nullptr);
    //assert(model2.flows[0]   != nullptr);
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
    //assert(model1.systems[0]  == nullptr);
    assert(model1.systems.empty());
}


void unit_Model::testModelRemoveFlow() {
    ModelImpl  model1;
    FlowUTest  f1;
    model1.flows.push_back(&f1);
    
    assert(model1.remove(&f1) == true);
    assert(model1.flows.empty());
    //assert(model1.flows[0]    == nullptr);
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

    model1.add(&s1);
    model1.add(&f1);
    
    assert(model1.getName()       == "getterTest");
    assert(model1.getSystem("s1") == &s1);
    assert(model1.getFlow("f1")   == &f1);
    assert(model1.getSystem("nonexistentSystem") == nullptr);
    assert(model1.getFlow("nonexistentFlow")     == nullptr);
}


void unit_Model::testModelExists() {
    ModelImpl model1;
    SystemImpl s1;
    FlowUTest f1;

    model1.add(&s1);
    model1.add(&f1);

    assert(model1.exists(&s1) == true);
    assert(model1.exists(&f1) == true);

    SystemImpl s2;
    assert(model1.exists(&s2) == false);
}


void unit_Model::testModelClear() {
    ModelImpl model1;
    SystemImpl s1;
    FlowUTest f1;

    model1.add(&s1);
    model1.add(&f1);

    model1.clear();
    assert(model1.systems.size() == 1);
    assert(model1.flows.size() == 1);
    //assert(model.systems[0] == nullptr);
    //assert(model.flows[0]   == nullptr);
}


void unit_Model::testModelSimulate() {
    ModelImpl model1;
    model1.simulate(0,10,1);
    assert(model1.clock == 11);
}

void unit_Model::testModelReport() {
    // ModelImpl  model1;
    // SystemImpl s1;

    // model.systems[0] = &s1;

    // // Creating an output flow that is going to capture what was printed in method report()
    // ostringstream capture;
    // // Redirecting its flow:
    // streambuf OriginalBufferFlow = cout.rdbuf(capture.rdbuf());
    
    // model1.report();

    // // Restoring the original flow
    // cout.rdbuf(OriginalBufferFlow);

    // assert(capture.str() == "System name: | Value: 0\n");
}

void unit_Model::runModelTests() {
    testModelReport();
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
