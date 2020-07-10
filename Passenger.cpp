/*******************************
	Assignment   : Final Project
	File Name    : Passenger.cpp
	Created By   : Apostolos Scondrianis
	Submitted On : Monday 15th, June 2020
*******************************/
#include "Passenger.h"
Passenger::Passenger(): IDM(0),firstNameM("\0"),lastNameM("\0"), phoneNumberM("000-0000-0000")
{
}
Passenger::Passenger(int ID, string firstName, string lastName, string phoneNumber, int row, char seat): IDM(ID), firstNameM(firstName), 
																		lastNameM(lastName), phoneNumberM(phoneNumber), seatM(row, seat) 
{	
}


Passenger::Passenger(const Passenger &source) {
	IDM = source.IDM;
	firstNameM = source.firstNameM;
	lastNameM = source.lastNameM;
	phoneNumberM = source.phoneNumberM;
	seatM.setRow(source.seatM.getRow());
	seatM.setSeat(source.seatM.getSeat());
}

const int Passenger::getID() const {
	return IDM;
}

const string Passenger::getFirstName() const {
	return firstNameM;
}

const string Passenger::getLastName() const {
	return lastNameM;
}

const string Passenger::getPhoneNumber() const {
	return phoneNumberM;
}

const Seat Passenger::getSeat() const {
	return seatM;
}

void Passenger::setID(int ID) {
	IDM = ID;
}

void Passenger::setFirstName(string firstName) {
	firstNameM = firstName;
}

void Passenger::setLastName(string lastName) {
	lastNameM = lastName;
}

void Passenger::setPhoneNumber(string phoneNumber) {
	phoneNumberM = phoneNumber;
}
void Passenger::setSeat(int row, char seat) {
	seatM.setRow(row);
	seatM.setSeat(seat);
}