#ifndef  MAIN_FUNCIONAL_TESTS
#define  MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"

#ifdef DEBUGING
    int numHandleCreated = 0;
    int numHandleDeleted = 0;
    int numBodyCreated = 0;
    int numBodyDeleted = 0;
#endif

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