/*
 * Title:		student Class Declaration
 * Purpose:		A Class to represent a student
 * Author:		Daniel Adebayo
 * Date:		April 28, 2021
 */

#ifndef SCHOOL_INHERITANCE_STUDENT_H
#define SCHOOL_INHERITANCE_STUDENT_H

#include "date.h"

class Student : public Person{
    string _major;
public:
    Student(const string& name, const Date& birthday);

    Student(const string& name, const Date& birthday, const string& major);

   virtual ~Student();

    string ToString()const override;

    void Read(istream& input);

    void Write(ostream& output)const;

    void AddGrade(float grade, size_t credits);

    float GetGPA()const;

    size_t GetCredits()const;


    float _gpa;
    size_t _credits;
};

#endif
