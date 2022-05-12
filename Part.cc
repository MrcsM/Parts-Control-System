#include "Part.h"

// Part

Part::Part(const string& name): name(name), flighthours(0) {}

string Part::getPartName() const {
    return name;
}

void Part::addFlightHours(int hours) {
    flighthours += hours;
}

void Part::install(const Date& date) {
    installationDate = date;
}

// FH_Part

FH_Part::FH_Part(const string& name, int hours): Part(name), fh_inspect(hours) {}

bool FH_Part::inspection(const Date date) const {
    return flighthours >= fh_inspect;
}

void FH_Part::print(ostream& out) const {
    out << "Part: " << name << "\nFlight Hours: " << flighthours << "\nInstallation Date: ";
    if (installationDate.toDays() == 1) {
        out << "Not installed\n";
    } else {
        out << installationDate;
    }
    out << "Inspect every: " << fh_inspect << " flight hours\n";
}

// IT_Part

IT_Part::IT_Part(const string& name, int hours): Part(name), it_inspect(hours) {}

bool IT_Part::inspection(const Date date) const {
    return (date.toDays() - installationDate.toDays()) >= it_inspect;
}

void IT_Part::print(ostream& out) const {
    out << "Part: " << name << "\nFlight Hours: " << flighthours << "\nInstallation Date: ";
    if (installationDate.toDays() == 1) {
        out << "Not installed\n";
    } else {
        out << installationDate;
    }
    out << "Inspect every: " << it_inspect << " days installed\n";
}

// FHIT_Part

FHIT_Part::FHIT_Part(const string& name, int fh, int it): FH_Part(name, fh), IT_Part(name, it), Part(name) {}

bool FHIT_Part::inspection(const Date date) const {
    return (FH_Part::inspection(date) || IT_Part::inspection(date));
}

void FHIT_Part::print(ostream& out) const {
    out << "Part: " << name << "\nFlight Hours: " << flighthours << "\nInstallation Date: ";
    if (installationDate.toDays() == 1) {
        out << "Not installed\n";
    } else {
        out << installationDate;
    }
    out << "Inspect every: " << fh_inspect << " flight hours\n";
    out << "Inspect every: " << it_inspect << " days installed\n";
}