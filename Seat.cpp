/*******************************
	Assignment   : Final Project
	File Name    : Flight.cpp
	Created By   : Apostolos Scondrianis
	Submitted On : Monday 15th, June 2020
*******************************/
#include "Seat.h"
Seat::Seat():rowM(0), seatM('0') {
}
Seat::Seat(int row, char seat): rowM(row), seatM(seat) {
}
Seat::Seat(const Seat & source) {
	rowM = source.rowM;
	seatM = source.seatM;
}
const int Seat::getRow() const{
	return rowM;
}
const char Seat::getSeat() const {
	return seatM;
}
void Seat::setRow(int row) {
	rowM = row;
}
void Seat::setSeat(char seat) {
	seatM = seat;
}