#ifndef  MAIN_UNIT_TESTS
#define  MAIN_UNIT_TESTS

#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"

#ifdef DEBUGING
    int numHandleCreated = 0;
    int numHandleDeleted = 0;
    int numBodyCreated = 0;
    int numBodyDeleted = 0;
#endif

int main()
{
    unit_System unit_system;
    unit_Flow unit_flow;
    unit_Model unit_model;
    
    unit_model.runModelTests();
    cout << "Model test: OK" << endl;

    #ifdef DEBUGING
        numHandleCreated = 0;
        numHandleDeleted = 0;
        numBodyCreated = 0;
        numBodyDeleted = 0;
    #endif
    
    unit_system.runSystemTests();
    cout << "System test: OK" << endl;
    
    #ifdef DEBUGING
        numHandleCreated = 0;
        numHandleDeleted = 0;
        numBodyCreated = 0;
        numBodyDeleted = 0;
    #endif
    
    unit_flow.runFlowTests();
    cout << "Flow test: OK" << endl;

    return 0;
}


#endif