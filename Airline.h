#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>

#include "Aircraft.h"

using namespace std;

class Airline {
    public:
        Airline(const string&);
        ~Airline();

        void addAircraft(const string&, const string&);
        void addPart(const string&, int, int);
        void takeFlight(const string&, int);

        void printAircraft() const;
        void printParts() const;

        void inspectionReport(const string&, Date&);

        bool install(const string&, const string&, Date&);
    private:
        Part* getPart(const string&);
        Aircraft* getAircraft(const string&);

    protected:
        string name;
        Array<Part*> parts;
        Array<Aircraft*> aircrafts;
};

#endif