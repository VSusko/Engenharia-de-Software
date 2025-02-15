#include "unit_System.h"

void unit_System::testSystemDefaultConstructor() {
    System *p1 = ModelFactory::createSystem();
    assert(dynamic_cast<SystemImpl*>(p1)->name  == "");
    assert(dynamic_cast<SystemImpl*>(p1)->value == 0);
}

void unit_System::testSystemGetters() {
    System *p1 = ModelFactory::createSystem();
    dynamic_cast<SystemImpl*>(p1)->name = "getterTest";
    dynamic_cast<SystemImpl*>(p1)->value = 100;
    assert(p1->getName()  == "getterTest");
    assert(p1->getValue() == 100);
}

void unit_System::testSystemSetters() {
    System *p1 = ModelFactory::createSystem();
    p1->setName("setterTest");
    p1->setValue(10);
    assert(dynamic_cast<SystemImpl*>(p1)->name  == "setterTest");
    assert(dynamic_cast<SystemImpl*>(p1)->value == 10);
}

void unit_System::testSystemParameterizedConstructor() {
    System *p2 = ModelFactory::createSystem("p2", 20);
    assert(dynamic_cast<SystemImpl*>(p2)->name == "p2");
    assert(dynamic_cast<SystemImpl*>(p2)->value == 20);
}

void unit_System::testSystemClear() {
    System *p1 = ModelFactory::createSystem();
    dynamic_cast<SystemImpl*>(p1)->value = 900;
    p1->clear();
    assert(dynamic_cast<SystemImpl*>(p1)->value == 0);
}

void unit_System::runSystemTests() {
    testSystemDefaultConstructor();
    testSystemSetters();
    testSystemGetters();
    testSystemParameterizedConstructor();
    testSystemClear();
}
