#include "unit_Flow.h"

#ifdef DEBUGING
    extern int numHandleCreated;
    extern int numHandleDeleted;
    extern int numBodyCreated;
    extern int numBodyDeleted;
#endif

void unit_Flow::testFlowDefaultConstructor() {
    FlowBody flow1;

    assert(flow1.name == "");
    assert(flow1.source == nullptr);
    assert(flow1.target == nullptr);
}

void unit_Flow::testFlowParameterizedConstructor() {
    System* p1 = new SystemHandle("System1", 0);
    System* p2 = new SystemHandle("System2", 0);
    FlowBody flow2("flow2", p1, p2);
    
    assert(flow2.name == "flow2");
    assert(flow2.source == p1);
    assert(flow2.target  == p2);
    
    delete p1;
    delete p2;
}

void unit_Flow::testFlowGetters() {
    FlowBody flow;
    System* p1 = new SystemHandle("System1", 0);
    System* p2 = new SystemHandle("System2", 0);

    flow.setName("getterTest");
    flow.setSource(p1);
    flow.setTarget(p2);
    assert(flow.name == "getterTest");
    assert(flow.source == p1);
    assert(flow.target == p2);

    delete p1;
    delete p2;
}

void unit_Flow::testFlowSetters() {
    FlowBody flow;
    System* p1 = new SystemHandle("System1", 0);
    System* p2 = new SystemHandle("System2", 0);
    
    flow.setName("setterTest");
    flow.setSource(p1);
    flow.setTarget(p2);
    assert(flow.name == "setterTest");
    assert(flow.source == p1);
    assert(flow.target == p2);

    delete p1;
    delete p2;
}

void unit_Flow::testFlowClear() {
    FlowBody flow1("flow1", nullptr, nullptr);
    flow1.clear();
    assert(flow1.source == nullptr);
    assert(flow1.target == nullptr);
}

void unit_Flow::testFlowExecute() {
    FlowUTest flow;
    System* p1 = new SystemHandle("System1", 0);
    System* p2 = new SystemHandle("System2", 0);
    
    flow.setSource(p1);
    flow.setTarget(p2);
    assert(flow.execute() == 0);
    
    delete p1;
    delete p2;
}

void unit_Flow::testHandleBodyMechanism() {
    FlowUTest f1,f2,f3;
    
    assert(3 == numHandleCreated - numHandleDeleted);
    assert(3 == numBodyCreated - numBodyDeleted);
    
    {
        FlowUTest f4;
        assert(4 == numHandleCreated - numHandleDeleted);
        assert(4 == numBodyCreated - numBodyDeleted);
    }
    
    assert(3 == numHandleCreated - numHandleDeleted);
    assert(3 == numBodyCreated - numBodyDeleted);

    FlowUTest f5("tiago", nullptr, nullptr), f6("antonio", nullptr, nullptr);
    
    assert(5 == numHandleCreated - numHandleDeleted);
    assert(5 == numBodyCreated - numBodyDeleted);

    f5 = f6; 
    
    assert(f5.getName() == "antonio");
    
    assert(5 == numHandleCreated - numHandleDeleted);
    assert(4 == numBodyCreated - numBodyDeleted);

	f5 = f5;

	assert(5 == numHandleCreated - numHandleDeleted);
    assert(4 == numBodyCreated - numBodyDeleted);
}
    

void unit_Flow::runFlowTests() {
    #ifdef DEBUGING
        testHandleBodyMechanism();
    #endif
    testFlowDefaultConstructor();
    testFlowParameterizedConstructor();
    testFlowGetters();
    testFlowSetters();
    testFlowClear();
    testFlowExecute();
}
