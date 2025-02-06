#ifndef  MAIN_UNIT_TESTS
#define  MAIN_UNIT_TESTS

#include "unit_tests.h"
#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"


int main()
{
    runSystemTests();
    cout << "System test: OK" << endl;

    runFlowTests();
    cout << "Flow test: OK" << endl;

    runModelTests();
    cout << "Model test: OK" << endl;

    return 0;
}


#endif