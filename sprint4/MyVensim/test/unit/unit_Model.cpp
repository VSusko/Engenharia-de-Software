#include "unit_Model.h"


void unit_Model::testModelDefaultConstructor() {
    ModelImpl* model1 = new ModelImpl();
    assert(model1->name == "");
    delete model1;
}


void unit_Model::testModelParameterizedConstructor() {
    ModelImpl* model2 = new ModelImpl("model2");
    assert(model2->name == "model2");
    delete model2;
}


void unit_Model::testModelSetters() {
    ModelImpl* model1 = new ModelImpl();
    model1->setName("setterTest");
    assert(model1->name == "setterTest");
    delete model1;
}


void unit_Model::testModelAdd() {
    ModelImpl* model1 = new ModelImpl();
    SystemImpl* p1 = new SystemImpl("p1", 100);
    model1->add(p1);
    assert(model1->systems[0] == p1);
    delete model1;
    delete p1;
}


void unit_Model::testModelCopyConstructor() {
    ModelImpl* model1 = new ModelImpl("original");
    SystemImpl* s1 = new SystemImpl("s1", 50);
    Expression* f1 = new Expression("f1", s1, nullptr);
    
    model1->add(s1);
    model1->add(f1);
    
    ModelImpl* model2 = new ModelImpl(*model1);
    
    assert(model2->name == "original");
    assert(model2->systems[0] != nullptr);
    assert(model2->flows[0] != nullptr);
    
    delete model1;
    delete model2;
    delete s1;
    delete f1;
}


void unit_Model::testModelAssignmentOperator() {
    ModelImpl* model1 = new ModelImpl("model1");
    SystemImpl* s1 = new SystemImpl("s1", 100);
    model1->add(s1);

    *model1 = *model1;
    assert(model1->name == "model1");
    assert(model1->systems[0] == s1);

    delete model1;
    delete s1;
}


void unit_Model::testModelRemoveSystem() {
    ModelImpl* model = new ModelImpl();
    SystemImpl* s1 = new SystemImpl("s1", 50);
    model->add(s1);
    
    assert(model->remove(s1) == true);
    assert(model->getSystem("s1") == nullptr);
    
    delete model;
    delete s1;
}


void unit_Model::testModelRemoveFlow() {
    ModelImpl* model = new ModelImpl();
    SystemImpl* s1 = new SystemImpl("s1", 50);
    Expression* f1 = new Expression("f1", s1, nullptr);
    model->add(f1);
    
    assert(model->remove(f1) == true);
    assert(model->getFlow("f1") == nullptr);
    
    delete model;
    delete s1;
    delete f1;
}


void unit_Model::testModelAddDuplicatesSystem() {
    ModelImpl* model = new ModelImpl();
    SystemImpl* s1 = new SystemImpl("s1", 100);
    
    assert(model->add(s1) == true);
    assert(model->add(s1) == false);
    
    delete model;
    delete s1;
}


void unit_Model::testModelAddDuplicatesFlow() {
    ModelImpl* model = new ModelImpl();
    SystemImpl* s1 = new SystemImpl("s1", 100);
    Expression* f1 = new Expression("f1", nullptr, nullptr);
    
    assert(model->add(f1) == true);
    assert(model->add(f1) == false); 
    
    delete model;
    delete s1;
}


void unit_Model::testModelGetters() {
    ModelImpl* model = new ModelImpl("getterTest");
    SystemImpl* s1 = new SystemImpl("s1", 100);
    Expression* f1 = new Expression("f1", s1, nullptr);
    
    model->add(s1);
    model->add(f1);
    
    assert(model->getName() == "getterTest");
    assert(model->getSystem("s1") == s1);
    assert(model->getFlow("f1") == f1);
    assert(model->getSystem("nonexistentSystem") == nullptr);
    assert(model->getFlow("nonexistentFlow") == nullptr);

    delete model;
    delete s1;
    delete f1;
}


void unit_Model::testModelExists() {
    ModelImpl* model = new ModelImpl();
    SystemImpl* s1 = new SystemImpl("s1", 50);
    Expression* f1 = new Expression("f1", s1, nullptr);

    model->add(s1);
    model->add(f1);

    assert(model->exists(s1) == true);
    assert(model->exists(f1) == true);

    SystemImpl* s2 = new SystemImpl("s2", 10);
    assert(model->exists(s2) == false);

    delete model;
    delete s1;
    delete f1;
    delete s2;
}


void unit_Model::testModelClear() {
    ModelImpl* model = new ModelImpl();
    SystemImpl* s1 = new SystemImpl("s1", 100);
    Expression* f1 = new Expression("f1", s1, nullptr);

    model->add(s1);
    model->add(f1);

    model->clear();
    assert(model->getSystem("s1") == nullptr);
    assert(model->getFlow("f1") == nullptr);

    delete model;
    delete s1;
    delete f1;
}


void unit_Model::testModelSimulate() {
    ModelImpl* model1 = new ModelImpl();
    SystemImpl* p1 = new SystemImpl("p1", 100);
    SystemImpl* p2 = new SystemImpl("p2", 5);
    Expression* flow1 = new Expression("flow1", p1, p2);
    model1->add(p1);
    model1->add(p2);
    model1->add(flow1);
    model1->simulate(0, 9, 1);
    assert(fabs(p1->getValue() - 90.4382) < 0.0001);
    assert(fabs(p2->getValue() - 14.5618) < 0.0001);
    delete model1;
    delete p1;
    delete p2;
    delete flow1;
}


void unit_Model::runModelTests() {
    testModelDefaultConstructor();
    testModelParameterizedConstructor();
    testModelSetters();
    testModelAdd();
    
    testModelCopyConstructor();
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
