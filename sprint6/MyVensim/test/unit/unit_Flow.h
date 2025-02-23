#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

#include "unit_tests.h"


/**
 * @class unit_Flow
 * @brief Class that holds all unitary tests for the Flow class
 * 
 * 
 */
class unit_Flow
{
    public:

        /**
         * @brief Test for the default constructor of the Flow class.
         * 
         * This test verifies the behavior of the Flow class when the default constructor is called, 
         * ensuring the object is properly initialized with default values.
         */
        void testFlowDefaultConstructor();

        /**
         * @brief Test for the parameterized constructor of the Flow class.
         * 
         * This test checks the functionality of the constructor that initializes the object with 
         * a specific name and two systems, ensuring correct object setup.
         */
        void testFlowParameterizedConstructor();
        
        /**
         * @brief Test for the setters of the Flow class.
         * 
         * This test evaluates the behavior of the getter functions in the Flow class to ensure 
         * that they correctly get values for the attributes.
         */
        void testFlowGetters();

        /**
         * @brief Test for the setters of the Flow class.
         * 
         * This test evaluates the behavior of the setter functions in the Flow class to ensure 
         * that they correctly set values for the attributes.
         */
        void testFlowSetters();
        
        /**
         * @brief Test for the copy constructor of the Flow class.
         * 
         * This test checks the proper functioning of the Flow class's copy constructor, ensuring 
         * that an object can be correctly copied and all values are transferred properly.
         */
        void testFlowCopyConstructor();
        
        /**
         * @brief Test for the copy assignment operator of the Flow class.
         * 
         * This test verifies that the Flow class's copy assignment operator functions correctly, 
         * ensuring that the values of one object are properly assigned to another.
         */
        void testFlowCopyOperator();

        /**
         * @brief Test for the copy operator on the own object
         * 
         * This test ensures that the copy operator won't fail if used on the own object
         */
        void testFlowSelfAssignment();

        /**
         * @brief Test for the clear functionality of the Flow class.
         * 
         * This test ensures that the `clear()` function works as expected, clearing all data and 
         * resetting the object to its initial state.
         */
        void testFlowClear();
        
        /**
         * @brief Test for execute method
         * 
         * This test is going to calculate an expression made by user and approve whether it works or not
         */
        void testFlowExecute();

        /**
         * @brief Runs all tests for the Flow class.
         * 
         * This method triggers all the individual tests for the Flow class, providing a complete 
         * test suite to ensure that all functionalities work as intended.
         */
        void runFlowTests();
};



#endif // UNIT_FLOW_H
