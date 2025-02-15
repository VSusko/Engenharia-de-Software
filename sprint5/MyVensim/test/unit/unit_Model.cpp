#include "unit_Model.h"

void unit_Model::testModelDefaultConstructor() {
    Model *model1 = ModelFactory::createModel();
    assert(dynamic_cast<ModelImpl*>(model1)->name == "");
}

void unit_Model::testModelParameterizedConstructor() {
    Model *model2 = ModelFactory::createModel("model2");
    assert(dynamic_cast<ModelImpl*>(model2)->name == "model2");
}

void unit_Model::testModelSetters() {
    Model *model1 = ModelFactory::createModel();
    model1->setName("setterTest");
    assert(dynamic_cast<ModelImpl*>(model1)->name == "setterTest");
}

void unit_Model::testModelAdd() {
    Model *model1 = ModelFactory::createModel();
    SystemImpl s1("s1", 10);
    FlowTest f1("f1", nullptr, nullptr);

    model1->add(&s1);
    model1->add(&f1);
    assert(dynamic_cast<ModelImpl*>(model1)->systems[0] == &s1);
    assert(dynamic_cast<ModelImpl*>(model1)->flows[0] == &f1);
}

void unit_Model::testModelRemoveSystem() {
    Model *model1 = ModelFactory::createModel();
    SystemImpl s1;
    dynamic_cast<ModelImpl*>(model1)->systems.push_back(&s1);
    
    assert(model1->remove(&s1) == true);
    assert(dynamic_cast<ModelImpl*>(model1)->systems.empty());
}

void unit_Model::testModelRemoveFlow() {
    Model *model1 = ModelFactory::createModel();
    FlowTest f1;
    dynamic_cast<ModelImpl*>(model1)->flows.push_back(&f1);
    
    assert(model1->remove(&f1) == true);
    assert(dynamic_cast<ModelImpl*>(model1)->flows.empty());
}

void unit_Model::testModelAddDuplicatesSystem() {
    Model *model1 = ModelFactory::createModel();
    SystemImpl s1;
    
    assert(model1->add(&s1) == true);
    assert(model1->add(&s1) == false);
}

void unit_Model::testModelAddDuplicatesFlow() {
    Model *model1 = ModelFactory::createModel();
    FlowTest f1;
    
    assert(model1->add(&f1) == true);
    assert(model1->add(&f1) == false); 
}

void unit_Model::testModelGetters() {
    Model *model1 = ModelFactory::createModel();
    dynamic_cast<ModelImpl*>(model1)->name = "getterTest";
    SystemImpl s1("s1", 1);
    FlowTest f1("f1", nullptr, nullptr);

    dynamic_cast<ModelImpl*>(model1)->systems.push_back(&s1);
    dynamic_cast<ModelImpl*>(model1)->flows.push_back(&f1);
    
    assert(model1->getName() == "getterTest");
    assert(model1->getSystem("s1") == &s1);
    assert(model1->getFlow("f1") == &f1);
    assert(model1->getSystem("nonexistentSystem") == nullptr);
    assert(model1->getFlow("nonexistentFlow") == nullptr);
}

void unit_Model::testModelExists() {
    Model *model1 = ModelFactory::createModel();
    SystemImpl s1("s1", 10);
    FlowTest f1("f1", nullptr, nullptr);

    dynamic_cast<ModelImpl*>(model1)->systems.push_back(&s1);
    dynamic_cast<ModelImpl*>(model1)->flows.push_back(&f1);

    assert(model1->exists(&s1) == true);
    assert(model1->exists(&f1) == true);

    SystemImpl s2("s2", 20);
    assert(model1->exists(&s2) == false);
}

void unit_Model::testModelClear() {
    Model *model1 = ModelFactory::createModel();
    SystemImpl s1;
    FlowTest f1;

    dynamic_cast<ModelImpl*>(model1)->systems.push_back(&s1);
    dynamic_cast<ModelImpl*>(model1)->flows.push_back(&f1);

    model1->clear();

    assert(dynamic_cast<ModelImpl*>(model1)->systems.empty());
    assert(dynamic_cast<ModelImpl*>(model1)->flows.empty());
}

void testSingletonInstance() {
    ModelFactory& factory1 = ModelFactory::getInstance();
    ModelFactory& factory2 = ModelFactory::getInstance();
    assert(&factory1 == &factory2);
}


void unit_Model::testModelSimulate() {
    Model *model1 = ModelFactory::createModel();
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
    testModelAddDuplicatesSystem();
    testModelAddDuplicatesFlow();
    testModelGetters();
    testModelExists();
    testModelClear();
    testModelSimulate();
}
