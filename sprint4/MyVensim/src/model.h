#ifndef MODEL_H
#define MODEL_H

#include "system.h"
#include "flow.h"
#include <vector>

using namespace std;


class Model
{        
    public:
        //Default constructor
        Model();
        
        //Copy construtor
        Model(const Model &other);

        //Name construtor
        Model(const string name);

        //Destructor
        virtual ~Model(){};

        //Copy operator overload
        Model& operator=(const Model &other);

        //Getters and Setters
        virtual void setName(string string) = 0;
        virtual Flow* getFlow(const string name) const = 0;
        virtual string getName() const = 0;
        virtual System* getSystem(const string name) const = 0;

        //Class functions
        virtual void simulate(double initial, double final, double lapse) = 0;
        virtual void clear() = 0;
        virtual void report() = 0;
        virtual bool add(System* s) = 0;
        virtual bool add(Flow* f) = 0;
        virtual bool remove(System* s) = 0;
        virtual bool remove(Flow* f) = 0;
        
        virtual bool exists(Flow* f) = 0;
        virtual bool exists(System* f) = 0;
};


#endif