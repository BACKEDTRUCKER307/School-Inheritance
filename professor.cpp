/*
 * Title:		professor Class Method Definition
 * Purpose:		Implementation of all professor class methods
 * Author:		Daniel Adebayo
 * Date:		April 28, 2021
 */
#include "date.h"
#include "person.h"

#include <string>
#include <iostream>
#include <sstream>
#include "professor.h"
using std::stringstream;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
/**
 * Professor Constructor
 * Sets the name of the Professor, and the birthday at the system's date
 * at the moment of instantiation.
 * @param name the name of the Professor
 * and shows the department
 */
Professor::Professor(const string &name, const Date &birthday, const string &department) : Person(name, birthday),  _department(department){

}
/**
 * Professor Constructor
 * Sets the name of the Professor, and the birthday at the system's date
 * at the moment of instantiation.
 * @param name the name of the Professor
 * shows the hire date, department
 */
Professor::Professor(const string &name, const Date &birthday, const string &department, const Date &hireDate):
Person(name, birthday),  _department(department),_hireDate(hireDate){
    int i = _hireDate.Difference(Date::Now()) / 365;
    if (i <= 5){
        _salary = 60000;
        _rank = ASSISTANT_PROFESSOR;
    }else if (i >= 5 && i < 10){
        _salary = 70000;
        _rank = ASSOCIATE_PROFESSOR;
    }else if (i >= 10){
        _salary = 75000;
        _rank = PROFESSOR;
    }
}
/**
 * Professor Constructor
 * Sets the name of the Professor, and the birthday at the system's date
 * at the moment of instantiation.
 * @param name the name of the Professor
 * shows the hire date, department, rank and salary
 */
Professor::Professor(const string &name, const Date &birthday, const string &department, const Date &hireDate,
                     Professor::Rank rank, float salary): Person(name, birthday),  _department(department),_hireDate(hireDate), _salary(salary){

}

Professor::~Professor() {

}

string Professor::ToString() const {
    stringstream retVal;
    retVal << "Professor{" << Person::ToString() << ", department: " << _department << " Rank: " << _rank <<" hireDate: " << _hireDate.ToString()   << "Salary: $" << GetSalary() <<"}";
    return retVal.str();
}

void Professor::Read(istream &input) {
    Person::Read(input);
}

void Professor::Write(ostream &output) const {
    Person::Write(output);
}
/**
 * raise Accessor
 * @return the Professor's raise
 */
void Professor::Raise(float percentage) {
    _salary+= _salary*(percentage /100);
}

void Professor::Promote() {

    if(_rank == ASSISTANT_PROFESSOR){
        _rank = ASSOCIATE_PROFESSOR;
}
    else if (_rank = ASSOCIATE_PROFESSOR){
        _rank = PROFESSOR;
    }else{
        _rank = PROFESSOR;
    }
}
/**
 * rank Accessor
 * @return the Professor's rank
 */
Professor::Rank Professor::GetRank() const {
    return Professor::ASSISTANT_PROFESSOR;
}
/**
 * salary Accessor
 * @return the Professor's salary
 */
float Professor::GetSalary() const {

    return _salary;
}






