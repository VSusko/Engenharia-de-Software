#include "unit_System.h"

void unit_System::testSystemDefaultConstructor() {
    SystemBody p1;
    assert(p1.getName()  == "");
    assert(p1.getValue() == 0);
}

void unit_System::testSystemGetters() {
    SystemBody p1;
    p1.setName("getterTest");
    p1.setValue(100);
    assert(p1.getName()  == "getterTest");
    assert(p1.getValue() == 100);
}

void unit_System::testSystemSetters() {
    SystemBody p1;
    p1.setName("setterTest");
    p1.setValue(10);
    assert(p1.getName()  == "setterTest");
    assert(p1.getValue() == 10);
}

void unit_System::testSystemParameterizedConstructor() {
    SystemBody p2("p2", 20);
    assert(p2.getName() == "p2");
    assert(p2.getValue() == 20);
}

void unit_System::testSystemClear() {
    SystemBody p1;
    p1.setValue(900);
    p1.clear();
    assert(p1.getValue() == 0);
}

void unit_System::testHandleBodyMechanism() {
    SystemHandle s1,s2,s3;
    
    assert(3 == numHandleCreated - numHandleDeleted);
    assert(3 == numBodyCreated - numBodyDeleted);
    
    {
        SystemHandle s4;
        assert(4 == numHandleCreated - numHandleDeleted);
        assert(4 == numBodyCreated - numBodyDeleted);
    }
    
    assert(3 == numHandleCreated - numHandleDeleted);
    assert(3 == numBodyCreated - numBodyDeleted);
    
    SystemHandle s5("tiago", 7), s6("antonio", 8);
    
    assert(5 == numHandleCreated - numHandleDeleted);
    assert(5 == numBodyCreated - numBodyDeleted);

    s5 = s6; 
    
    assert(s5.getName() == "antonio");
    
    assert(5 == numHandleCreated - numHandleDeleted);
    assert(4 == numBodyCreated - numBodyDeleted);

	s5 = s5;

	assert(5 == numHandleCreated - numHandleDeleted);
    assert(4 == numBodyCreated - numBodyDeleted);
}


void unit_System::runSystemTests() {
    #ifdef DEBUGING
        testHandleBodyMechanism();
    #endif
    testSystemDefaultConstructor();
    testSystemSetters();
    testSystemGetters();
    testSystemParameterizedConstructor();
    testSystemClear();
}
