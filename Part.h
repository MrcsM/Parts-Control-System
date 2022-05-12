#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Part {
    public:
        Part(const string&);
        virtual ~Part(){};

        string getPartName() const;

        void addFlightHours(int);
        void install(const Date&);

        virtual bool inspection(const Date) const = 0;
        virtual void print(ostream& out) const = 0;
    protected:
        string name;
        Date installationDate;
        int flighthours;
};

class FH_Part: virtual public Part {
    public:
        FH_Part(const string&, int);

        bool inspection(const Date) const;
        virtual void print(ostream& out) const;
    protected:
        int fh_inspect;
};

class IT_Part: virtual public Part {
    public:
        IT_Part(const string&, int);

        bool inspection(const Date) const;
        virtual void print(ostream& out) const;
    protected:
        int it_inspect;
};

class FHIT_Part: public FH_Part, public IT_Part {
    public:
        FHIT_Part(const string&, int, int);
        
        bool inspection(const Date) const;
        virtual void print(ostream& out) const;
};

inline ostream& operator<<(ostream& out, const Part& part) {
    part.print(out);
    return out;
}

#endif