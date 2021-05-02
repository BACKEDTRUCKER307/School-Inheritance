/*
 * Title:		professor Class Declaration
 * Purpose:		A Class to represent a professor
 * Author:		Daniel Adebayo
 * Date:		April 28, 2021
 */

#ifndef SCHOOL_INHERITANCE_PROFESSOR_H
#define SCHOOL_INHERITANCE_PROFESSOR_H
#include "date.h"
#include "person.h"

class Professor: public Person {
    enum Rank {ASSISTANT_PROFESSOR, ASSOCIATE_PROFESSOR, PROFESSOR};
    string _department;
    Date _hireDate;
    Rank _rank;
    float _salary;
public:
    Professor(const string& name, const Date& birthday, const string& department);

    Professor(const string& name, const Date& birthday, const string& department, const Date & hireDate);

    Professor(const string& name, const Date& birthday, const string& department, const Date& hireDate, Rank rank, float salary);

   virtual ~Professor() ;

    string ToString()const override;

    void Read(istream& input) override;

    void Write(ostream& output)const override;

    void Raise(float percentage);

    void Promote();

    Rank GetRank()const;

    float GetSalary()const;
};


#endif
