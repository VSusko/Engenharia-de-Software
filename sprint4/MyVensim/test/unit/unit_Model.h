#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "unit_tests.h"


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
