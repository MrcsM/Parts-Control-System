#include "Aircraft.h"

Aircraft::Aircraft(const string& type, const string& reg): type(type), registration(reg), flighthours(0) {}

string Aircraft::getRegistration() const {
    return registration;
}

void Aircraft::install(Part* part, Date& date) {
    part->install(date);
    parts.add(part);
}

void Aircraft::takeFlight(int hours) {
    flighthours += hours;
    for (int i = 0; i < parts.getSize(); ++i) {
        parts[i]->addFlightHours(hours);
    }
}

void Aircraft::inspectionReport(Date date, Array<Part*>* needInspect) {
    for (int i = 0; i < parts.getSize(); ++i) {
        if (parts[i]->inspection(date)) {
            needInspect->add(parts[i]);
        }
    }
}

ostream& operator<<(ostream& out, const Aircraft& aircraft) {
    return out << "Aircraft: " << aircraft.type << " | Registration: " << aircraft.registration << " | Flight Hours: " << aircraft.flighthours;
}