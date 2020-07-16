/***************************************
	Assignment   : Final Project
	File Name    : main.cpp
	Created By   : Apostolos Scondrianis
	Submitted On : Monday 15th, June 2020
****************************************/

#include "Airline.cpp"
#include "User.cpp"
#include "main.h"

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
	readFlightsFromFile(airlines, "flights_info.txt");
	readPassengersFromFile(airlines, "passengers_info.txt");
	
	cout << "Version 1.0" << endl;
	cout << "Flight Management Program in C++" << endl;
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
									saveAirlineData(airlines);
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
									saveAirlineData(airlines);
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

/*************************************************************** 
					Option Header Functions 
***************************************************************/

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
	cout << "5. Exit the Modify a Flight Menu.\n\n";
	cout << "Enter your choice: (1, 2, 3, 4 or 5) : ";
}

/*************************************************************** 
					Menu Option Handlers
***************************************************************/

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
			if(static_cast<int>(choice) - 48 <= 5 && static_cast<int>(choice) - 48 >= 1) {
				cleanStandardInputStream();
				return static_cast<int>(choice) - 48;
			} else {
				cout << "You have given an invalid input. Please give an input between 1 and 5.\n\n";
				cleanStandardInputStream();
			}
		}
		displayModifyFlightHeader();
	}
}

/*************************************************************** 
				Main Menu Options'	Functions
***************************************************************/

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

/*************************************************************** 
				Airline Menu Options' Functions
***************************************************************/

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

void saveAirlineData(vector <Airline> & airlines) {
	char choice;
	ofstream outputStream;
	ofstream flightStream;
	ofstream passengerStream;
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
				flightStream.open("flights_info.txt");
				passengerStream.open("passengers_info.txt");
				if(outputStream.fail() || flightStream.fail() || passengerStream.fail()) {
					cout << "There was an error while trying to open the file. Operation was cancelled.\n";
					outputStream.close();
					break;
				} else {
					outputStream << setiosflags(ios::left);
					flightStream << setiosflags(ios::left);
					passengerStream << setiosflags(ios::left);
					for(int i = 0; i < static_cast<int>(airlines.size()); i++) {
						outputStream << setw(6) << airlines[i].getID() << setw(20) << airlines[i].getAirlineName() << "\n";
						for(int j = 0; j < static_cast<int>(airlines[i].getFlights().size()); j++) {
							flightStream << setw(6) << airlines[i].getID() << setw(4) << airlines[i].getFlights()[j].getID() << setw(9) << airlines[i].getFlights()[j].getFlightName() << setw(6) << airlines[i].getFlights()[j].getRows() << airlines[i].getFlights()[j].getSeats() << "\n";
							for(int k = 0; k < static_cast<int>(airlines[i].getFlights()[j].getPassengers().size()); k++) {
								passengerStream << setw(6) << airlines[i].getID() << setw(4) << airlines[i].getFlights()[j].getID() << setw(20) << airlines[i].getFlights()[j].getPassengers()[k].getFirstName() << setw(20) << airlines[i].getFlights()[j].getPassengers()[k].getLastName() << setw(20) << airlines[i].getFlights()[j].getPassengers()[k].getPhoneNumber();
								if(airlines[i].getFlights()[j].getPassengers()[k].getSeat().getRow() > 9) {
									passengerStream << airlines[i].getFlights()[j].getPassengers()[k].getSeat().getRow() << airlines[i].getFlights()[j].getPassengers()[k].getSeat().getSeat() <<" "<< airlines[i].getFlights()[j].getPassengers()[k].getID() << "\n";
								} else {
									passengerStream << airlines[i].getFlights()[j].getPassengers()[k].getSeat().getRow() << airlines[i].getFlights()[j].getPassengers()[k].getSeat().getSeat() <<"  "<< airlines[i].getFlights()[j].getPassengers()[k].getID() << "\n";
								}								
							}
						}
					}
					cout << "\nAll the airline data was saved in the airline_info.txt\n";
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

/*************************************************************** 
				Flight Menu Options' Functions
***************************************************************/

void displayFlights(Airline & airline) {
	const vector <Flight> & flights = airline.getFlights();
	if(airline.getFlights().size() == 0) {
		cout << "\nThere are no flights to display\n";
	} else {
		cout << "\n-------------------------------------------------------\n";
		cout << setw(15) << setiosflags(ios::left) << "Airline ID " << setw(5) << "ID" << setw(20) << "Flight Name" << setw(10) << "Rows" << setw(10) << "Seats" << endl;
		cout << "-------------------------------------------------------\n";
		for(int i = 0; i < static_cast<int>(flights.size()); i++) {
			cout << setw(15) << flights[i].getAirlineID() << setw(5) << flights[i].getID() << setw(20) << flights[i].getFlightName() << setw(10)<< flights[i].getRows() << setw(10) << flights[i].getSeats() << endl;
			cout << "-------------------------------------------------------\n";
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

/*************************************************************** 
				Modify Flight Menu Options' Functions
***************************************************************/

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

/*************************************************************** 
					Helper Functions
***************************************************************/

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

/*************************************************************** 
					Menu Functions
***************************************************************/

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
				cout << "Exiting Modify flight menu.\n";
				flightFlag = 0;
				break;
		}
	}
}

/*************************************************************** 
				Create Airline Helper Functions
***************************************************************/

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

/*************************************************************** 
				Create Flight Helper Functions
***************************************************************/

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

/*************************************************************** 
				Create Passenger Helper Functions
***************************************************************/

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

/*************************************************************** 
					Read From File Functions
***************************************************************/

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
		if(ID >= 0 && ID < 10) {
			inputStream.ignore();
			inputStream.ignore();
			inputStream.ignore();
			inputStream.ignore();
			inputStream.ignore();
		} else if(ID >= 10 && ID < 100) {
			inputStream.ignore();
			inputStream.ignore();
			inputStream.ignore();
		} else if(ID >= 100 && ID < 10000) {
			inputStream.ignore();
			inputStream.ignore();
		} else {
			inputStream.ignore();
		}
		inputStream.get(airlineName, 21);
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
		inputStream.ignore();
	}
	inputStream.close();
}

void readFlightsFromFile(vector <Airline> & airlines, string filename) {
	Flight createdFlight;
	int flightID;
	int airlineID;
	char flightName[7];
	char * p;
	int rows;
	int seats;
	ifstream readFlightStream(filename);
	if(readFlightStream.fail()) {
		cout << "Something went wrong while opening the flight file... Program will now terminate...\n";
		readFlightStream.close();
		exit(1);
	} else {
		while(1) {
			readFlightStream >> airlineID;
			if(readFlightStream.eof()) {
				break;
			} else if(readFlightStream.fail()){
				cout << "Something went wrong while reading the airline ID.\n";
				exit(1);
			}
			if(airlineID >= 0 && airlineID < 10) {
				readFlightStream.ignore();
				readFlightStream.ignore();
				readFlightStream.ignore();
				readFlightStream.ignore();
				readFlightStream.ignore();
			} else if(airlineID >= 10 && airlineID < 100) {
				readFlightStream.ignore();
				readFlightStream.ignore();
				readFlightStream.ignore();
			} else if(airlineID >= 100 && airlineID < 10000) {
				readFlightStream.ignore();
				readFlightStream.ignore();
			} else {
				readFlightStream.ignore();
			}
			readFlightStream >> flightID;
			if(readFlightStream.eof()) {
				break;
			} else if(readFlightStream.fail()) {
				cout << "There was an error while reading the flight ID.\n";
				exit(1);
			}
			if(flightID >= 0 && flightID < 10) {
				readFlightStream.ignore();
				readFlightStream.ignore();
				readFlightStream.ignore();
			} else if(flightID >= 10 && flightID <100) {
				readFlightStream.ignore();
				readFlightStream.ignore();
			} else {
				readFlightStream.ignore();
			}
			readFlightStream.get(flightName, 7);
			if(readFlightStream.eof()) {
				break;
			} else if(readFlightStream.fail()) {
				cout << "There was an error while reading the flight name.\n";
				exit(1);
			}
			p = flightName;
			while(*p != '\0') {
				if(*p == ' ') {
					*p = '\0';
					break;
				}
				p++;
			}
			readFlightStream >> rows >> seats;
			if(readFlightStream.eof()) {
				break;
			} else if(readFlightStream.fail()) {
				cout << "There was an error while reading seats or rows.\n";
				exit(1);
			}
			readFlightStream.ignore();
			for(int i = 0; i < static_cast<int>(airlines.size()); i++) {
				if(airlines[i].getID() == airlineID) {
					createdFlight.setID(flightID);
					createdFlight.setAirlineID(airlineID);
					createdFlight.setFlightName(flightName);
					createdFlight.setRows(rows);
					createdFlight.setSeats(seats);
					airlines[i].getFlights().push_back(createdFlight);
					break;
				}
			}
		}
		readFlightStream.close();
	}
}

void readPassengersFromFile(vector <Airline> & airlines, string filename) {
	Passenger createdPassenger;
	int airlineID;
	int flightID;
	int passengerID;
	int passengerRow;
	char firstName[21];
	char lastName[21];
	char phoneNumber[21];
	char seatCharacters[5];
	char passengerSeat;
	char *p;
	int spaceCounter;
	int dashCounter;
	int validName;
	int validPhoneNumber;
	ifstream readPassengerStream("passengers_info.txt");
	if(readPassengerStream.fail()) {
		cout << "There was an error opening the file... Program will now terminate.\n";
		readPassengerStream.close();
		exit(1);
	} else {
		while(1) {
			while(1) {
				readPassengerStream >> airlineID >> flightID;
				if(readPassengerStream.eof()) {
					break;
				}else if(readPassengerStream.fail()) {
					cout << "There was an error while reading the airlineID and flight ID.\n";
					exit(1);
				}
				if(flightID >= 0 && flightID < 10) {
					readPassengerStream.ignore();
					readPassengerStream.ignore();
					readPassengerStream.ignore();
				} else if(flightID >= 10 && flightID < 100) {
					readPassengerStream.ignore();
					readPassengerStream.ignore();
				} else {
					readPassengerStream.ignore();
				}
				readPassengerStream.get(firstName, 21);
				if(readPassengerStream.eof())
					break;
				else if(readPassengerStream.fail()) {
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
				readPassengerStream.get(lastName, 21);
				if(readPassengerStream.eof())
					break;
				else if(readPassengerStream.fail()) {
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
				readPassengerStream.get(phoneNumber, 21);
				if(readPassengerStream.eof())
					break;
				else if(readPassengerStream.fail()) {
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
				readPassengerStream.get(seatCharacters, 5);
				if(readPassengerStream.eof())
					break;
				else if(readPassengerStream.fail()) {
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
				readPassengerStream >> passengerID;
				if(readPassengerStream.eof())
					break;
				else if(readPassengerStream.fail()) {
					cout << "There was an error reading the passenger ID. Program will be terminated.\n";
					exit(1);
				} else {
					if(!(passengerID > 9999 && passengerID <= 99999)) {
						cout << "passengerID needs to be a 5 digit number. Program will be terminated.\n";
						exit(1);
					}
				}
				for(int i = 0; i < static_cast<int>(airlines.size()); i++) {
					if(airlines[i].getID() == airlineID) {
						for(int j = 0; j < static_cast<int>(airlines[i].getFlights().size()); j++) {
							if(flightID == airlines[i].getFlights()[j].getID()) {
									createdPassenger.setID(passengerID);
									createdPassenger.setFirstName(firstName);
									createdPassenger.setLastName(lastName);
									createdPassenger.setPhoneNumber(phoneNumber);
									createdPassenger.setSeat(passengerRow, passengerSeat);
									airlines[i].getFlights()[j].addPassenger(createdPassenger);
									readPassengerStream.ignore();
								break;
							}
						}
						break;
					}
				}
			}
			break;
		}
		readPassengerStream.close();
	}
}