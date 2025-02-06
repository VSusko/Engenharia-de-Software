#include "unit_System.h"

//Default constructor test
void testSystemDefaultConstructor() {
    SystemImpl* p1 = new SystemImpl();
    assert(p1->getName() == "");
    assert(p1->getValue() == 0);
    delete p1;
}

//Setters test
void testSystemSetters() {
    SystemImpl* p1 = new SystemImpl();
    p1->setName("test");
    assert(p1->getName() == "test");
    p1->setValue(10);
    assert(p1->getValue() == 10);
    delete p1;
}

//Name and value constructor test
void testSystemParameterizedConstructor() {
    SystemImpl* p2 = new SystemImpl("p2", 20);
    assert(p2->getName() == "p2");
    assert(p2->getValue() == 20);
    delete p2;
}

// Copy operator test
void testSystemCopyOperator() {
    SystemImpl* p1 = new SystemImpl("test", 10);
    SystemImpl* p2 = new SystemImpl("p2", 20);
    *p2 = *p1;
    assert(p2->getName() == "test");
    assert(p2->getValue() == 10);
    delete p1;
    delete p2;
}

// Copy constructor test
void testSystemCopyConstructor() {
    SystemImpl* p1 = new SystemImpl("test", 10);
    SystemImpl* p3 = new SystemImpl(*p1);
    assert(p3->getName() == "test");
    assert(p3->getValue() == 10);
    delete p1;
    delete p3;
}

// Clear test
void testSystemClear() {
    SystemImpl* p1 = new SystemImpl("test", 10);
    p1->clear();
    assert(p1->getValue() == 0);
    delete p1;
}

// Running all tests
void runSystemTests() {
    testSystemDefaultConstructor();
    testSystemSetters();
    testSystemParameterizedConstructor();
    testSystemCopyOperator();
    testSystemCopyConstructor();
    testSystemClear();
}
