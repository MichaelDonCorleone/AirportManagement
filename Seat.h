/*******************************
	Assignment   : Final Project
	File Name    : Seat.h
	Created By   : Apostolos Scondrianis
	Submitted On : Monday 15th, June 2020
*******************************/
#ifndef _SEEAT_HEADER_
#define _SEAT_HEADER_
class Seat {
	private:
		int rowM;
		char seatM;
	public:
		//Default Constructor
		Seat();
		//Constructor with row and seat arguments
		Seat(int row, char seat);
		//Copy Constructor
		Seat(const Seat & source);
		//Getters for the private members of the Seat object
		const int getRow() const;
		const char getSeat() const;
		//Setters for the private members of the Seat object
		void setRow(int row);
		void setSeat(char seat);
};
#endif