#include "unit_System.h"


void unit_System::testSystemDefaultConstructor() {
    SystemImpl* p1 = new SystemImpl();
    assert(p1->name == "");
    assert(p1->value == 0);
    delete p1;
}


void unit_System::testSystemGetters() {
    SystemImpl* p1 = new SystemImpl("getterTest", 100);
    assert(p1->getName() == "getterTest");
    assert(p1->getValue() == 100);
    delete p1;
}


void unit_System::testSystemSetters() {
    SystemImpl* p1 = new SystemImpl();
    p1->setName("setterTest");
    assert(p1->name == "setterTest");
    p1->setValue(10);
    assert(p1->value == 10);
    delete p1;
}


void unit_System::testSystemParameterizedConstructor() {
    SystemImpl* p2 = new SystemImpl("p2", 20);
    assert(p2->name == "p2");
    assert(p2->value == 20);
    delete p2;
}


void unit_System::testSystemCopyOperator() {
    SystemImpl* p1 = new SystemImpl("copyOperator", 35);
    SystemImpl* p2 = new SystemImpl();
    *p2 = *p1;
    assert(p2->name == "copyOperator");
    assert(p2->value == 35);
    delete p1;
    delete p2;
}

void unit_System::testSystemSelfAssignment() {
    SystemImpl* p1 = new SystemImpl("selfAssign", 50);
    *p1 = *p1;
    assert(p1->name == "selfAssign");
    assert(p1->value == 50);
    delete p1;
}

void unit_System::testSystemCopyConstructor() {
    SystemImpl* p1 = new SystemImpl("copyConstructor", 80);
    SystemImpl* p3 = new SystemImpl(*p1);
    assert(p3->name == "copyConstructor");
    assert(p3->value == 80);
    delete p1;
    delete p3;
}


void unit_System::testSystemClear() {
    SystemImpl* p1 = new SystemImpl("clearTest", 900);
    p1->clear();
    assert(p1->value == 0);
    delete p1;
}

void unit_System::testSystemEdgeCases() {
    SystemImpl* p1 = new SystemImpl("", -999);
    assert(p1->name == "");
    assert(p1->value == -999);

    p1->setValue(1e9);
    assert(p1->value == 1e9);

    delete p1;
}


void unit_System::runSystemTests() {
    testSystemDefaultConstructor();
    testSystemSetters();
    testSystemGetters();
    testSystemParameterizedConstructor();
    testSystemCopyOperator();
    testSystemSelfAssignment();
    testSystemCopyConstructor();
    testSystemClear();
    testSystemEdgeCases();
}
