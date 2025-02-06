#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

using namespace std;

class System
{
    private:
        string name;
        double value;

    public:
        //Standard constructor
        System();

        //Constructor with name and initial value
        System(const string _name, const double _value);

        //Copy constructor
        System(const System &other);

        //Destructor
        virtual ~System(){};

        //Copy operator overload
        System& operator=(const System &s);

        //Getters and setters
        void setValue(double _time);
        double getValue() const;
        void setName(const string& _name);
        string getName() const;

        //Class Functions
        void clear();

};

#endif