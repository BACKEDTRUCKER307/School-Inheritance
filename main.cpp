/*
 * Title:		main file
 * Purpose:		to uses all classes
 * Author:		Daniel Adebayo
 * Date:		April 28, 2021
 */
#include "date.h"
#include "person.h"
#include "student.h"
#include "professor.h"
#include <string>

#include <iostream>
#include <vector>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;

size_t Menu();

int main(int argc, char* argv[]) {
	vector<Person*> people; // This is the only vector you need, remember to release the memory
	int userOption;
	while ( (userOption = Menu()) != 15){
		if (userOption == 1){			// Add Person
		    string name;
		    int year, month, day;
            cout << "Name: " ;
            cin >> name;
            cout << "Birth date yyyy mm dd: " << endl;
            cin >> year >> month >> day;
            Date birthday = Date(year,month,day);
            while (0 == birthday.GetYear() && 0 == birthday.GetMonth() && 0 == birthday.GetDay()){
                cout << "invalid date" << endl;
                cout << "Birth date yyyy mm dd: " << endl;
                cin >> year >> month >> day;
                birthday = Date(year,month,day);
            }
            people.push_back(new Person(name, Date(year, month, day)));
            cout << "Person inserted in position:" ;
            cout << people.size()-1<< endl;
		}else if (userOption == 2){		// Add Student
            string name,  major;
            int year, month, day;
            cout << "Name: " ;
            cin >> name;
            cout << "Birth date yyyy mm dd: " << endl;;
            cin >> year >> month >> day;
            Date birthday = Date(year,month,day);
            while (0 == birthday.GetYear() && 0 == birthday.GetMonth() && 0 == birthday.GetDay()){
                cout << "invalid date" << endl;
                cout << "Birth date yyyy mm dd: " << endl;
                cin >> year >> month >> day;
                birthday = Date(year,month,day);
            }
            cout << "Major: ";
            cin >> major;
            cout << "Student inserted in position:";
            people.push_back(new Student(name, Date(year, month, day), major));
            cout << people.size()-1<< endl;
		}else if (userOption == 3){		// Add Professor
            string name, Department,hireDate;
            int year, month, day;
            int year2, month2, day2;
            cout << "Name: " ;
            cin >> name;
            cout << "Birth date yyyy mm dd: " << endl;;
            cin >> year >> month >> day;
            Date birthday = Date(year,month,day);
            while (0 == birthday.GetYear() && 0 == birthday.GetMonth() && 0 == birthday.GetDay()){
                cout << "invalid date" << endl;
                cout << "Birth date yyyy mm dd: " << endl;
                cin >> year >> month >> day;
                birthday = Date(year,month,day);
            }
            cout << "Department: ";
            cin >> Department;
            cout << "Hire Date yyyy mm dd: ";
            cin >> year2 >> month2 >> day2;
            cout << "Professor inserted in position:";
            people.push_back(new Professor(name, Date(year, month, day), Department, Date(year2, month2, day2)));
            cout << people.size()-1<< endl;
		}else if (userOption == 4){		// List All People
            for (Person* people: people){
                if (dynamic_cast<Person*>(people) != nullptr) {
                    Person* person = dynamic_cast<Person*>(people);
                    cout << people->ToString() << endl;
                    cout << endl;
                }
            }
		}else if (userOption == 5){		// Show Students Report
            for (Person* people: people){
                if (dynamic_cast<Student*>(people) != nullptr) {
                    Student* person = dynamic_cast<Student *>(dynamic_cast<Person *>(people));
                    cout << people->ToString() << endl;
                    cout << endl;
                }
            }
		}else if (userOption == 6){		// Show Professor Report
            for (Person* people: people){
                if (dynamic_cast<Professor*>(people) != nullptr) {
                    Professor* person = dynamic_cast<Professor *>(dynamic_cast<Person *>(people));
                    cout << people->ToString() << endl;
                    cout << endl;
                }
            }
		}else if (userOption == 7){		// Show !Professor !Student
            for (Person* people: people){
                if (dynamic_cast<Student*>(people) == nullptr && dynamic_cast<Professor*>(people) == nullptr) {
                    cout << people->ToString() << endl;
                    cout << endl;
                }
            }
		}else if (userOption == 8){		// Calculate Average GPA
		    float TotalGPA = 0;
            float AverageGPA ;
            size_t i = 0;
            cout << "The average GPA of the students is: ";
            for(Person* people: people){
                if (dynamic_cast<Student*>(people) != nullptr){
                    ++i;
                    Student* student = dynamic_cast<Student*>(people);

                    TotalGPA = student-> GetGPA();
                }
            }
            AverageGPA = TotalGPA / i;
          cout << AverageGPA << endl;

		}else if (userOption == 9){		// Calculate Average Salary
		    float AverageSal = 0;
		    float TotalSal = 0;
		    size_t ProfessorTotal = 0;
            cout << "The average salary of the professor is: " << endl;
           for(size_t i = 0; i < people.size(); ++i ){
               if(dynamic_cast<Professor*>(people.at(i)) != nullptr){
                   Professor* professor = dynamic_cast<Professor*>(people.at(i));
                   ++ProfessorTotal;
                   TotalSal += professor->GetSalary();
               }
           }
           AverageSal = TotalSal/ProfessorTotal;
           cout << AverageSal<< endl;
           cout <<endl;

		}else if (userOption == 10){	// Input Grades to Student
		    float Grade, GradeNo;
		   size_t Credit, CreditNo;
		    size_t i = 0;
		    vector<size_t> studentNumber;
            for (Person* persons: people) {
                i++;
                if(dynamic_cast<Student*>(persons) != nullptr) {
                    studentNumber.push_back(i);
                    Student *student = dynamic_cast<Student *>(persons);
                    cout << i << " " << student->ToString() << endl;
                }
                cout << endl;
            }
            if (studentNumber.size() == 0){
                cout << " There are no students" << endl;
                continue;
            }else{
                cout << "Number of student to input grades to: " << endl;
                cin >> i;
                if(dynamic_cast<Student*>(people.at(i-1)) == nullptr){
                    cout << "This is not a student" << endl;
                    cout << "Number of student to input grades to: " << endl;
                    cin >> i;
                }
            }
            cout << "Grade of the student [0.0 to 4.0 scale]: " << endl;
            cin >> GradeNo;
            while(cin.fail()){
                cin.clear();
                cin.ignore(255, '\n');
                cerr << "Incorrect input!" << endl;
                cout << "Grade of the student [0.0 to 4.0 scale]: " << endl;
                cin >> GradeNo;
            }
            while(GradeNo < 0.0 || GradeNo > 4.0){
                cout << "Invalid grade value, make sure [0.0, 4.0]" << endl;
                cout << "Grade of the student [0.0 to 4.0 scale]: " ;
                cin >> GradeNo;
            }
            cout << "Credits {1, 2, 3, 4, 5}: " << endl;
            cin >> CreditNo;
            while (CreditNo < 1 || CreditNo > 5){
                cout <<"Invalid input Please try again" << endl;
                cout << "Credits {1, 2, 3, 4, 5}: " << endl;
                cin >> CreditNo;
            }
            Student* student = dynamic_cast<Student*>(people.at(i-1));
            Grade = student->GetGPA();
            Credit = student->GetCredits();
            GradeNo = ((GradeNo + CreditNo) + (Grade + Credit)) / (Credit + CreditNo);
            student->_gpa = GradeNo;
            student->_credits += CreditNo;

            cout << "Grade added" << endl;
            cout <<endl;


		}else if (userOption == 11){	// Promote Professor
            size_t i = 0;
            vector<size_t> ProfessorNumber;
            for (Person* persons: people) {
                i++;
                if(dynamic_cast<Professor*>(persons) != nullptr) {
                    ProfessorNumber.push_back(i);
                    Professor *professor = dynamic_cast<Professor *>(persons);
                    cout << i << " " << professor->ToString() << endl;
                }
                cout << endl;
            }
            if (ProfessorNumber.size() == 0){
                cout << " There are no Professor" << endl;
                continue;
            }else{
                cout << "Number of professor to promote: " << endl;
                cin >> i;
            }
            Professor* professor = dynamic_cast<Professor*>(people.at(i-1));
         professor->Promote();

            cout << "Promotion added" << endl;
            cout <<endl;
		}else if (userOption == 12){	// Give Raise to Professor
            size_t i = 0;
            float raise;
            vector<size_t> ProfessorNumber;
            for (Person* persons: people) {
                i++;
                if(dynamic_cast<Professor*>(persons) != nullptr) {
                    ProfessorNumber.push_back(i);
                    Professor *professor = dynamic_cast<Professor *>(persons);
                    cout << i << " " << professor->ToString() << endl;
                }
                cout << endl;
            }
            if (ProfessorNumber.size() == 0){
                cout << " There are no Professor" << endl;
                continue;
            }else{
                cout << "Number of professor to give a raise: " << endl;
                cin >> i;
            }
            cout << "Raise to the professor [0.0, 50.0]" << endl;
            cin >> raise;
            while(raise < 0.0 || raise > 50.0 ){
                cout << "Raise out of range, Please try again" << endl;
                cout << "Raise to the professor [0.0, 50.0]" << endl;
                cin >> raise;
            }
            Professor* professor = dynamic_cast<Professor*>(people.at(i-1));

            professor->Raise(raise);

            cout << "Raise added" << endl;
            cout <<endl;
		}else if (userOption == 13){	// Load from File

		}else if (userOption == 14){	// Write to File

		}
	}
	return 0;
}

size_t Menu(){
	int option = 0;
	while(true){
		cout << "-------------------------------------------" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Add a Student" << endl;
		cout << "3. Add a Professor" << endl;
		cout << "4. List all People" << endl;
		cout << "5. Show Students Report" << endl;
		cout << "6. Show Professors Report" << endl;
		cout << "7. Show People (not Professors or Students)" << endl;
		cout << "8. Calculate all Students Average GPA" << endl;
		cout << "9. Calculate all Professors Average Salary" << endl;
		cout << "10. Input Grades to Student" << endl;
		cout << "11. Promote Professor" << endl;
		cout << "12. Give Raise to Professor" << endl;
		cout << "13. Load Data from File" << endl;
		cout << "14. Write Data to File" << endl;
		cout << "15. Exit" << endl;

		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Incorrect input!" << endl;
			continue;
		}
		if (option < 1 || option > 15){
			cerr << "Incorrect menu option!" << endl;
			continue;
		}
		break;
	}
	cout << endl;
	return static_cast<size_t>(option);
}
void DeletePerson(vector<Person*>& people){
        for (Person* p : people){
            delete p;
    }
}