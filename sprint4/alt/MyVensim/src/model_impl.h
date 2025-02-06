#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include "model.h"

class ModelImpl : public Model
{
    private:
        string name;
        vector<System*> systems;
        vector<Flow*> flows;
        
    public:
        //Default constructor
        ModelImpl();

        //Name construtor
        ModelImpl(const string name);

        //Destructor
        virtual ~ModelImpl(){};

        //Getters and Setters
        void setName(string string);
        string getName() const;
        System* getSystem(const string name) const;
        Flow* getFlow(const string name) const;

        //Class functions
        void simulate(double initial, double final, double lapse) ;
        void clear() ;
        void report() ;
        bool add(System* s) ;
        bool add(Flow* f) ;
        bool remove(System* s) ;
        bool remove(Flow* f) ;
        
        bool exists(Flow* f) ;
        bool exists(System* f) ;
};


#endif