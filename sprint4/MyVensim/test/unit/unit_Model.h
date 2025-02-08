#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "unit_tests.h"
#include <sstream>

/**
 * @class unit_Model
 * @brief Class that holds all unitary tests for the Model class
 * 
 * 
 */
class unit_Model
{
    public:

        /**
         * @brief Test for the default constructor of the Model class.
         * 
         * This test verifies the behavior of the Model class when the default constructor is called, 
         * ensuring the object is correctly initialized with default values.
         */
        void testModelDefaultConstructor();
    
        /**
         * @brief Test for the parameterized constructor of the Model class.
         * 
         * This test checks the functionality of the constructor that initializes the object with 
         * a specific name, ensuring the object is correctly set up with the provided parameters.
         */
        void testModelParameterizedConstructor();
    
        /**
         * @brief Test for the setters of the Model class.
         * 
         * This test evaluates the behavior of the setter functions in the Model class to ensure 
         * that they correctly set values for the model's attributes.
         */
        void testModelSetters();
    
        /**
         * @brief Test for the add functionality of the Model class.
         * 
         * This test verifies the correct behavior of the add method, ensuring that objects can be 
         * added properly within the Model class.
         */
        void testModelAdd();

        /**
         * @brief Test for the copy constructor of the Model class.
         * 
         * This test checks the proper functioning of the Model class's copy constructor, ensuring 
         * that an object can be correctly copied and all values are transferred properly.
         */
        void testModelCopyConstructor();

        /**
         * @brief Test for the copy assignment operator of the Model class.
         * 
         * This test verifies that the Model class's copy assignment operator functions correctly, 
         * ensuring that the values of one object are properly assigned to another.
         */
        void testModelCopyOperator();

        /**
         * @brief Test for the copy operator on the own object
         * 
         * This test ensures that the copy operator won't fail if used on the own object
         */
        void testModelAssignmentOperator();

        /**
         * @brief Tests the remove method of the Model class for systems.
         * 
         * This test verifies the correct behavior of the remove method, ensuring that systems can be 
         * removed properly of the Model class.
         */
        void testModelRemoveSystem();

        /**
         * @brief Tests the remove method of the Model class for flows.
         * 
         * This test verifies the correct behavior of the remove method, ensuring that flows can be 
         * removed properly of the Model class.
         */
        void testModelRemoveFlow();

        /**
         * @brief Tests if a system added twice is being actually added two times.
         * 
         * This test verifies the correct behavior of adding a system in model container
         */
        void testModelAddDuplicatesSystem();

        /**
         * @brief Tests if a flow added twice is being actually added two times.
         * 
         * This test verifies the correct behavior of adding a flow in model container
         */
        void testModelAddDuplicatesFlow();

        /**
         * @brief Test for the getters of the Model class.
         * 
         * This test evaluates the behavior of the getter functions in the Model class to ensure 
         * that they correctly get values for the attributes.
         */
        void testModelGetters();

        /**
         * @brief Test for the report functionality of the Model class.
         * 
         * Since the report method just prints all systems informations, this function redirects
         * the output flow to a buffer that is going to be compared with the expected output 
         */
        void testModelReport();

        /**
         * @brief Test for the exists method of the Model class.
         * 
         * This test checks if the method exists is actually looking for an object in the model and returning
         * "true" if the object is present and "false" otherwise
         */
        void testModelExists();

        /**
         * @brief Test for the clear functionality of the Model class.
         * 
         * This test ensures that the `clear()` function works as expected, clearing all systems and 
         * flows pointers.
         */
        void testModelClear();

        /**
         * @brief Test for the simulate functionality of the Model class.
         * 
         * This test checks if the simulate method performs as expected, testing how the model behaves 
         * during simulation.
         */
        void testModelSimulate();
    
        /**
         * @brief Runs all tests for the Model class.
         * 
         * This method triggers all the individual tests for the Model class, providing a complete 
         * test suite to ensure that all functionalities are working as expected.
         */
        void runModelTests();
};


#endif // UNIT_MODEL_H
