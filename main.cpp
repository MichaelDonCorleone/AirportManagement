/***************************************
	Assignment   : Final Project
	File Name    : main.cpp
	Created By   : Apostolos Scondrianis
	Submitted On : Monday 15th, June 2020
****************************************/

#include "Airline.cpp"
#include "User.cpp"
#include "main.h"
#include "readPassengerFromKeyboard.cpp"
#include "readFlightFromKeyboard.cpp"

int main(void) {
	int choice;
	User assign(1, 1, "JohnDoer", "thunderstar1993", "Apostolos", "Scondrianis", "403-978-8941");
	User test(2, 2, "JohnDoerw", "thunderstar1993", "Apostolos", "Scondrianis", "403-978-8941");
	User test2(3, 2, "JohnDoers", "thunderstar1993", "Apostolos", "Scondrianis", "403-978-8941");
	User operatingUser;
	vector<User> userDatabase;
	userDatabase.push_back(assign);
	userDatabase.push_back(test);
	userDatabase.push_back(test2);
	int airlineFlag;
	vector <Airline> airlines;
	readAirlinesFromFile(airlines, "airline_info.txt");
	//airlines.resize(4);
/*	airlines[0].setID(0);
	airlines[1].setID(1);
	airlines[2].setID(2);
	airlines[3].setID(3);
	airlines[0].setAirlineName("West Jest");
	airlines[1].setAirlineName("British Airways");
	airlines[2].setAirlineName("Air Canada");
	airlines[3].setAirlineName("American Airways");*/
	Flight f;
	f = populate_flight_from_file("flight_info.txt");
	airlines[0].addFlight(f);
	
	cout << "Version 1.0" << endl;
	cout << "Term Project - Flight Management Program in C++" << endl;
	cout << "Produced by: Apostolos Scondrianis" << endl;
	pressEnter();

	cout << "Welcome to Flight Management login System v 1.0 in C++.\n";
	
	displayUserHeader(operatingUser);
	
	while((choice = loginMenu(operatingUser))) {
		if(operatingUser.getAccessLevel() == 0) {
			switch(choice) {
				case 1:
					pressEnter();
					displayUserHeader(operatingUser);
					break;
				case 2:
					loginOption(operatingUser, userDatabase);
					cout << "Username : " << operatingUser.getUsername() << " . Password : " << operatingUser.getPassword() << " . \n";
					pressEnter();
					displayUserHeader(operatingUser);
					break;
				case 3:
					cout << "Program terminated. \n";
					exit(1);
					break;
			}
		} else {
			if(operatingUser.getAccessLevel() == 1) {
				switch(choice) {
					case 1:
						cout << "You have selected the Airline Menu Option.\n";
						pressEnter();
						displayAirlineHeader();
						airlineFlag = 1;
						while(airlineFlag == 1 && (choice = airlineMenu())) {
							switch(choice) {
								case 1:
									displayAirlines(airlines);
									pressEnter();
									displayAirlineHeader();
									break;
								case 2:
									selectAirline(airlines);
									pressEnter();
									displayAirlineHeader();
									break;
								case 3:
									createAirline(airlines);
									pressEnter();
									displayAirlineHeader();
									break;
								case 4:
									deleteAirline(airlines);
									pressEnter();
									displayAirlineHeader();
									break;
								case 5:
									saveAirlines(airlines);
									pressEnter();
									displayAirlineHeader();
									break;
								case 6:
									cout << "You have exited the Airline menu.\n";
									airlineFlag = 0;
									break;
							}
						}
						displayUserHeader(operatingUser);
						break;
					case 2:
						displayUsers(userDatabase);
						pressEnter();
						displayUserHeader(operatingUser);
						break;
					case 3:
						saveUsers(userDatabase);
						pressEnter();
						displayUserHeader(operatingUser);
						break;
					case 4:
						cout << "You have successfully logged out.\n";
						operatingUser.setID(0);
						operatingUser.setAccessLevel(0);
						operatingUser.setUsername("\0");
						operatingUser.setPassword("\0");
						operatingUser.setFirstName("\0");
						operatingUser.setLastName("\0");
						operatingUser.setPhoneNumber("\0");
						pressEnter();
						displayUserHeader(operatingUser);
						break;
					case 5:
						cout << "Program terminated.\n";
						exit(1);
						break;
				}
			} else {
				switch(choice) {
					case 1:
						cout << "You have selected the Airline Menu Option.\n";
						pressEnter();
						displayAirlineHeader();
						airlineFlag = 1;
						while(airlineFlag == 1 && (choice = airlineMenu())) {
							switch(choice) {
								case 1:
									displayAirlines(airlines);
									pressEnter();
									displayAirlineHeader();
									break;
								case 2:
									selectAirline(airlines);
									pressEnter();
									displayAirlineHeader();
									break;
								case 3:
									createAirline(airlines);
									pressEnter();
									displayAirlineHeader();
									break;
								case 4:
									deleteAirline(airlines);
									pressEnter();
									displayAirlineHeader();
									break;
								case 5:
									saveAirlines(airlines);
									pressEnter();
									displayAirlineHeader();
									break;
								case 6:
									cout << "You have exited the Airline menu.\n\n";
									airlineFlag = 0;
									break;
							}
						}
						displayUserHeader(operatingUser);
						break;
					case 2:
						cout << "You have successfully logged out.\n";
						operatingUser.setID(0);
						operatingUser.setAccessLevel(0);
						operatingUser.setUsername("\0");
						operatingUser.setPassword("\0");
						operatingUser.setFirstName("\0");
						operatingUser.setLastName("\0");
						operatingUser.setPhoneNumber("\0");
						pressEnter();
						displayUserHeader(operatingUser);
						break;
					case 3:
						cout << "Program terminated.\n";
						exit(1);
						break;
				}
			}
		}
	}
	
	return 0;
}

void displayUserHeader(User & operatingUser) {
	if(operatingUser.getAccessLevel() == 0) {
		cout << "Please select one of the following options:\n";
		cout << "1. Create new account.\n";
		cout << "2. Login with an existing account.\n";
		cout << "3. Quit.\n";
		cout << "Enter your choice: (1, 2 or 3) : ";
	} 
	else if(operatingUser.getAccessLevel() == 1) {
		cout << "Please select one of the following options:\n";
		cout << "1. Enter Airline menu.\n";
		cout << "2. Print users.\n";
		cout << "3. Save users in \"user_info.txt\".\n";
		cout << "4. Logout.\n";
		cout << "5. Quit. \n";
		cout << "Enter your choice: (1, 2, 3, 4 or 5) : ";			
	}
	else {
		cout << "Please select one of the following options:\n";
		cout << "1. Enter Airline menu.\n";
		cout << "2. Logout.\n";
		cout << "3. Quit.\n";
		cout << "Enter your choice: (1, 2 or 3) : ";		
	}
}

int loginMenu(User & operatingUser) {
	char choice;
	while(1) {
		choice = cin.get();
		if(choice == '\n') {
			cout << "You have given an invalid input.";
		}else {
			if(operatingUser.getAccessLevel() == 0) {
				if(static_cast<int>(choice) - 48 <= 3 && static_cast<int>(choice) - 48 >= 1) {
					cleanStandardInputStream();
					return static_cast<int>(choice) - 48;
				} else {
					cout << "You have given an invalid input. Please give an input between 1 and 3.\n\n";
					cleanStandardInputStream();
				}
			} else if(operatingUser.getAccessLevel() == 1) {
				if(static_cast<int>(choice) - 48 <= 5 && static_cast<int>(choice) - 48 >= 1) {
					cleanStandardInputStream();
					return static_cast<int>(choice) - 48;
				} else {
					cout << "You have given an invalid input. Please give an input between 1 and 3.\n\n";
					cleanStandardInputStream();
				}			
			} else {
				if(static_cast<int>(choice) - 48 <= 3 && static_cast<int>(choice) - 48 >= 1) {
					cleanStandardInputStream();
					return static_cast<int>(choice) - 48;
				} else {
					cout << "You have given an invalid input. Please give an input between 1 and 3.\n\n";
					cleanStandardInputStream();
				}			
			}
		}
		displayUserHeader(operatingUser);
	}
}

void loginOption(User & operatingUser,vector<User> & userDatabase) {
	string username;
	string password;
	if(static_cast<int>(userDatabase.size()) == 0) {
		cout << "\nThere are no users in the database. Unable to initiate login process.\n";
		cout << "Program will now terminate.\n";
		exit(1);
	} else {
		cout << "\nPlease enter your username : ";
		getline(cin, username, '\n');
		if(cin.fail()) {
			cin.clear();
			cleanStandardInputStream();
			cout << "Something went wrong when trying to read a username. Please try again.\n";
		} else {
			if(username.length() >= 8) {
				if(username.length() <= 20) {
					for(int i = 0; i < static_cast<int>(userDatabase.size()); i++) {
						if(username == userDatabase[i].getUsername()) {
							cout << "User Found.\n";
							cout << "Please enter password : ";
							getline(cin, password, '\n');
							if(cin.fail()) {
								cout << "Something went wrong when trying to read a password. Please try again.\n";
							} else {
								if(password.length() >= 8) {
									if(password.length() <= 20) {
										if(password == userDatabase[i].getPassword()) {
											cout << "You have successfully logged in as : " << username << endl;
											operatingUser = userDatabase[i];
										} else {
											cout << "The inputted password does not match the database password. Please try again.\n";
										}
									} else {
										cout << "Password needs to be between 8 and 20 characters. Please try again.\n";
									}
								} else {
									cout << "Password needs to be greateer or equal to 8 characters. Please try again.\n";
								}
							}
							break;
						} else {
							cout << "User not matching.\n";
						}
					}
				} else {
					cout << "Username needs to be between 8 and 20 characters.\n";
				}
			} else {
				cout << "Username needs to be greater or equal to 8 characters. Please try again.\n";
			}
		}
	}
}

void displayAirlineHeader() {
	cout << "Please select one of the following options:\n";
	cout << "1. Print Airline list.\n";
	cout << "2. Select Airline to modify.\n";
	cout << "3. Add Airline.\n";
	cout << "4. Delete Airline.\n";
	cout << "5. Save Airline data.\n";
	cout << "6. Exit Airline menu.\n";
	cout << "Enter your choice: (1, 2, 3, 4, 5 or 6) : ";
}

void displayFlightHeader() {
	cout << "Please select one of the following options:\n";
	cout << "1. Print flights associated with Airline.\n";
	cout << "2. Delete a flight.\n";
	cout << "3. Create a flight. \n";
	cout << "4. Select a flight to modify.\n";
	cout << "5. Exit flight menu.\n";
	cout << "Enter your choice: (1, 2, 3, 4 or 5) : ";
}

void displayModifyFlightHeader() {
	cout << "Please select one of the following options:\n";
	cout << "1. Display Flight Seat Map.\n";
	cout << "2. Display Passengers Information.\n";
	cout << "3. Add a New Passenger.\n";
	cout << "4. Remove an Existing Passenger\n";
	cout << "5. Save data\n";
	cout << "6. Exit the Modify a Flight Menu.\n\n";
	cout << "Enter your choice: (1, 2, 3, 4, 5 or 6) : ";
}

int flightMenu() {
	char choice;
	while(1) {
		choice = cin.get();
		if(choice == '\n') {
			cout << "You have given an invalid input.";
		} else {
			if(static_cast<int>(choice) - 48 <= 5 && static_cast<int>(choice) - 48 >= 1) {
				cleanStandardInputStream();
				return static_cast<int>(choice) - 48;
			} else {
				cout << "You have given an invalid input. Please give an input between 1 and 5.\n\n";
				cleanStandardInputStream();
			}
		}
		displayFlightHeader();
	}
}

int modifyFlightMenu() {
	char choice;
	while(1) {
		choice = cin.get();
		if(choice == '\n') {
			cout << "You have given an invalid input.";
		} else {
			if(static_cast<int>(choice) - 48 <= 6 && static_cast<int>(choice) - 48 >= 1) {
				cleanStandardInputStream();
				return static_cast<int>(choice) - 48;
			} else {
				cout << "You have given an invalid input. Please give an input between 1 and 6.\n\n";
				cleanStandardInputStream();
			}
		}
		displayModifyFlightHeader();
	}
}

int airlineMenu() {
	char choice;
	while(1) {
		choice = cin.get();
		if(choice == '\n') {
			cout << "You have given an invalid input.\n\n";
		} else {
			if(static_cast<int>(choice) - 48 <= 6 && static_cast<int>(choice) - 48 >=1) {
				cleanStandardInputStream();
				return static_cast<int>(choice) - 48;
			} else {
				cout << "You have given an invalid input. Please give an input between 1 and 5.\n\n";
				cleanStandardInputStream();
			}
		}
		displayAirlineHeader();
	}
}

void selectAirline(vector <Airline> & airlines) {
	int ID;
	if(static_cast<int>(airlines.size()) == 0) {
		cout << "There are no airlines registered in the system.\n\n";
	} else {
		while(1) {
			cout << "Please enter the ID of the Airline that needs to be modified : ";
			cin >> ID;
			if(cin.fail()) {
				cout << "You have given an ID that is not valid. Make sure the ID is a number between 1 and 100.\n";
				cin.clear();
				cleanStandardInputStream();
			} else {
				if(ID >= 0 && ID <= 100) {
					int i;
					for(i = 0; i < static_cast<int>(airlines.size()); i++) {
						if(airlines[i].getID() == ID) {
							cout << "You chose to modify " << airlines[i].getAirlineName() <<".\n\n";
							cleanStandardInputStream();
							modifyAirline(airlines[i]);
							break;
						}
					}
					if(i == static_cast<int>(airlines.size())) {
						cout << "Airline with given ID not found.\n";
						cleanStandardInputStream();
					}
					break;
				} else {
					cout << "Airline ID must be between 0 and 100.\n";
					cleanStandardInputStream();
				}
			}
		}
	}
}

void createAirline(vector <Airline> & airlines) {
	int ID;
	int successAirlineName;
	char airlineName[21];
	Airline createdAirline;
	do {
		ID = readAirlineID(airlines);
	} while(ID == -1);
	do {
		successAirlineName = readAirlineName(airlineName, 21);
	} while(successAirlineName == 0);
	createdAirline.setID(ID);
	createdAirline.setAirlineName(airlineName);
	airlines.push_back(createdAirline);
	cout << "You have successfully created an airline with ID " << ID << " and airline name : " << airlineName << " .\n";
}
	
void deleteAirline(vector <Airline> & airlines) {
	int ID;
	int sizeBeforeDelete = static_cast<int>(airlines.size());
	if(static_cast<int>(airlines.size()) == 0) {
		cout << "There are no airlines registered in the system.\n";
		cout << "Please add one before trying to delete one.\n\n";
	} else {
		while(1) {
			cout << "Please enter the ID of the Airline that needs to removed : ";
			cin >> ID;
			if(cin.fail()) {
				cout << "You have given an ID that is not valid. Make sure the ID is a number between 0 and 100.\n";
				cin.clear();
				cleanStandardInputStream();
			} else {
				if(ID >= 0 && ID <= 100) {
					int i;
					for(i = 0; i < sizeBeforeDelete; i++) {
						if(airlines[i].getID() == ID) {
							cout << "You chose to delete " << airlines[i].getAirlineName() <<".\n";
							airlines.erase(airlines.begin()+i);
							//modifyAirline(airlines[i]);

							break;
						}
					}
					if(i == sizeBeforeDelete) {
						cout << "Airline with given ID not found.\n";
					}
					break;
				} else {
					cout << "Airline ID must be between 0 and 100.\n";
				}
			}
		}
		cleanStandardInputStream();
	}
}

void deleteFlight(Airline & airline) {
	const vector <Flight> & flights = airline.getFlights();
	int ID;
	int sizeBeforeDelete = static_cast<int>(flights.size());
	if(static_cast<int>(flights.size()) == 0) {
		cout << "There are no flights registered in the system for this airline.\n";
		cout << "Please add one before trying to delete one.\n";
	} else {
		while(1) {
			cout << "Please enter the ID of the Flight that needs to removed : ";
			cin >> ID;
			if(cin.fail()) {
				cout << "You have given an ID that is not valid. Make sure the ID is a number between 0 and 100.\n";
				cin.clear();
				cleanStandardInputStream();
			} else {
				if(ID >= 0 && ID <= 100) {
					int i;
					for(i = 0; i < sizeBeforeDelete; i++) {
						if(flights[i].getID() == ID) {
							cout << "You chose to delete " << flights[i].getFlightName() <<".\n";
							airline.removeFlight(i);
							break;
						}
					}
					if(i == sizeBeforeDelete) {
						cout << "Airline with given ID not found.\n";
					}
					break;
				} else {
					cout << "Airline ID must be between 0 and 100.\n";
				}
			}
		}
		cleanStandardInputStream();
	}	
}

void modifyAirline(Airline & airline) {
	int choice;
	displayFlightHeader();
	int flightFlag = 1;
	while(flightFlag == 1 && (choice = flightMenu())) {
		switch(choice) {
			case 1:
				displayFlights(airline);
				pressEnter();
				displayFlightHeader();
				break;
			case 2:
				deleteFlight(airline);
				pressEnter();
				displayFlightHeader();
				break;
			case 3:
				createFlight(airline);
				pressEnter();
				displayFlightHeader();
				break;
			case 4:
				selectFlight(airline);
				pressEnter();
				displayFlightHeader();
				break;
			case 5:
				cout << "Exiting Flight menu.\n";
				flightFlag = 0;
				break;
		}
	}
}

void pressEnter(){
	cout<< "\n<<< Press Return to Continue>>>>\n";
	cin.get();
}

void cleanStandardInputStream (void){
	int leftover;
	do{
		leftover = cin.get();
	} while(leftover !='\n' && leftover != EOF);
}

void displayPassengers(const Flight & source) {
	if(source.getPassengers().size() != 0) {
		cout << setw(20) << setiosflags(ios::left) <<"First Name"<< setw(20) <<"Last Name" << setw(20) << "Phone" << setw(6) << "Row" << setw(6) << "Seat" << setw(5) << "ID"<<endl;
		cout << "-----------------------------------------------------------------------------\n";
		for(int i = 0; i < static_cast<int>(source.getPassengers().size()); i++) {
			cout << setw(20) << source.getPassengers().at(i).getFirstName() << setw(20) << source.getPassengers().at(i).getLastName() << setw(20) << source.getPassengers().at(i).getPhoneNumber() << setw(6) << source.getPassengers().at(i).getSeat().getRow() << setw(6) << source.getPassengers().at(i).getSeat().getSeat() << setw(5) << source.getPassengers().at(i).getID() << endl;
			cout << "-----------------------------------------------------------------------------\n";
		}
	} else {
		cout << "The flight " << source.getFlightName() << " has no passengers yet.\n";
	}
}

void displayUsers(vector <User> & userDatabase) {
	if(userDatabase.size() > 0) {
		cout << "--------------------------------------------------------------------------------------------\n";
		cout << setw(20) << setiosflags(ios::left) << "Username " << setw(20) << "First Name" << setw(20) << "Last Name" << setw(20) <<"Phone" << setw(5) << "ID"<<endl;
		cout << "--------------------------------------------------------------------------------------------\n";
		for(int i = 0; i < static_cast<int>(userDatabase.size()); i++) {
			cout << setw(20) << setiosflags(ios::left) << userDatabase[i].getUsername() << setw(20) << userDatabase[i].getFirstName() << setw(20) << userDatabase[i].getLastName() << setw(20) << userDatabase[i].getPhoneNumber() << setw(5) << userDatabase[i].getID() <<endl;
			cout << "--------------------------------------------------------------------------------------------\n";
		}
	}
}

void displayAirlines(vector <Airline> & airlines) {
	if(airlines.size() == 0) {
		cout << "\nThere are no airlines to display\n";
	} else {
		cout << "\n--------------------------\n";
		cout << setw(5) << setiosflags(ios::left) << "ID" << setw(20) << "Airline Name" << endl;
		cout << "--------------------------\n";
		for(int i = 0; i < static_cast<int>(airlines.size()); i++) {
			cout << setw(5) << airlines[i].getID() <<setw(20) << airlines[i].getAirlineName() << endl;
			cout << "--------------------------\n";
		}
	}
}

void displayFlights(Airline & airline) {
	const vector <Flight> & flights = airline.getFlights();
	if(airline.getFlights().size() == 0) {
		cout << "\nThere are no flights to display\n";
	} else {
		cout << "\n-------------------------------\n";
		cout << setw(15) << setiosflags(ios::left) << " Airline ID " << setw(5) << "ID" << setw(20) << "Flight Name" << endl;
		cout << "-------------------------------\n";
		for(int i = 0; i < static_cast<int>(flights.size()); i++) {
			cout << setw(15) << flights[i].getAirlineID() << setw(5) << flights[i].getID() << setw(20) << flights[i].getFlightName() << endl;
			cout << "-------------------------------\n";
		}
	}
}

void createFlight(Airline & airline) {
	Flight createdFlight;
	int rows;
	int seats;
	int ID;
	int successName;
	char flightName[7];
	do {
		ID = readFlightID(airline.getFlights());
	} while(ID == -1);
	do {
		successName = readFlightName(flightName, 7);
	} while(successName == 0);
	do {
		rows = readRows();
	} while(rows == 0);
	do {
		seats = readSeats();
	} while(seats == 0);
	createdFlight.setID(ID);
	createdFlight.setRows(rows);
	createdFlight.setSeats(seats);
	createdFlight.setFlightName(flightName);
	airline.getFlights().push_back(createdFlight);
}

void selectFlight(Airline & airline) {
	vector <Flight> & flights = airline.getFlights();
	int ID;
	if(static_cast<int>(flights.size()) == 0) {
		cout << "There are no flights registered in the system for this airline.\n\n";
	} else {
		while(1) {
			cout << "Please enter the ID of the Flight that needs to be modified : ";
			cin >> ID;
			if(cin.fail()) {
				cout << "You have given an ID that is not valid. Make sure the ID is a number between 0 and 100.\n";
				cin.clear();
				cleanStandardInputStream();
			} else {
				if(ID >= 0 && ID <= 100) {
					int i;
					for(i = 0; i < static_cast<int>(flights.size()); i++) {
						if(flights[i].getID() == ID) {
							cout << "You chose to modify " << flights[i].getFlightName() <<".\n\n";
							cleanStandardInputStream();
							modifyFlight(flights[i]);
							break;
						}
					}
					if(i == static_cast<int>(flights.size())) {
						cout << "Flight with given ID not found.\n";
						cleanStandardInputStream();
					}
					break;
				} else {
					cout << "Flight ID must be between 0 and 100.\n";
					cleanStandardInputStream();
				}
			}
		}
	}
}

void modifyFlight(Flight & flight) {
	int choice;
	displayModifyFlightHeader();
	int flightFlag = 1;
	while(flightFlag == 1 && (choice = modifyFlightMenu())) {
		switch(choice){
			case 1:
				flight.show_seat_map();
				pressEnter();
				displayModifyFlightHeader();
				break;
			case 2:
				displayPassengers(flight);
				pressEnter();
				displayModifyFlightHeader();
				break;
			case 3:
				addPassenger(flight);
				pressEnter();
				displayModifyFlightHeader();
				break;
			case 4:
				removePassenger(flight);
				pressEnter();
				displayModifyFlightHeader();
				break;
			case 5:
				saveInformation(flight);
				pressEnter();
				displayModifyFlightHeader();
				break;				
			case 6:
				cout << "Exiting Modify flight menu.\n";
				flightFlag = 0;
				break;
		}
	}
}

void addPassenger(Flight & source) {
	Passenger createdPassenger;
	int ID;
	char firstName[20];
	char lastName[20];
	char phoneNumber[13];
	int validName;
	int validPhoneNumber;
	int row;
	char seat = 'A';
	int validRow;
	int validSeat;
	if(static_cast<int>(source.getPassengers().size()) == source.getRows()*source.getSeats()) {
		cout << "Unable to add passengers. The flight is full. Please remove a passenger in order to add another one.\n";
	} else {
		do {
			ID = readPassengerID(source);
		} while (ID == 0);
		do {
			validName = readPassengerFirstName(firstName, 20);
		} while(validName == 0);
		
		do {
			validName = readPassengerLastName(lastName, 20);
		} while(validName == 0);
		do {
			validPhoneNumber = readPassengerPhoneNumber(phoneNumber, 13);
		} while(validPhoneNumber == 0);
		do {
			validRow = readPassengerRow(&row, source);
		} while(validRow == 0);
		do {
			validSeat = readPassengerSeat(&row, &seat, source);
		} while(validSeat == 0);
		createdPassenger.setID(ID);
		createdPassenger.setFirstName(firstName);
		createdPassenger.setLastName(lastName);
		createdPassenger.setPhoneNumber(phoneNumber);
		createdPassenger.setSeat(row, seat);
		source.addPassenger(createdPassenger);
	}
	cin.ignore();
}

void removePassenger(Flight & source) {
	int ID;
	if(static_cast<int>(source.getPassengers().size()) == 0) {
		cout << "There are no passengers to be removed in this flight.\n";
	} else {
		while(1) {
			cout << "Please enter the ID of the passenger that needs to be removed : ";
			cin >> ID;
			if(cin.fail()) {
				cout << "You have given an ID that is not valid. Make sure the ID is a 5 digit number.\n";
				cin.clear();
				cleanStandardInputStream();
			} else {
				if(ID > 9999 && ID <= 99999) {
					int i;
					int sizeBeforeDelete = static_cast<int>(source.getPassengers().size());
					for(i = 0; i < sizeBeforeDelete; i++) {
						if(source.getPassengers().at(i).getID() == ID) {
							source.removePassenger(ID);
							cout << "Passenger with given ID successfully removed.\n";
							break;
						}
					}
					if(i == sizeBeforeDelete) {
						cout << "Passenger with given ID not found.\n";
					}
					break;
				} else {
					cout << "You are ID is not a 5 digit number.\n";
				}
			}
		}
	}
	cleanStandardInputStream();
}

void saveAirlines(vector <Airline> & airlines) {
	char choice;
	ofstream outputStream;
	while(1) {
		cout << "Would you like to save the airline data in the \"airline_info.txt\"? Please answer <Y or N> :";
		choice = cin.get();
		if(cin.fail()) {
			cout << "\nThere was an error while trying to read your selection. Please try again.\n";
			cin.clear();
			cleanStandardInputStream();
		} else {
			if(choice == 'Y') {
				outputStream.open("airline_info.txt");
				if(outputStream.fail()) {
					cout << "There was an error while trying to open the file. Operation was cancelled.\n";
					outputStream.close();
					break;
				} else {
					outputStream << setiosflags(ios::left);
					for(int i = 0; i < static_cast<int>(airlines.size()); i++) {
						outputStream << setw(6) << airlines[i].getID() << setw(20) << airlines[i].getAirlineName() << "\n";
					}
					cout << "\nAll the airline data was saved in the airline_info.txt\n";
					outputStream << setw(6) << "-1";
					cin.ignore();
					outputStream.close();
					break;
				}
			}else if(choice == 'N') {
				cout << "\nYou chose not to save any data.\n";
				cin.ignore();
				break;
			} else {
				cout << "\nYour input was not 'Y' or 'N'.Please try again.\n";
				cin.ignore();
			}
		}
	}
}

void saveInformation(Flight & f){
	char choice;
	ofstream outputStream;
	while(1) {
		cout << "Do you want to save the data in the \"flight_info.txt\"? Please answer <Y or N> :";
		choice = cin.get();
		if(cin.fail()) {
			cout << "\nThere was an error with your input. Please try again.\n";
			cin.clear();
			cleanStandardInputStream();
		} else {
			if(choice == 'Y') {
				outputStream.open("flight_info.txt");
				if(outputStream.fail()) {
					cout << "There was an error opening the file. Operation cancelled.\n";
					outputStream.clear();
					break;
				}else {
					outputStream << setw(9) << setiosflags(ios::left) << f.getFlightName() << setw(6) << f.getRows() << f.getSeats() << "\n";
					for(int i = 0; i < static_cast<int>(f.getPassengers().size()); i++) {
						outputStream << setw(20) << f.getPassengers().at(i).getFirstName() << setw(20) << f.getPassengers().at(i).getLastName() << setw(20) << f.getPassengers().at(i).getPhoneNumber();
						if(f.getPassengers().at(i).getSeat().getRow() > 9) {
							outputStream << f.getPassengers().at(i).getSeat().getRow() << f.getPassengers().at(i).getSeat().getSeat() <<" "<< f.getPassengers().at(i).getID() << "\n";
						} else {
							outputStream << f.getPassengers().at(i).getSeat().getRow() << f.getPassengers().at(i).getSeat().getSeat() <<"  "<< f.getPassengers().at(i).getID() << "\n";
						}
					}
					cout <<"\nAll the data in the passenger list was saved in the flight_info.txt\n";
					cin.ignore();
					outputStream.close();
					break;
				}
			}else if (choice == 'N') {
				cout << "\nYou chose not to save any data.\n";
				cin.ignore();
				break;
			} else {
				cout << "\nYour input was not 'Y' or 'N'.Please try again.\n";
				cin.ignore();
			}
		}
	}
	
}

void saveUsers(vector <User> & userDatabase) {
	char choice;
	ofstream outputStream;
	while(1) {
		cout << "Do you want to save the user data in the \"user_info.txt\"? Please enter <Y or N> : ";
		choice = cin.get();
		if(cin.fail()) {
			cout << "\nThere was an error while reading your choice. Please try again.\n";
			cin.clear();
			cleanStandardInputStream();
		} else {
			if(choice == 'Y') {
				outputStream.open("user_info.txt");
				if(outputStream.fail()) {
					cout << "There was an error while opening the file. Operation cancelled.\n";
					outputStream.clear();
					break;
				} else {
					int i;
					outputStream << setiosflags(ios::left);
					for(i = 0; i < static_cast<int>(userDatabase.size()); i++) {
						outputStream << setw(21) << userDatabase[i].getUsername() << setw(21) << userDatabase[i].getPassword() << setw(21) << userDatabase[i].getFirstName() << setw(21) << userDatabase[i].getLastName();
						outputStream << setw(13) << userDatabase[i].getPhoneNumber() << " " << userDatabase[i].getAccessLevel() << " " << userDatabase[i].getID() << "\n";
					}
					cout << "\n"<< i << " users have been saved successfully in the user_info.txt\n";
					outputStream.close();
					cin.ignore();
					break;
				}
			} else if(choice == 'N') {
				cout << "\nYou chose not to save any data.\n";
				cin.ignore();
				break;
			} else {
				cout << "\nYour input needs to either be 'Y' or 'N'. Please try again.\n";
				cin.ignore();
			}
		}
	}
}

void readAirlinesFromFile(vector <Airline> & airlines, string filename) {
	int ID;
	int characterCounter = 1;
	char airlineName[21];
	Airline createdAirline;
	char *p;
	ifstream inputStream(filename);
	if(inputStream.fail()) {
		cout << "There was an error opening the file... Program will now terminate.\n";
		inputStream.close();
		exit(1);
	}
	while(1) {
		inputStream >> ID;
		if(inputStream.eof()) {
			break;
		}else if(inputStream.fail()) {
			cout << "Something went wrong while reading Airline ID.\n";
			exit(1);
		}
		if(ID >= 0 && ID <= 10) {
			inputStream.ignore();
			inputStream.ignore();
			inputStream.ignore();
			inputStream.ignore();
			inputStream.ignore();
		} else if(ID > 10 && ID <= 100) {
			inputStream.ignore();
			inputStream.ignore();
			inputStream.ignore();
		} else if(ID > 100 && ID <= 1000) {
			inputStream.ignore();
			inputStream.ignore();
		} else {
			inputStream.ignore();
		}
		inputStream.get(airlineName, 21);
		cout << airlineName << "\n";
		if(inputStream.eof()) {
			break;
		} else if(inputStream.fail()) {
			cout << "Something went wrong while reading the airline name.\n";
			exit(1);
		}
		p = airlineName;
		while(*p != '\0' && characterCounter != 20) {
			if(*p == ' ' && *(p+1) == ' ') {
				*p = '\0';
				break;
			}
			p++;
			characterCounter++;
		}
		if(characterCounter == 20) {
			if(airlineName[19] == ' ') {
				airlineName[19] = '\0';
			} else {
				airlineName[20] = '\0';
			}
		}
		characterCounter = 1;
		createdAirline.setID(ID);
		createdAirline.setAirlineName(airlineName);
		airlines.push_back(createdAirline);
		cout << "test\n";
		inputStream.ignore();
	}
	inputStream.close();
}

Flight populate_flight_from_file(string filename) {
	Flight f;
	Passenger createdPassenger;
	char flightName[10];
	int rows;
	int seats;
	char firstName[21];
	char lastName[21];
	char seatCharacters[5];
	int passengerRow;
	char passengerSeat;
	char phoneNumber[21];
	int passengerID;
	ifstream inputStream(filename);
	char * p;
	int dashCounter;
	int spaceCounter;
	int validName;
	int validPhoneNumber;
	if(inputStream.fail()) {
		cout << "There was an error opening the file... Program will now terminate.\n";
		exit(1);
	}
	while(1) {
		inputStream.get(flightName, 10);
		if(inputStream.eof())
			break;
		else if(inputStream.fail()) {
			cout << "Something went wrong while reading the flight name.\n";
			exit(1);
		}
		inputStream >> rows >> seats;
		if(inputStream.eof())
			break;
		else if(inputStream.fail()) {
			cout << "Something went wrong while reading flight seats and rows.\n";
		}
		p = flightName;
		while(*p != '\0') {
			if(*p == ' ') {
				*p = '\0';
				break;
			}
			p++;
		}
		f.setFlightName(flightName);
		f.setRows(rows);
		f.setSeats(seats);
		f.setAirlineID(0);
		while(1) {
			inputStream.ignore();
			inputStream.get(firstName, 21);
			if(inputStream.eof())
				break;
			else if(inputStream.fail()) {
				cout << "Something went wrong while reading the passenger first name. Program will terminate.\n";
				cout << firstName << endl;
				exit(1);
				
			} else {
				if(static_cast<int>(strlen(firstName)) > 0) {
					int k;
					dashCounter = 0;
					spaceCounter = 0;
					validName = 1;
					for(k = 0; k < static_cast<int>(strlen(firstName)); k++) {
						if(!(isalpha(firstName[k]))) {
							if(!(firstName[k] == '-')) {
								if(k > 0 && spaceCounter == 0 && firstName[k] == ' ') {
									spaceCounter++;
								} else {
									if(spaceCounter == 1 && firstName[k] == ' ') {
										firstName[k] = '\0';
										break;
									} else {
										validName = 0;
										break;
									}
								}
							} else {
								if(dashCounter == 0) {
									if(k != 0) {
										dashCounter++;
									} else {
										validName = 0;
										break;
									}
								} else {
									validName = 0;
									break;												
								}
							}
						}
					}
				} else {
					validName = 0;
				}
				if(validName == 0) {
					cout << "There was an error with reading the passenger's first name. Program will terminate.\n";
					exit(1);
				}
			}
			inputStream.get(lastName, 21);
			if(inputStream.eof())
				break;
			else if(inputStream.fail()) {
				cout << "Something went wrong while reading the passenger last name. Program will terminate.\n";
				exit(1);
				
			} else {
				if(static_cast<int>(strlen(lastName)) > 0) {
					int k;
					dashCounter = 0;
					spaceCounter = 0;
					validName = 1;
					for(k = 0; k < static_cast<int>(strlen(lastName)); k++) {
						if(!(isalpha(lastName[k]))) {
							if(!(lastName[k] == '-')) {
								if(k > 0 && spaceCounter == 0 && lastName[k] == ' ') {
									spaceCounter++;
								} else {
									if(spaceCounter == 1 && lastName[k] == ' ') {
										lastName[k] = '\0';
										break;
									} else {
										validName = 0;
										break;
									}
								}
							} else {
								if(dashCounter == 0) {
									if(k != 0) {
										dashCounter++;
									} else {
										validName = 0;
										break;
									}
								} else {
									validName = 0;
									break;												
								}
							}
						}
					}
				} else {
					validName = 0;
				}
				if(validName == 0) {
					cout << "there was an error with reading the passenger's last name. Program will terminate.\n";
					exit(1);
				}
			}
			validPhoneNumber = 1;
			inputStream.get(phoneNumber, 21);
			if(inputStream.eof())
				break;
			else if(inputStream.fail()) {
				cout << "Something went wrong went reading the phone number of the passenger. Program will terminate.\n";
				exit(1);
			} else {
				phoneNumber[12] = '\0';
				if(!(static_cast<int>(strlen(phoneNumber)) == 12)) {
					validPhoneNumber = 0;
				} else {
					for(int z = 0; z < static_cast<int>(strlen(phoneNumber)); z++) {
						if(z < 3 || (z > 3 && z < 7) || (z > 7 && z <= 11)) {
							if(!isdigit(phoneNumber[z])) {
								validPhoneNumber = 0;
								break;
							}
						} else {
							if(phoneNumber[z] != '-') {
								validPhoneNumber = 0;
								break;
							}
						}
					}
				}
				if(validPhoneNumber == 0) {
					cout << "There was an error while reading the phone number of the passenger. Program will terminate.\n";
					exit(1);
				}
			}
			inputStream.get(seatCharacters, 5);
			if(inputStream.eof())
				break;
			else if(inputStream.fail()) {
				cout << "There was an error while reading the row and seat.Program will be terminated.\n";
				exit(1);
			} else {
				p = seatCharacters;
				while(*p != '\0') {
					if(*p == ' ') {
						*p = '\0';
						break;
					}
					p++;
				}
				passengerRow = 0;
				for(int i = 0; i < static_cast<int>(strlen(seatCharacters)); i++) {
					if(isdigit(seatCharacters[i])) {
						passengerRow = passengerRow*10 + static_cast<int>(seatCharacters[i]) - 48;
					} else {
						passengerSeat = seatCharacters[i];
					}
				}
			}
			inputStream >> passengerID;
			if(inputStream.eof())
				break;
			else if(inputStream.fail()) {
				cout << "There was an error reading the passenger ID. Program will be terminated.\n";
				exit(1);
			} else {
				if(!(passengerID > 9999 && passengerID <= 99999)) {
					cout << "passengerID needs to be a 5 digit number. Program will be terminated.\n";
					exit(1);
				}
			}

			createdPassenger.setID(passengerID);
			createdPassenger.setFirstName(firstName);
			createdPassenger.setLastName(lastName);
			createdPassenger.setPhoneNumber(phoneNumber);
			createdPassenger.setSeat(passengerRow, passengerSeat);
			f.addPassenger(createdPassenger);
		}
		break;
	}
	inputStream.close();
	return f;
}