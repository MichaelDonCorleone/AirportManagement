#include "Airline.h"

Airline::Airline(): IDM(0), airlineNameM("\0") {
}

Airline::Airline(int ID, string airlineName, vector <Flight> & flights): IDM(ID), airlineNameM(airlineName) {
}

Airline::Airline(const Airline &source) {
	IDM = source.IDM;
	airlineNameM = source.airlineNameM;
}

const int Airline::getID() const {
	return IDM;
}

const string Airline::getAirlineName() const {
	return airlineNameM;
}

const vector <Flight> & Airline::getFlights() const {
	return flightsM;
}

void Airline::setID(int ID) {
	IDM = ID;
}

void Airline::setAirlineName(string airlineName) {
	airlineNameM = airlineName;
}

void Airline::addFlight(Flight & source) {
	flightsM.resize(flightsM.size() + 1);
	flightsM.at(flightsM.size()-1).setID(source.getID());
	flightsM.at(flightsM.size()-1).setFlightName(source.getFlightName());
	flightsM.at(flightsM.size()-1).setRows(source.getRows());
	flightsM.at(flightsM.size() -1).setSeats(source.getSeats());
	for(int i = 0; i < static_cast<int>(source.getPassengers().size()); i++) {
		flightsM.at(flightsM.size() -1).addPassenger(source.getPassengers().at(i));
	}
}

void Airline::removeFlight(int position) {
	flightsM.erase(flightsM.begin()+position);
}