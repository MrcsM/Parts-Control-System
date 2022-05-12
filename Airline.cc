#include "Airline.h"

Airline::Airline(const string& name): name(name) {}

Airline::~Airline() {
    for (int i = 0; i < parts.getSize(); ++i) {
        delete parts[i];
    }
    for (int i = 0; i < aircrafts.getSize(); ++i) {
        delete aircrafts[i];
    }
}

Part* Airline::getPart(const string& part) {
    for (int i = 0; i < parts.getSize(); ++i) {
        if (parts[i]->getPartName() == part) {
            return parts[i];
        }
    }
    return nullptr;
}

Aircraft* Airline::getAircraft(const string& reg) {
    for (int i = 0; i < aircrafts.getSize(); ++i) {
        if (aircrafts[i]->getRegistration() == reg) {
            return aircrafts[i];
        }
    }
    return nullptr;
}

void Airline::addAircraft(const string& type, const string& reg) {
    Aircraft* aircraftPoint = new Aircraft(type, reg);
    aircrafts.add(aircraftPoint);
}

void Airline::addPart(const string& part, int fh_inspect, int it_inspect) {
    if (fh_inspect != 0 && it_inspect != 0) {
        FHIT_Part* fhitPart = new FHIT_Part(part, fh_inspect, it_inspect);
        parts.add(fhitPart);
    } else if (fh_inspect == 0 && it_inspect != 0) {
        IT_Part* itPart = new IT_Part(part, it_inspect);
        parts.add(itPart);
    } else {
        FH_Part* fhPart = new FH_Part(part, fh_inspect);
        parts.add(fhPart);
    }
}

void Airline::takeFlight(const string& reg, int hours) {
    for (int i = 0; i < aircrafts.getSize(); ++i) {
        if (aircrafts[i]->getRegistration() == reg) {
            aircrafts[i]->takeFlight(hours);
            return;
        }
    }
    cout << "Couldn't find aircraft with registration '" << reg << "'." << endl;
}

void Airline::printAircraft() const {
    for (int i = 0; i < aircrafts.getSize(); ++i) {
        cout << *aircrafts[i] << endl;
    }
}

void Airline::printParts() const {
    for (int i = 0; i < parts.getSize(); ++i) {
        cout << *parts[i] << endl;
    }
}

void Airline::inspectionReport(const string& reg, Date& date) {
    for (int i = 0; i < aircrafts.getSize(); ++i) {
        if (aircrafts[i]->getRegistration() == reg) {
            cout << "Parts from " << reg << " that require inspection immediately:" << endl;
            Array<Part*>* needsInspect = new Array<Part*>();
            aircrafts[i]->inspectionReport(date, needsInspect);
            cout << *needsInspect;
            delete needsInspect;
        }
    }
}

bool Airline::install(const string& reg, const string& part, Date& date) {
    for (int i = 0; i < aircrafts.getSize(); ++i) {
        if (aircrafts[i]->getRegistration() == reg) {
            for (int j = 0; j < parts.getSize(); ++j) {
                if (parts[j]->getPartName() == part) {
                    aircrafts[i]->install(parts[j], date);
                    return true;
                }
            }
        }
    }
    return false;
}