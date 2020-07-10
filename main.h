/*******************************
	Assignment   : Final Project
	File Name    : main.h
	Created By   : Apostolos Scondrianis
	Submitted On :
*******************************/
#ifndef _MAIN_HEADER_
#define _MAIN_HEADER_

void displayUserHeader(User & operatingUser);
/*
	REQUIRES : ----
	PROMISES : Prints the login menu instructions.
*/

void displayModifyFlightHeader();

void displayFlightHeader();
/* 
    REQUIRES : ----
    PROMISES : Prints the menu instructions as per final project description
*/

void displayAirlineHeader();

void pressEnter();
/*
    REQUIRES : -----
    PROMISES : Oauses the program till the user hits the return key.
*/
void cleanStandardInputStream (void);
/*
    REQUIRES : ----
    PROMISES : Cleans the input buffer till it reaches EOF or \n character.
*/
int loginMenu(User & operatingUser);

int airlineMenu();

int modifyFlightMenu();

void selectAirline(vector <Airline> & airlines);

void deleteAirline(vector <Airline> & airlines);

void loginOption(User & operatingUser, vector<User> & userDatabase);

void displayUsers(vector <User> & userDatabase);

void displayAirlines(vector <Airline> & airlines);

void modifyAirline(Airline & airline);

void saveUsers(vector <User> & userDatabase);

void displayFlights(Airline & airline);

void deleteFlight(Airline & airline);

void selectFlight(Airline & airline);

void createFlight(Airline & airline);

void modifyFlight(Airline & airline, int position);

int flightMenu();
/*
    REQUIRES : The user must input a choice between 1 and 
    PROMISES : The function reads a selection from the keyboard
               until it is a digit between greater or equal to 1
	  		   and lesser or equal to 6. Appropriate error messages
			   are printed to the screen.
*/
void displayPassengers(const Flight &source);
/* 
    REQUIRES : The flight must have passengers to be able to display passengers.
    PROMISES : The information of the passengers that will be boarding this flight
               are printed to the screen according to the provided format by the
			   final project instructions.
*/

void addPassenger(Flight & source);
/*
    REQUIRES : ID must not be already given to an existing passenger and must be a valid number of
               5 digits, First name must be of 19 characters, cannot have more than one space or 
			   hyphenation, Last name must be of 19 characters, cannot have more than one space or 
			   hyphenation, Phone number must 12 characters long and of the following format : 
			   XXX-XXX-XXXX where X is a valid digit between 0 and 9, row must be an integer
			   greater or equal to 1 and lesser or equal to the flight object's amount of Rows,
			   seat is a character greater or equal to A and lesser or equal to the flight object's
			   maximum seat.
	PROMISES : If flight is not full it reads all reequired member fields of a passenger's object 
	           from the keyboard until valid data has been gathered, creates an object Passenger 
			   and adds it to the flight's passenger vector. If flight is full nothing happens.
*/

void removePassenger(Flight & source);
/*
	REQUIRES : An ID that is a valid number of 5 digits is given. 
	           Passenger with given ID must exist. 
	PROMISES : Removes the passenger with the ID given. If a
	           passenger with the given ID does not exist
			   nothing happens. If the flight is empty, nothing 
			   happens.
*/
Flight populate_flight_from_file(string filename);
/*
	REQUIRES : A valid non corrupt file exists. First Line must have
	           Flight information with the following format :
			   XXXXXXXX ##    #
			   Subsequent lines should contain data of passengers
			   with the following format
			   ******************* ------------------- XXX-XXX-XXXX        RRS +++++
			   Where * is the first name - is the last name XXX-XXX-XXXX is the phone
			   number. RR is the number of rows, S number of seats +++++.
	PROMISES : Attempts to read the file using the requirements used for creating a new
	           passenger in the function void addPassenger(Flight & souurce). If any
			   error occurs with the formatting, or the inputStream the program 
			   terminates. If the file reading is successfully, a Flight is populated
			   with Flight information and passenger information accordingly.
*/
void saveInformation(Flight &source);
/*  REQUIRES : Output stream successfully opens. If not nothing happens.
    PROMISES : Prompts user to confirm that they would like to save current flight 
	           Information. Then attempts to save the program's data in the 
			   required format by the final projects pdf. 
*/

int readPassengerID(Flight &source);
/*
	REQUIRES : -----
	PROMISES : Returns a valid ID.
*/

int readPassengerFirstName(char * firstName, int n);

int readPassengerLastName(char *lastName, int n);

int readPassengerPhoneNumber(char *phoneNumber, int n);

int readPassengerRow(int * row, Flight & source);

int readPassengerSeat(int * row, char *seat, Flight & source);

#endif