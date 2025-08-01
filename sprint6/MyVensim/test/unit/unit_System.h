#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

#include "unit_tests.h"


/**
 * @class unit_System
 * @brief Class that holds all unitary tests for the System class
 * 
 * 
 */
class unit_System
{
    public:

        /**
         * @brief Test the default constructor.
         * 
         * Creates a `SystemImpl` object using the default constructor and validates that the `name` and `value` are initialized to the expected default values.
         */
        void testSystemDefaultConstructor();

        /**
         * @brief Test the getters.
         * 
         * Creates a `SystemImpl` object, uses the getters to validates that the `name` and `value` are updated correctly.
         */
        void testSystemGetters();

        /**
         * @brief Test the setters.
         * 
         * Creates a `SystemImpl` object, uses the setters to modify the values, and validates that the `name` and `value` are updated correctly.
         */
        void testSystemSetters();

        /**
         * @brief Test the parameterized constructor.
         * 
         * Creates a `SystemImpl` object with an initial name and value and validates that these values are set correctly.
         */
        void testSystemParameterizedConstructor();
        
        /**
         * @brief Test the clear function.
         * 
         * Creates a `SystemImpl` object, calls the `clear()` function to reset the value, and validates that the value is correctly reset to zero.
         */
        void testSystemClear();

        /**
         * @brief Test for the handle/body.
         * 
         */
        void testHandleBodyMechanism();


        /**
         * @brief Run all system tests.
         * 
         * Executes all the test functions to validate the behavior of the `SystemImpl` class.
         */
        void runSystemTests();
};


#endif // UNIT_SYSTEM_H
