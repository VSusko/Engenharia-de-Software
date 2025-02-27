#include "unit_System.h"

void unit_System::testSystemDefaultConstructor() {
    Model* model = Model::createModel("model");
    System *p1 = model->createSystem("", 0);
    assert(p1->getName()  == "");
    assert(p1->getValue() == 0);
}

void unit_System::testSystemGetters() {
    Model* model = Model::createModel("model");
    System *p1 = model->createSystem("", 0);
    p1->setName("getterTest");
    p1->setValue(100);
    assert(p1->getName()  == "getterTest");
    assert(p1->getValue() == 100);
}

void unit_System::testSystemSetters() {
    Model* model = Model::createModel("model");
    System *p1 = model->createSystem("", 0);
    p1->setName("setterTest");
    p1->setValue(10);
    assert(p1->getName()  == "setterTest");
    assert(p1->getValue() == 10);
}

void unit_System::testSystemParameterizedConstructor() {
    Model* model = Model::createModel("model");
    System *p2 = model->createSystem("p2", 20);
    assert(p2->getName() == "p2");
    assert(p2->getValue() == 20);
}

void unit_System::testSystemClear() {
    Model* model = Model::createModel("model");
    System *p1 = model->createSystem("", 0);
    p1->setValue(900);
    p1->clear();
    assert(p1->getValue() == 0);
}

void unit_System::runSystemTests() {
    testSystemDefaultConstructor();
    testSystemSetters();
    testSystemGetters();
    testSystemParameterizedConstructor();
    testSystemClear();
}
