/*****************************************
	Assignment   : Final Project
	File Name    : user.h
	Created By   : Apostolos Scondrianis
	Submitted On : Monday 15th, June 2020
*****************************************/
class User {
	private:
		int IDM;
		int accessLevelM;
		string usernameM;
		string passwordM;
		string firstNameM;
		string lastNameM;
		string phoneNumberM;
	public:
		//constructors
		User();
		User(int ID, int levelOfAccess, string username, string password, string firstName, string lastName, string phoneNumber);
		User(const User &source);
		User & operator =(User& source);
		//getters
		const int getID() const;
		const int getAccessLevel() const;
		const string getUsername() const;
		const string getPassword() const;
		const string getFirstName() const;
		const string getLastName() const;
		const string getPhoneNumber() const;
		//setters
		void setID(int ID);
		void setAccessLevel(int accessLevel);
		void setUsername(string username);
		void setPassword(string password);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setPhoneNumber(string phoneNumber);
};