#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

using namespace std;

class System
{
    public:
        //Standard constructor
        System();

        //Constructor with name and initial value
        System(const string name, const double value);

        //Copy constructor
        System(const System &other);

        //Destructor
        virtual ~System(){};

        //Copy operator overload
        System& operator=(const System &s);

        //Getters and setters
        virtual void setValue(double time) = 0;
        virtual double getValue() const = 0;
        virtual void setName(const string& name) = 0;
        virtual string getName() const = 0;

        //Class Functions
        virtual void clear() = 0;

};

#endif