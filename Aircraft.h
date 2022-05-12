#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Array.h"
#include "Part.h"

#include <iostream>
#include <string>

using namespace std;

class Aircraft {
    friend ostream& operator<<(ostream&, const Aircraft&);
    public:
        Aircraft(const string&, const string&);

        string getRegistration() const;

        void install(Part*, Date&);
        void takeFlight(int);
        void inspectionReport(Date, Array<Part*>*);
    protected:
        string type;
        string registration;
        int flighthours;
        Array<Part*> parts;
};

#endif