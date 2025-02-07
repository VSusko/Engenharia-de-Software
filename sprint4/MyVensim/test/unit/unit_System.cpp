#include "unit_System.h"


void unit_System::testSystemDefaultConstructor() {
    SystemImpl* p1 = new SystemImpl();
    assert(p1->name == "");
    assert(p1->value == 0);
    delete p1;
}


void unit_System::testSystemSetters() {
    SystemImpl* p1 = new SystemImpl();
    p1->setName("test");
    assert(p1->name == "test");
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


void unit_System::runSystemTests() {
    testSystemDefaultConstructor();
    testSystemSetters();
    testSystemParameterizedConstructor();
    testSystemCopyOperator();
    testSystemCopyConstructor();
    testSystemClear();
}
