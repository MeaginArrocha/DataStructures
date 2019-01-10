#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Student& Student::operator=(const Student &src) {
	if (this != &src) {
		copy (src);
	}
	return *this;
}
void Student::copy (const Student &src) {
	id=src.id;
	wholeName=src.wholeName;
	gpa=src.gpa;
	for (int i=0; i<10000; i++) data[i] = src.data[i];
}

ostream &operator <<(ostream &out, Student &src){//ID=name(GPA)
	out << src.getID() << "-" << src.getWholeName() << "(" << src.getGPA() << ")";
	return out;
}