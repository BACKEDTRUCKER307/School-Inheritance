/*
 * Title:		person Class Method Definition
 * Purpose:		Implementation of all person class methods
 * Author:		Daniel Adebayo
 * Date:		April 28, 2021
 */
#include "person.h"
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
using std::string;
using std::stringstream;
using std::istream;
using std::ostream;

/**
 * Person default constructor
 * Creates a person with a name and with birthday
 * at the system's date at the moment of instantiation
 */
Person::Person(const string &name, const Date &birthday): _name(name), _birthday( birthday) {

}
/**
 * Person Constructor
 * Sets the name and birthday of the person. However this constructor does not take in
 * a Date for the birthday, instead it takes year, month and day of the birthday
 * @param name the person's name
 * @param year the person's birthday year
 * @param month the person's birthday month
 * @param day  the person's birthday day
 */
Person::Person(const string &name, size_t year, size_t month, size_t day): _name(name), _birthday(Date(year, month, day)) {

}

Person::~Person() {

}
/**
 * To String
 * Returns a string representation of the person. Will have the name and
 * birthday of the person.
 * @return string representation of person
 */
string Person::ToString() const {
    stringstream retVal;
    retVal << "{name: " << _name << ", birthday: " << _birthday.ToString() << "}";
    return retVal.str();
}

void Person::Read(istream &input) {

}

void Person::Write(ostream &output) const {

}
/**
 * Age Accessor
 * Calculates the age based on the birthday of the person and system's current
 * date.
 * @return the age of the person in years
 */
size_t Person::GetAge() const {

    return _birthday.Difference(Date::Now()) / 365;
}
/**
 * Name Accessor
 * @return the person's name
 */
string Person::GetName() const {
    return _name;
}
