#ifndef _AIRLINE_HEADER_
#define _AIRLINE_HEADER_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <cstring>
#include "Flight.cpp"

class Airline {
	private:
		int IDM;
		string airlineNameM;
		vector <Flight> flightsM;
	public:
		//constructors
		Airline();
		Airline(int ID, string airlineName, vector<Flight> & flights);
		Airline(const Airline & source);
		//getters
		const int getID() const;
		const string getAirlineName() const;
		const vector<Flight> & getFlights() const;
		//setters
		void setID(int ID);
		void setAirlineName(string airlineName);
		//helper functions
		void addFlight(Flight &source);
		void removeFlight(int position);
};
#endif