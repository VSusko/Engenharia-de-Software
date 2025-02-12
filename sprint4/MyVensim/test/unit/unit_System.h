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
         * @brief Test the copy assignment operator.
         * 
         * Creates a `SystemImpl` object, makes a copy using the assignment operator, and validates that the copy was made correctly.
         */
        void testSystemCopyOperator();
        
        /**
         * @brief Test for the copy operator on the own object
         * 
         * This test ensures that the copy operator won't fail if used on the own object
         */
        void testSystemSelfAssignment();

        /**
         * @brief Test the copy constructor.
         * 
         * Creates a `SystemImpl` object, makes a copy using the copy constructor, and validates that the values are copied correctly.
         */
        void testSystemCopyConstructor();
        
        /**
         * @brief Test the clear function.
         * 
         * Creates a `SystemImpl` object, calls the `clear()` function to reset the value, and validates that the value is correctly reset to zero.
         */
        void testSystemClear();

        /**
         * @brief Run all system tests.
         * 
         * Executes all the test functions to validate the behavior of the `SystemImpl` class.
         */
        void runSystemTests();
};


#endif // UNIT_SYSTEM_H
