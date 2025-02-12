#include "unit_System.h"


void unit_System::testSystemDefaultConstructor() {
    SystemImpl p1;
    assert(p1.name  == "");
    assert(p1.value == 0);
}


void unit_System::testSystemGetters() {
    SystemImpl p1;
    p1.name = "getterTest";
    p1.value = 100;
    assert(p1.getName()  == "getterTest");
    assert(p1.getValue() == 100);
}


void unit_System::testSystemSetters() {
    SystemImpl p1;
    p1.setName("setterTest");
    p1.setValue(10);
    assert(p1.name  == "setterTest");
    assert(p1.value == 10);
}


void unit_System::testSystemParameterizedConstructor() {
    SystemImpl p2("p2", 20);
    assert(p2.name == "p2");
    assert(p2.value == 20);
}


void unit_System::testSystemCopyOperator() {
    SystemImpl p1;
    p1.name = "copyOperator";
    p1.value = 35;
    SystemImpl p2;
    p2 = p1;
    assert(p2.name == "copyOperator");
    assert(p2.value == 35);
}

void unit_System::testSystemSelfAssignment() {
    SystemImpl p1;
    p1.name  = "selfAssign";
    p1.value = 50;
    p1 = p1;
    assert(p1.name == "selfAssign");
    assert(p1.value == 50);
}

void unit_System::testSystemCopyConstructor() {
    SystemImpl p1("copyConstructor", 80);
    SystemImpl p2(p1);
    assert(p2.name == "copyConstructor");
    assert(p2.value == 80);
}


void unit_System::testSystemClear() {
    SystemImpl p1;
    p1.value = 900;
    p1.clear();
    assert(p1.value == 0);
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
}
