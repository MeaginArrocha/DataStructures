#ifndef STUDENTDB_H
#define STUDENTDB_H
#include <string>
using namespace std;
#include "Student.h"
#include <map>

class StudentDB {
public:
	StudentDB(){}
	//~StudentDB(); //if needed

	bool empty() const;
	int size() const;  //returns number of students in DB

	bool insert(const Student &stud);//return false if stud already in DB

	//each of the below returns true if found and false if not
	//out is changed to the correct Student if it is found
	bool searchByID(int id, Student &out) const;
	bool searchByName(const string &name, Student &out) const;

	bool removeByID(int id);
	bool removeByName(const string &name);

	//the below methods are extra credit, they change the GPA of a student in the DB
	//bool updateGPAByID(int id, double gpa);
	//bool updateGPAByName(const string &name, double gpa);

private:
	//your data structureS go here, there will be more than 1
	
	map <int, Student> IDmap;//has student record in it
	map <string, int> nameMap;//if searched by name, can find id then find student record
	//done instead of storing student record twice

};

#endif