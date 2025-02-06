#ifndef SYSTEM_IMPL_H
#define SYSTEM_IMPL_H

#include "system.h"

using namespace std;

class SystemImpl : public System
{
    private:
        string name;
        double value;

    public:
        //Standard constructor
        SystemImpl();

        //Constructor with name and initial value
        SystemImpl(const string name, const double value);

        //Copy constructor
        SystemImpl(const SystemImpl &other);

        //Destructor
        virtual ~SystemImpl(){};

        //Copy operator overload
        SystemImpl& operator=(const SystemImpl &s);

        //Getters and setters
        void setValue(double time);
        double getValue() const;
        void setName(const string& name);
        string getName() const;

        //Class Functions
        void clear();

};

#endif