#include "StudentDB.h"

bool StudentDB::empty() const{
	return IDmap.empty();
	//used only id's map because I will insert here first for a new student
	//then I will insert into nameMap
	//if this is empty, nameMap will also be empty
}

int StudentDB::size() const{
	return IDmap.size();
}

bool StudentDB::insert(const Student &stud){
	Student temp = stud;
	if(searchByID(stud.getID(), temp))//already there
		return false;
	else{
		pair <int, Student> IDpair;
		IDpair.first = stud.getID();
		IDpair.second = stud;
		IDmap.insert(IDpair);

		pair <string, int> namePair;
		namePair.first = stud.getWholeName();
		namePair.second = stud.getID();
		nameMap.insert(namePair);
	}
	return true;
}

bool StudentDB::searchByID(int id, Student&out) const{
	if(IDmap.find(id) == IDmap.end())//didn't find it
		return false;
	else//found it
		//set out = to student
		out = IDmap.at(id);

	return true;
}

bool StudentDB::searchByName(const string &name, Student &out) const{
	if(nameMap.find(name) == nameMap.end())
		return false;
	else{
		//need to connect it to the IDmap
		searchByID(nameMap.at(name), out);
	}
	return true;
}

bool StudentDB::removeByID(int id){
	Student myStudent;
	if(!searchByID(id, myStudent))//doesn't exist
		return false;
	else{
		//remove from both maps
		string temp = myStudent.getWholeName();
		nameMap.erase(temp);
		IDmap.erase(id);
	}
	return true;
}

bool StudentDB::removeByName(const string &name){
	Student myStudent;
	if(!searchByName(name, myStudent))
		return false;
	else{
		int temp = myStudent.getID();
		IDmap.erase(temp);
		nameMap.erase(name);
	}
	return true;
}
