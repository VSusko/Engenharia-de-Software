#ifndef  MAIN_FUNCIONAL_TESTS
#define  MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"

#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"

int main()
{
    exponentialFuncionalTest();
    cout << "Exponential test: OK" << endl;

    logisticalFuncionalTest();
    cout << "Logistical test: OK" << endl;

    complexFuncionalTest();
    cout << "Complex test: OK" << endl;

    return 0;

}

#endif 