#ifndef MODEL_FACTORY_H
#define MODEL_FACTORY_H

#include "model_impl.h"
#include "flow_impl.h"
#include "system_impl.h"

/**
 * @class FlowMainTest
 * @brief Derived class from FlowImpl that will be used on tests
 */
class FlowTest : public FlowImpl {
public:
    FlowTest() {}
    FlowTest(string name, System* source, System* target)
        : FlowImpl(name, source, target) {}

    virtual double execute() override { 
        return (getSource()->getValue() * 0);
    }
};

/**
 * @class ModelFactory
 * @brief Factory class to create Model instances.
 */
class ModelFactory {
private:
    ModelFactory() {}

public:

    static ModelFactory& getInstance()
    {
        static ModelFactory m;
        return m;
    }

    /**
     * @brief Creates a new Model instance.
     * @return Pointer to the newly created Model.
     */
    static Model* createModel()
    {
        return new ModelImpl();
    }

    /**
     * @brief Creates a new Model instance with a name.
     * @param name The name of the model.
     * @return Pointer to the newly created Model.
     */
    static Model* createModel(const string& name)
    {
        return new ModelImpl(name);
    }

    ModelFactory(const ModelFactory&) = delete;
    void operator=(const ModelFactory&) = delete;


    /**
     * @brief Creates a new System instance.
     * @return Pointer to the newly created System.
     */
    static System* createSystem()
    {
        return new SystemImpl();
    }

    /**
     * @brief Creates a new System instance with a name.
     * @param name The name of the System.
     * @return Pointer to the newly created System.
     */
    static System* createSystem(const string& name, const double value)
    {
        return new SystemImpl(name, value);
    }


    /**
     * @brief Creates a new Flow instance.
     * @return Pointer to the newly created Flow.
     */
    static Flow* createFlow()
    {
        return new FlowTest();
    }

    /**
     * @brief Creates a new Flow instance with a name.
     * @param name The name of the Flow.
     * @return Pointer to the newly created Flow.
     */
    static Flow* createFlow(const string& name, System* source, System* target)
    {
        return new FlowTest(name, source, target);
    }
};

#endif
