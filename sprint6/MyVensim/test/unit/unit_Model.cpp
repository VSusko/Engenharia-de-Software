#include "unit_Model.h"

void unit_Model::testModelDefaultConstructor() {
    Model *model1 = model1->createModel();
    assert(dynamic_cast<ModelImpl*>(model1)->name == "");
}

void unit_Model::testModelParameterizedConstructor() {
    Model *model2 = model2->createModel("model2");
    assert(dynamic_cast<ModelImpl*>(model2)->name == "model2");
}

void unit_Model::testModelSetters() {
    Model* model1 = model1->createModel();
    model1->setName("setterTest");
    assert(dynamic_cast<ModelImpl*>(model1)->name == "setterTest");
}


void unit_Model::testModelAdd() {
    Model* model1  = model1->createModel();
    System* s1     = model1->createSystem();
    Flow* f1       = model1->createFlow<FlowUTest>();

    assert(dynamic_cast<ModelImpl*>(model1)->systems[0] == s1);
    assert(dynamic_cast<ModelImpl*>(model1)->flows[0] == f1);
}


void unit_Model::testModelRemoveSystem() {
    Model* model1  = model1->createModel();
    System* s      = model1->createSystem("", 0);
    
    assert(model1->remove(s) == true);
}

void unit_Model::testModelRemoveFlow() {
    Model* model1  = model1->createModel();
    Flow*  f       = model1->createFlow<FlowUTest>("", nullptr, nullptr);
    
    assert(model1->remove(f) == true);
}


void unit_Model::testModelGetters() {
    Model *model1 = model1->createModel();
    dynamic_cast<ModelImpl*>(model1)->name = "getterTest";

    System* s1 = model1->createSystem("s1", 1);
    Flow*   f1 = model1->createFlow<FlowUTest>("f1");
    
    assert(model1->getName()        == "getterTest");
    assert(model1->getSystem("s1")  == s1);
    assert(model1->getFlow("f1")    == f1);
    assert(model1->getSystem("nonexistentSystem") == nullptr);
    assert(model1->getFlow("nonexistentFlow")     == nullptr);
}

void unit_Model::testModelClear() {
    Model *model1 = model1->createModel();
    model1->createSystem("", 0);
    model1->createFlow<FlowUTest>("", nullptr, nullptr);

    model1->clear();

    assert(dynamic_cast<ModelImpl*>(model1)->systems.empty());
    assert(dynamic_cast<ModelImpl*>(model1)->flows.empty());
}

void unit_Model::testModelSimulate() {
    Model *model1 = model1->createModel();
    model1->simulate(0, 10, 1);
    assert(dynamic_cast<ModelImpl*>(model1)->clock == 11);
}

void unit_Model::runModelTests() {
    testModelDefaultConstructor();
    testModelParameterizedConstructor();
    testModelSetters();
    testModelAdd();
    testModelRemoveSystem();
    testModelRemoveFlow();
    testModelGetters();
    testModelClear();
    testModelSimulate();
}
