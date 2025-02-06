#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "system.h"
#include "flow.h"

using namespace std;


class Model
{
    private:
        string name;
        vector<System*> systems;
        vector<Flow*> flows;
        
    public:
        //Default constructor
        Model();
        
        //Copy construtor
        Model(const Model &other);

        //Name construtor
        Model(const string _name);

        //Destructor
        virtual ~Model(){};

        //Copy operator overload
        Model operator=(const Model &other);

        //Getters and Setters
        void setName(string _string);
        string getName() const;
        System* getSystem(const string _name);
        Flow* getFlow(const string _name);

        //Class functions
        void simulate(double initial, double final, double lapse);
        void clear();
        void report();
        bool add(System* s);
        bool add(Flow* f);
        bool remove(System* s);
        bool remove(Flow* f);
    
    private:
        bool exists(Flow* f);
        bool exists(System* f);
};


#endif