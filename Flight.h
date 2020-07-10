/*******************************
	Assignment   : Final Project
	File Name    : Flight.h
	Created By   : Apostolos Scondrianis
	Submitted On : Monday 15th, June 2020
*******************************/
#ifndef _FLIGHT_HEADER_
#define _FLIGHT_HEADER_

#include "Passenger.cpp"



class Flight {
	private:
		int IDM;
		int airlineIDM;
		string flightNameM;
		int rowsM;
		int seatsM;
		vector<Passenger> passengersM;
	public:
		//Default Constructor
		Flight();
		//Constructor with all members
		Flight(int ID, int airlineID, string flightName, int rows, int seats, vector<Passenger> passengers);
		//Constructor without Passengers
		Flight(int ID, int airlineID, string flightName, int rows, int seats);
		//Copy constructor
		Flight(const Flight & source);
		//Flight Object getters
		const int getID() const;
		const int getAirlineID() const;
		const string getFlightName() const;
		const int getRows() const;
		const int getSeats() const;
		const vector<Passenger> getPassengers() const;
		//Flight Object setters
		void setID(int ID);
		void setAirlineID(int airlineID);
		void setFlightName(string flightName);
		void setRows(int rows);
		void setSeats(int seats);
		//helper functions
		void addPassenger(const Passenger &source); 
		//add a passenger to the passenger vector of the Object
		void removePassenger(const int passengerID);
		/*		   
		   REQUIRES : passengerID needs to be a valid ID of a passenger that exists in
		              the flight object's passengerM's vector.
		   PROMISES : If the passengerID is a valid ID and exists in the passengerM vector,
		              it removed the Pasenger object with that ID from the flight object.
	    */
		void show_seat_map();
		/*
		    REQUIRES : Rows and Seats of the flight have been defined and both are greater than
			           0.
		    PROMISES : Prints a seat plan of the flight as per instructions provided by the
			           Final Project instructions. If rows == 0 or seats == 0 no seat plan will
					   be printed.
	    */
};
#endif