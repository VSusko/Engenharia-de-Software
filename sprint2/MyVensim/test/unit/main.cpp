#ifndef  MAIN_UNIT_TESTS
#define  MAIN_UNIT_TESTS

#include "unit_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"


int main()
{   
    systemTest();
    cout << "System test: OK" << endl;

    flowTest();
    cout << "Flow test: OK" << endl;

    modelTest();
    cout << "Model test: OK" << endl;

    return 0;
}


#endif