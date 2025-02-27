#include "unit_System.h"

void unit_System::testSystemDefaultConstructor() {
    Model* model = Model::createModel("model");
    System *p1 = model->createSystem("", 0);
    assert(dynamic_cast<SystemBody*>(p1)->name  == "");
    assert(dynamic_cast<SystemBody*>(p1)->value == 0);
}

void unit_System::testSystemGetters() {
    Model* model = Model::createModel("model");
    System *p1 = model->createSystem("", 0);
    dynamic_cast<SystemBody*>(p1)->name = "getterTest";
    dynamic_cast<SystemBody*>(p1)->value = 100;
    assert(p1->getName()  == "getterTest");
    assert(p1->getValue() == 100);
}

void unit_System::testSystemSetters() {
    Model* model = Model::createModel("model");
    System *p1 = model->createSystem("", 0);
    p1->setName("setterTest");
    p1->setValue(10);
    assert(dynamic_cast<SystemBody*>(p1)->name  == "setterTest");
    assert(dynamic_cast<SystemBody*>(p1)->value == 10);
}

void unit_System::testSystemParameterizedConstructor() {
    Model* model = Model::createModel("model");
    System *p2 = model->createSystem("p2", 20);
    assert(dynamic_cast<SystemBody*>(p2)->name == "p2");
    assert(dynamic_cast<SystemBody*>(p2)->value == 20);
}

void unit_System::testSystemClear() {
    Model* model = Model::createModel("model");
    System *p1 = model->createSystem("", 0);
    dynamic_cast<SystemBody*>(p1)->value = 900;
    p1->clear();
    assert(dynamic_cast<SystemBody*>(p1)->value == 0);
}

void unit_System::runSystemTests() {
    testSystemDefaultConstructor();
    testSystemSetters();
    testSystemGetters();
    testSystemParameterizedConstructor();
    testSystemClear();
}
