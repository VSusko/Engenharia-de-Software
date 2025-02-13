#ifndef MODEL_FACTORY_H
#define MODEL_FACTORY_H

#include "model_impl.h"

/**
 * @class ModelFactory
 * @brief Factory class to create Model instances.
 */
class ModelFactory {
public:
    /**
     * @brief Creates a new Model instance.
     * @return Pointer to the newly created Model.
     */
    static Model* createModel() {
        return new ModelImpl();
    }

    /**
     * @brief Creates a new Model instance with a name.
     * @param name The name of the model.
     * @return Pointer to the newly created Model.
     */
    static Model* createModel(const string& name) {
        return new ModelImpl(name);
    }
};

#endif
