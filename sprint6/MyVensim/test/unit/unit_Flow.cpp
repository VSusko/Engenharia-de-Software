#include "unit_Flow.h"

#ifdef DEBUGING
    extern int numHandleCreated;
    extern int numHandleDeleted;
    extern int numBodyCreated;
    extern int numBodyDeleted;
#endif

void unit_Flow::testFlowDefaultConstructor() {
    Model* model = Model::createModel("model");
    Flow* flow1  = model->createFlow<FlowUTest>("", nullptr, nullptr);

    assert(flow1->getName() == "");
    assert(flow1->getSource() == nullptr);
    assert(flow1->getTarget() == nullptr);
}

void unit_Flow::testFlowParameterizedConstructor() {
    Model* model = Model::createModel("model");
    System *p1 = model->createSystem("", 0);
    System *p2 = model->createSystem("", 0);
    Flow *flow2 = model->createFlow<FlowUTest>("flow2", p1, p2);
    assert(flow2->getName() == "flow2");
    assert(flow2->getSource() == p1);
    assert(flow2->getTarget()  == p2);
}

void unit_Flow::testFlowGetters() {
    Model* model = Model::createModel("model");
    Flow *flow = model->createFlow<FlowUTest>("", nullptr, nullptr);
    System *p1 = model->createSystem("", 0);
    System *p2 = model->createSystem("", 0);
    flow->setName("getterTest");
    flow->setSource(p1);
    flow->setTarget(p2);
    assert(flow->getName() == "getterTest");
    assert(flow->getSource() == p1);
    assert(flow->getTarget() == p2);
}

void unit_Flow::testFlowSetters() {
    Model* model = Model::createModel("model");
    Flow *flow1 = model->createFlow<FlowUTest>("", nullptr, nullptr);
    System *p1 = model->createSystem("", 0);
    System *p2 = model->createSystem("", 0);
    flow1->setName("setterTest");
    flow1->setSource(p1);
    flow1->setTarget(p2);
    assert(flow1->getName() == "setterTest");
    assert(flow1->getSource() == p1);
    assert(flow1->getTarget() == p2);
}

void unit_Flow::testFlowClear() {
    Model* model = Model::createModel("model");
    Flow *flow1 = model->createFlow<FlowUTest>("flow1", nullptr, nullptr);
    flow1->clear();
    assert(flow1->getSource() == nullptr);
    assert(flow1->getTarget() == nullptr);
}

void unit_Flow::testFlowExecute() {
    Model* model = Model::createModel("model");
    Flow *flow = model->createFlow<FlowUTest>("", nullptr, nullptr);
    System *p1 = model->createSystem("", 10);
    System *p2 = model->createSystem("", 0);
    flow->setSource(p1);
    flow->setTarget(p2);
    assert(flow->execute() == 0);
}

void unit_Flow::testHandleBodyMechanism() {
    #ifdef DEBUGING
        int initialHandles = numHandleCreated - numHandleDeleted;
        int initialBodies = numBodyCreated - numBodyDeleted;
    
        cout << "Antes da criação: Handles: " << initialHandles 
                  << ", Bodies: " << initialBodies << endl;
    #endif
    
        Model* model = Model::createModel("model");
        Flow* flow1 = model->createFlow<FlowUTest>("flow1", nullptr, nullptr);
    
    #ifdef DEBUGING
        cout << "Após criação: Handles: " << (numHandleCreated - numHandleDeleted) 
                  << ", Bodies: " << (numBodyCreated - numBodyDeleted) << endl;
    #endif
    
        delete flow1;
    
    #ifdef DEBUGING
        cout << "Após deleção: Handles: " << (numHandleCreated - numHandleDeleted) 
                  << ", Bodies: " << (numBodyCreated - numBodyDeleted) << endl;
    #endif
    }
    

void unit_Flow::runFlowTests() {
    testFlowDefaultConstructor();
    //testFlowParameterizedConstructor();
    //testFlowGetters();
    //testFlowSetters();
    //testFlowClear();
    //testFlowExecute();
    testHandleBodyMechanism();
}
