/************************************************
	Assignment   : Final Project
	File Name    : readPFlightFromKeyboard.cpp
	Created By   : Apostolos Scondrianis
	Submitted On : Monday 15th, June 2020
************************************************/
int readAirlineID(vector <Airline> & airlines) {
	int ID;
	cout << "Please enter the Airline ID : ";
	cin >> ID;
	if(cin.fail()) {
		cout << "\nYou have given an invalid ID. Make sure your airline ID is an integer number.\n";
		cin.clear();
		cleanStandardInputStream();
		return -1;
	} else {
		if(ID >= 0 && ID <= 10000) {
			for(int i = 0; i < static_cast<int>(airlines.size()); i++) {
				if(ID == airlines[i].getID()) {
					cout << "You have given an ID that already exists. Please use a different ID.\n";
					return -1;
				}
			}
			cin.ignore();
			return ID;
		} else {
			cout << "Airline ID must be a number between 0 and 10000. Please try again.\n";
			return -1;
		}
	}
}

int readAirlineName(char * airlineName, int n) {
	char *p = airlineName;
	cout << "Please give the airline name : ";
	cin.getline(airlineName, n, '\n');
	if(cin.fail()) {
		cout << "The airline name should be less than or equal to " << n-1 << " characters. Please try again.\n";
		cin.clear();
		cleanStandardInputStream();
		return 0;
	} else {
		if((*p) == ' ') {
			cout << "The airline name cannot start with a space. Please try again.\n";
			return 0;
		} else {
			if(strlen(airlineName) >= 10) {
				while(*p != '\0') {
					if(!(isalpha(*p) || *p == ' ')) {
						cout << "The airline name can only include spaces and alphabetic characters. Please try again.\n";
						return 0;
					}
					p++;
				}
				return 1;
			} else {
				cout << "Airline name must be at least 10 characters. Please try again.\n";
				return 0;
			}
		}
	}
}

int readFlightName(char * flightName, int n) {
	char * p = flightName;
	cout << "Please enter the flight name : ";
	cin.getline(flightName, n, '\n');
	if(cin.fail()) {
		cout << "Something went wrong reading the flight name or the given flight name is longer than 6 characters.\n";
		cin.clear();
		cleanStandardInputStream();
		return 0;
	} else {
		if((*p >= 65 && *p <= 90) && (*(p+1) >= 65 && *(p+1) <= 90)) {
			p++;
			p++;
			while(*p != '\0') {
				if(!(*p >= 48 && *p <= 57)) {
					cout << "A Flight needs to have one of the following formats : XX* or XX** or XX*** or X****. Where XX is a capital letter and * a digit.\n";
					return 0;
				}
				p++;
			}
			if(p-flightName == 2) {
				cout << "You have only entered the two letters associated with the flight name. Please try again.\n";
				return 0;
			} else {
				cout << "Valid Flight Name.\n";
				return 1;
			}
		} else {
			cout << "The flight's name first two characters need to be between A and Z characters.\n";
			return 0;
		}
	}
}

int readFlightID(vector <Flight> & flights) {
	int ID;
	cout << "Please enter the flight ID : ";
	cin >> ID;
	if(cin.fail()) {
		cout << "\nYou have given an invalid input. Make sure your flight ID is a number that has 5 digits.\n";
		cin.clear();
		cleanStandardInputStream();
		return -1;
	} else {
		if(ID >= 0 && ID <= 1000) {
			for(int i = 0; i < static_cast<int>(flights.size()); i++) {
				if(flights[i].getID() == ID) {
					cout << "\nYou are trying to use an ID that has already been assigned.\nPlease enter a different ID.\n";
					return -1;
				}
			}
			cin.ignore();
			return ID;
		} else {
			cout << "\nYou have given an invalid input. Make sure your ID is a number between 0 and 1000.\n";
			return -1;
		}
	}
}

int readRows() {
	int rows;
	cout << "Please enter the number of rows the flight has: ";
	cin >> rows;
	if(cin.fail()) {
		cout << "\nYou have given an invalid input. Make sure the number of rows is a number.\n";
		cin.clear();
		cleanStandardInputStream();
		return 0;
	} else {
		if(rows > 0 && rows <= 46) {
			cin.ignore();
			return rows;
		} else {
			cout << "\nValid number of rows are between 1 and 46. Please enter a different number of rows.\n";
			return 0;
		}
	}
}

int readSeats() {
	int seats;
	cout << "Please enter the number of seats per row the flight has: ";
	cin >> seats;
	if(cin.fail()) {
		cout << "\nYou have given an invalid input. Make sure the number of seats per row is a number.\n";
		cin.clear();
		cleanStandardInputStream();
		return 0;
	} else {
		if(seats > 0 && seats < 13) {
			cin.ignore();
			return seats;
		} else {
			cout << "\nValid number of seats per row is between 1 and 12 seats. Please try again.\n";
			return 0;
		}
	}
}