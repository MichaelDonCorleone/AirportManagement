/*******************************
	Assignment   : Final Project
	File Name    : Passenger.h
	Created By   : Apostolos Scondrianis
	Submitted On : Monday 15th, June 2020
*******************************/
#ifndef _PASSENGER_HEADER_
#define _PASSENGER_HEADER_
#include "Seat.cpp"
using namespace std;
class Passenger {
	private:
		int IDM;
		string firstNameM;
		string lastNameM;
		string phoneNumberM;
		Seat seatM;
	public:
		//default constructor
		Passenger();
		//Constructor
		Passenger(int ID, string firstNameM, string lastNameM, string phoneNumber, int row, char seat);
		//Copy Constructor
		Passenger(const Passenger &source);
		//Getter functions for the private members of Passenger objects
		const int getID() const;
		const string getFirstName() const;
		const string getLastName() const;
		const string getPhoneNumber() const;
		const Seat getSeat() const;
		//Setter functions for the private members of Passenger objects
		void setID(int ID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setPhoneNumber(string phoneNumber);
		void setSeat(int row, char seat);
};
#endif