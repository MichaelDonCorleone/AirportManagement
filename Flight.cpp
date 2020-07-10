/*******************************
	Assignment   : Final Project
	File Name    : Flight.cpp
	Created By   : Apostolos Scondrianis
	Submitted On : Monday 15th, June 2020
*******************************/
#include "Flight.h"

Flight::Flight(): IDM(0), airlineIDM(0), flightNameM("\0"), rowsM(0), seatsM(0) {
}

Flight::Flight(int ID, int airlineID, string flightName, int rows, int seats, vector<Passenger> passengers): IDM(ID), airlineIDM(airlineID),flightNameM(flightName), rowsM(rows), seatsM(seats) {
	passengersM.resize(passengers.size());
	for(int i = 0; i < static_cast<int>(passengers.size()); i++) {
		passengersM.at(i).setID(passengers.at(i).getID());
		passengersM.at(i).setFirstName(passengers.at(i).getFirstName());
		passengersM.at(i).setLastName(passengers.at(i).getLastName());
		passengersM.at(i).setPhoneNumber(passengers.at(i).getPhoneNumber());
		passengersM.at(i).setSeat(passengers.at(i).getSeat().getRow(), passengers.at(i).getSeat().getSeat());
	}
}

Flight::Flight(const Flight &source) {
	IDM = source.IDM;
	airlineIDM = source.airlineIDM;
	flightNameM = source.flightNameM;
	rowsM = source.rowsM;
	seatsM = source.seatsM;
	passengersM.resize(source.getPassengers().size());
	for(int i = 0; i < static_cast<int>(passengersM.size()); i++) {
		passengersM.at(i).setID(source.passengersM.at(i).getID());
		passengersM.at(i).setFirstName(source.passengersM.at(i).getFirstName());
		passengersM.at(i).setLastName(source.passengersM.at(i).getLastName());
		passengersM.at(i).setPhoneNumber(source.passengersM.at(i).getPhoneNumber());
		passengersM.at(i).setSeat(source.passengersM.at(i).getSeat().getRow(), source.passengersM.at(i).getSeat().getSeat());
	}
}

const int Flight::getID() const {
	return IDM;
}

const int Flight::getAirlineID() const {
	return airlineIDM;
}

const string Flight::getFlightName() const {
	return flightNameM;
}

const int Flight::getRows() const {
	return rowsM;
}

const int Flight::getSeats() const {
	return seatsM;
}

const vector<Passenger> Flight::getPassengers() const {
	return passengersM;
}

void Flight::setID(int ID) {
	IDM = ID;
}

void Flight::setAirlineID(int airlineID) {
	airlineIDM = airlineID;
}

void Flight::setFlightName(string flightName) {
	flightNameM = flightName;
}

void Flight::setRows(int rows) {
	rowsM = rows;
}

void Flight::setSeats(int seats) {
	seatsM = seats;
}
void Flight::addPassenger(const Passenger & source) {
	passengersM.resize(passengersM.size()+1);
	passengersM[passengersM.size()-1].setID(source.getID());
	passengersM[passengersM.size()-1].setFirstName(source.getFirstName());
	passengersM[passengersM.size()-1].setLastName(source.getLastName());
	passengersM[passengersM.size()-1].setPhoneNumber(source.getPhoneNumber());
	passengersM[passengersM.size()-1].setSeat(source.getSeat().getRow(), source.getSeat().getSeat());
}
void Flight::removePassenger(const int ID) {
	for(int i = 0; i < static_cast<int>(passengersM.size()); i++) {
		if(passengersM[i].getID() == ID) {
			passengersM.erase(passengersM.begin()+i);
		}
	}
}
void Flight::show_seat_map() {
	if(rowsM != 0 && seatsM != 0) {
		vector < vector <int> > m (rowsM, vector<int> (seatsM));
		for(int i = 0; i < static_cast<int>(passengersM.size()); i++) {
			m.at(passengersM.at(i).getSeat().getRow()-1).at(static_cast<int>(passengersM.at(i).getSeat().getSeat())-65) = 1;
		}
		cout <<"Aircraft Seat Map\n";
		cout <<"     ";
		for(int i = 0; i < seatsM; i++) {
			cout <<static_cast<char>(i+65) << "   ";
		}
		cout << "\n";
		cout << "   +";
		for(int j = 0; j < seatsM; j++) {
			cout << "---+";
		}
		cout << "\n";
		for(int i = 0; i < rowsM; i++) {
			cout << setw(2) << setiosflags(ios::left) <<i+1 << " |";
			for(int j = 0; j < seatsM; j++) {
				if(m.at(i).at(j) == 0) {
					cout << "   |";
				} else {
					cout << " X |";
				}
			}
			cout << "\n";
			cout << "   +";
			for(int j = 0; j < seatsM; j++) {
				cout << "---+";
			}
			cout << "\n";
		}
	} else {
		cout << "Current flight has no rows or seats. Seat Map cannot be presented.\n";
	}
}