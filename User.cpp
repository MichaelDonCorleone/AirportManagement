/******************************************
	Assignment   : Final Project
	File Name    : User.cpp
	Created By   : Apostolos Scondrianis
	Submitted On : Monday 15th, June 2020
******************************************/
#include "User.h"
User::User(): IDM(0), accessLevelM(0), usernameM("\0"), passwordM("\0"), firstNameM("\0"), lastNameM("\0"), phoneNumberM("\0") 
{
}

User::User(int ID, int accessLevel, string username, string password, string firstName, string lastName, string phoneNumber):
						IDM(ID), accessLevelM(accessLevel), usernameM(username), passwordM(password), firstNameM(firstName), lastNameM(lastName), phoneNumberM(phoneNumber) 
{
} 
User::User(const User &source): IDM(source.IDM), accessLevelM(source.accessLevelM), usernameM(source.usernameM), 
							passwordM(source.passwordM), firstNameM(source.firstNameM), lastNameM(source.lastNameM), phoneNumberM(source.phoneNumberM)
{
}
User & User::operator=(User & source) {
	if(this != &source) {
		IDM = source.IDM;
		accessLevelM = source.accessLevelM;
		usernameM = source.usernameM;
		passwordM = source.passwordM;
		firstNameM = source.firstNameM;
		lastNameM = source.lastNameM;
		phoneNumberM = source.phoneNumberM;
	}
	return *this;
}
const int User::getID() const {
	return IDM;
}

const int User::getAccessLevel() const {
	return accessLevelM;
}

const string User::getUsername() const {
	return usernameM;
}

const string User::getPassword() const {
	return passwordM;
}

const string User::getFirstName() const {
	return firstNameM;
}

const string User::getLastName() const {
	return lastNameM;
}

const string User::getPhoneNumber() const {
	return phoneNumberM;
}

void User::setID(int ID) {
	IDM = ID;
}

void User::setAccessLevel(int accessLevel) {
	accessLevelM = accessLevel;
}

void User::setUsername(string username) {
	usernameM = username;
}

void User::setPassword(string password) {
	passwordM = password;
}

void User::setFirstName(string firstName) {
	firstNameM = firstName;
}

void User::setLastName(string lastName) {
	lastNameM = lastName;
}

void User::setPhoneNumber(string phoneNumber) {
	phoneNumberM = phoneNumber;
}