#ifndef SYSTEM_FACTORY_H
#define SYSTEM_FACTORY_H

#include "system_impl.h"

/**
 * @class SystemFactory
 * @brief Factory class to create System instances.
 */
class SystemFactory {
public:
    /**
     * @brief Creates a new System instance.
     * @return Pointer to the newly created System.
     */
    static System* createSystem() {
        return new SystemImpl();
    }

    /**
     * @brief Creates a new System instance with a name.
     * @param name The name of the System.
     * @return Pointer to the newly created System.
     */
    static System* createSystem(const string& name, const double value) {
        return new SystemImpl(name, value);
    }
};

#endif
