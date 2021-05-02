/*
 * Title:		student Class Method Definition
 * Purpose:		Implementation of all student class methods
 * Author:		Daniel Adebayo
 * Date:	    April 28, 2021
 */

#include "date.h"
#include "person.h"
#include "student.h"

#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
using std::string;
using std::stringstream;
using std::istream;
using std::ostream;

/**
 * student default constructor
 * Creates a student with a name and with birthday
 * at the system's date at the moment of instantiation
 */
Student::Student(const string &name, const Date &birthday) : Person(name, birthday) {

}
/**
 * student Constructor
 * Sets the name and birthday of the person
 *  name the person's name
 *  birthDay the person's birthday
 */
Student::Student(const string &name, const Date &birthday, const string &major) : Person(name, birthday){
    _major = major;
}

Student::~Student() {

}

string Student::ToString() const {
    stringstream retVal;
    retVal << "{Student " << Person::ToString() << ", major: " << _major << " credits: " << _credits << ", gpa: " << _gpa << "}";
    return retVal.str();
}

void Student::Read(istream &input) {

}

void Student::Write(ostream &output) const {

}
/**
 * Grade Accessor
 * @return the student's Grade
 */
void Student::AddGrade(float grade, size_t credits) {

}
/**
 * GPA Accessor
 * @return the student's GPA
 */
float Student::GetGPA() const {
    return _gpa;
}
/**
 * credit Accessor
 * @return the student's credits
 */
size_t Student::GetCredits() const {
    return 0;
}




