#include <string>
#include <iostream>
using namespace std;

#include "Student.h"
#include "StudentDB.h"

void main() {//This is clearly not sufficient testing, just a start
	Student stud(1234, "GaryUnderwood", 3.5);
	Student stud2(2468, "JanetUnderwood", 3.7);
	Student test, test2;
	StudentDB db;
	cout << db.empty() << " " << db.size() << endl;
	cout << db.insert(stud) << endl;
	cout << db.insert(stud2) << endl;
	cout << db.empty() << " " << db.size() << endl;

	cout << db.searchByID(1234, test) << " " << db.searchByName("GaryUnderwood", test2) << endl;
	cout << test << endl;
	cout << test2<< endl;
	
	cout << db.searchByID(13234, test) << " " << db.searchByName("Underwood",test2) << endl;//should fail

	cout << db.removeByID(1234) <<endl;
	cout << db.removeByName("JanetUnderwood") << endl;

	//these should now fail
	cout << db.searchByID(1234, test) << " " << db.searchByName("GaryUnderwood", test2) << endl;
	cout << db.searchByID(2468, test) << " " << db.searchByName("JanetUnderwood", test2) << endl;

	cout << db.empty() << " " << db.size() << endl;//true and 0
}