#ifndef  MAIN_UNIT_TESTS
#define  MAIN_UNIT_TESTS

#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"

int main()
{
    unit_System unit_system;
    unit_Flow unit_flow;
    unit_Model unit_model;
    
    unit_system.runSystemTests();
    cout << "System test: OK" << endl;

    unit_flow.runFlowTests();
    cout << "Flow test: OK" << endl;

    unit_model.runModelTests();
    cout << "Model test: OK" << endl;

    return 0;
}


#endif