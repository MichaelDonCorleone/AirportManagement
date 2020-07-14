/************************************************
	Assignment   : Final Project
	File Name    : readPassengerFromKeyboard.cpp
	Created By   : Apostolos Scondrianis
	Submitted On : Monday 15th, June 2020
************************************************/

int readPassengerID(Flight &source) {
	int ID;
	cout << "Please enter the passenger ID : ";
	cin >> ID;
	if(cin.fail()) {
		cout << "\nYou have given an invalid input. Make sure your ID is a number that has 5 digits.\n";
		cin.clear();
		cleanStandardInputStream();
		return 0;
	} else {
		if(ID > 9999 && ID <= 99999) {
			for(int j = 0; j < static_cast<int>(source.getPassengers().size()); j++) {
				if(source.getPassengers().at(j).getID() == ID) {
						cout << "\nYou are  trying to use an ID that has already been assigned.\nPlease enter a different ID.\n";
						return 0;
				}
			}
			cin.ignore();
			return ID;
		} else {
			cout << "\nYou have given an invalid input. Make sure your ID is a number between 10000 and 99999.\n";
			return 0;
		}
	}
	
}

int readPassengerFirstName(char * firstName, int n) {
	int dashCounter;
	int spaceCounter;
	cout << "Please enter the passenger first name: ";
	cin.getline(firstName, n, '\n');
	if(cin.fail()) {
		cin.clear();
		cleanStandardInputStream();
		cout << "Something went wrong went reading the name or you inputted a name \nthat is longer than 19 characters. Try again.\n";
		return 0;
	} else {
		if(static_cast<int>(strlen(firstName)) > 0) {
			int k;
			dashCounter = 0;
			spaceCounter = 0;
			for(k = 0; k < static_cast<int>(strlen(firstName)); k++) {
				if(!(isalpha(firstName[k]))) {
					if(!(firstName[k] == '-')) {
						if(k > 0 && spaceCounter == 0) {
							spaceCounter++;
						} else {
							cout << "Your first name contains invalid characters. \nFirst name valid characters are alphabet characters and '-'.\n";
							return 0;
						}
					} else {
						if(dashCounter == 0) {
							if(k != 0) {
								dashCounter++;
							} else {
								cout << "The first name cannot start with a '-' character.\n";
								return 0;
							}
						}
						else {
							cout << "The first name inputted contains more than one '-'.\n";
							firstName[0] = '\0';
							return 0;								
						}
					}
				}
			}
			return 1;
		} else {
			cout << "You cannot have an empty string first name.\n\n";
			firstName[0] = '\0';
			return 0;
		}
	}
}

int readPassengerLastName(char *lastName, int n) {
	int dashCounter;
	int spaceCounter;
	cout << "Please enter the passenger's Last Name: ";
	cin.getline(lastName, n, '\n');
	if(cin.fail()) {
		cin.clear();
		cleanStandardInputStream();
		cout << "Something went wrong went reading the Last Name or you inputted a Last Name \nthat is longer than 19 characters. Try again.\n";
		return 0;
	} else {
		if(static_cast<int>(strlen(lastName)) > 0) {
			int k;
			dashCounter = 0;
			spaceCounter = 0;
			for(k = 0; k < static_cast<int>(strlen(lastName)); k++) {
				if(!(isalpha(lastName[k]))) {
					if(!(lastName[k] == '-')) {
						if(k > 0 && spaceCounter == 0 && lastName[k] == ' ') {
							spaceCounter++;
						} else {
							cout << "The Last Name contains invalid characters. \nLast Name valid characters are alphabet characters and '-'.\n";
							return 0;
						}
					} else {
						if(dashCounter == 0) {
							if(k != 0) {
								dashCounter++;
							} else {
								cout << "The Last Name cannot start with a '-' character.\n";
								return 0;
							}
						}
						else {
							cout << "The Last Name inputted contains more than one '-'.\n";
							return 0;											
						}
					}
				}
			}
			return 1;
		} else {
			cout << "You cannot have an empty Last Name input.\n\n";
			return 0;
		}
	}	
}

int readPassengerPhoneNumber(char *phoneNumber, int n) {
	cout << "Please enter the passenger phone number : ";
	cin.getline(phoneNumber, n, '\n');
	if(cin.fail()) {
		cin.clear();
		cleanStandardInputStream();
		cout << "Something went wrong went reading the name or you inputted a phone number \nthat is longer than 12 characters. Try again.\n";
		return 0;
	} else {
		if(!(static_cast<int>(strlen(phoneNumber)) == 12)) {
			cout << "The phone number inputted must have the following format : XXX-XXX-XXXX , where X is a digit between 0 and 9.\n";
			return 0;
		} else {
			for(int z = 0; z < static_cast<int>(strlen(phoneNumber)); z++) {
				if(z < 3 || (z > 3 && z < 7) || (z > 7 && z <= 11)) {
					if(!isdigit(phoneNumber[z])) {
						cout << "The phone number inputted must have the following format : XXX-XXX-XXXX , where X is a digit between 0 and 9.\n";
						return 0;
					}
				} else {
					if(phoneNumber[z] != '-') {
						cout << "The phone number inputted must have the following format : XXX-XXX-XXXX , where X is a digit between 0 and 9.\n";
						return 0;
					}
				}
			}
			return 1;
		}
	}
}

int readPassengerRow(int * row, Flight & source) {
	int howManyInRow = 0;
	cout << "\nPlease enter the passenger's desired row : ";
	cin >> *row;
	if(cin.fail()) {
		cout << "\nYou have given an invalid input. Make sure your row is a number. b\n";
		cin.clear();
		cleanStandardInputStream();
		return 0;
	} else {
		if(*row > 0 && *row <= source.getRows()) {
			if(static_cast<int>(source.getPassengers().size()) > 0) {
				for(int m = 0; m < static_cast<int>(source.getPassengers().size()); m++) {
					if(source.getPassengers().at(m).getSeat().getRow() == *row) { 
						howManyInRow++;
					}
				}
			} else {
				cin.ignore();
				return 1;
			}
			if(howManyInRow != source.getSeats()) {
				cin.ignore();
				return 1;
			} else {
				cout << "This Row is full. Please choose another one.\n";
				return 0;
			}
		} else {
			cout << "The flight has " << source.getRows() << " rows. Please input a number between 1 and ."<< source.getRows()<< "\n";
			return 0;
		}
	}
}

int readPassengerSeat(int *row, char *seat, Flight & source) {
	cout << "Please give the passenger's desired seat : ";
	*seat = cin.get();
	if(*seat == '\n') {
		cout << "You have given an invalid input.\n";
		return 0;
	}
	else {
		if((static_cast<int>(*seat) - 64) <= source.getSeats() && static_cast<int>(*seat) - 64 >= 0) {
			if(static_cast<int>(source.getPassengers().size()) > 0) {
				for(int m = 0; m < static_cast<int>(source.getPassengers().size()); m++) {
					if(source.getPassengers().at(m).getSeat().getRow() == *row && source.getPassengers().at(m).getSeat().getSeat() == *seat) {
						cout <<"You have given a seat that has been taken. Please try another seat.\n";
						cin.ignore();
						return 0;
					}
				}
				return 1;
			} else {
				return 1;
			}
		} else {
			cout << "You have given an invalid input. Please give an input for the seat between A and"<< static_cast<char>(source.getSeats()+64) <<".\n\n";
			cin.ignore();
			return 0;
		}
	}
}