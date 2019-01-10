#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;
class Student {
public:
	Student(int i=0, string n="", double g=0) :id(i), wholeName(n), gpa(g) {}
	int getID() const {return id;}
	string getWholeName() const {return wholeName;}
	double getGPA() const {return gpa;}
	void setGPA(double g) {gpa=g;}
	Student(const Student&src) {copy(src); }
	Student& operator=(const Student &src);
	void copy (const Student &src);
private:
	int id;
	string wholeName;
	double gpa;
	char data[10000];  //other data not important to us, but it does take up space
};

ostream &operator <<(ostream &out, Student &src);

#endif