#include "unit_Model.h"

void unit_Model::testModelDefaultConstructor() {
    Model *model1 = ModelImpl::createModel("");
    cout << "Model name: " << dynamic_cast<ModelImpl*>(model1)->name << endl;
    assert(dynamic_cast<ModelImpl*>(model1)->name == "");
}

void unit_Model::testModelParameterizedConstructor() {
    Model *model2 = ModelImpl::createModel("model2");
    assert(dynamic_cast<ModelImpl*>(model2)->name == "model2");
}

void unit_Model::testModelSetters() {
    Model *model1 = ModelImpl::createModel("");
    model1->setName("setterTest");
    assert(dynamic_cast<ModelImpl*>(model1)->name == "setterTest");
}

/*
void unit_Model::testModelAdd() {
    Model *model1 = ModelImpl::createModel();
    System* s1 = model->createSystem("s1", 100);
    FlowTest f1("f1", nullptr, nullptr);

    assert(dynamic_cast<ModelImpl*>(model1)->systems[0] == &s1);
    assert(dynamic_cast<ModelImpl*>(model1)->flows[0] == &f1);
}
*/

/*
void unit_Model::testModelRemoveSystem() {
    Model *model1 = ModelImpl::createModel("");
    System* s1 = ModelImpl::createSystem("", 0);
    
    assert(ModelImpl::remove(&s1) == true);
}

void unit_Model::testModelRemoveFlow() {
    Model *model1 = ModelImpl::createModel("");
    Flow* flow = ModelImpl::createFlow<FlowUTest>("", nullptr, nullptr);
    
    assert(ModelImpl::remove(&f1) == true);
}
*/

/*
void unit_Model::testModelAddDuplicatesSystem() {
    Model *model1 = ModelImpl::createModel();
    SystemImpl s1;
    
    assert(model1->add(&s1) == true);
    assert(model1->add(&s1) == false);
}

void unit_Model::testModelAddDuplicatesFlow() {
    Model *model1 = ModelImpl::createModel();
    FlowTest f1;
    
    assert(model1->add(&f1) == true);
    assert(model1->add(&f1) == false); 
}
*/

void unit_Model::testModelGetters() {
    Model *model1 = ModelImpl::createModel("");
    dynamic_cast<ModelImpl*>(model1)->name = "getterTest";
    System* s1 = model1->createSystem("s1", 1);
    Flow* f1 = model1->createFlow<FlowUTest>("f1");
    
    assert(model1->getName() == "getterTest");
    assert(model1->getSystem("s1") == s1);
    assert(model1->getFlow("f1") == f1);
    assert(model1->getSystem("nonexistentSystem") == nullptr);
    assert(model1->getFlow("nonexistentFlow") == nullptr);
}

void unit_Model::testModelClear() {
    Model *model1 = ModelImpl::createModel("");
    System* s1 = model1->createSystem("", 0);
    Flow* f1 = model1->createFlow<FlowUTest>("", nullptr, nullptr);

    model1->clear();

    assert(dynamic_cast<ModelImpl*>(model1)->systems.empty());
    assert(dynamic_cast<ModelImpl*>(model1)->flows.empty());
}

/*
void testSingletonInstance() {
    ModelImpl& factory1 = ModelImpl::getInstance();
    ModelImpl& factory2 = ModelImpl::getInstance();
    assert(&factory1 == &factory2);
}
*/

void unit_Model::testModelSimulate() {
    Model *model1 = ModelImpl::createModel("");
    model1->simulate(0, 10, 1);
    assert(dynamic_cast<ModelImpl*>(model1)->clock == 11);
}

void unit_Model::runModelTests() {
    testModelDefaultConstructor();
    testModelParameterizedConstructor();
    testModelSetters();
    //testModelAdd();
    //testModelRemoveSystem();
    //testModelRemoveFlow();
    //testModelAddDuplicatesSystem();
    //testModelAddDuplicatesFlow();
    testModelGetters();
    testModelClear();
    testModelSimulate();
}
