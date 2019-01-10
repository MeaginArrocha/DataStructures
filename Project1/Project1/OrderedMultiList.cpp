#include "OrderedMultiList.h"
#include <iostream>

using namespace std;

OrderedMultiList::OrderedMultiList(){
	for(int i = 0; i < DEFAULT_MAX_ITEMS; i++){
		myArray[i].character = NULL;
		myArray[i].frequency = NULL;
	}
}

bool OrderedMultiList::empty(){
	if(myArray[0].character == NULL){
		return true;
	}
	return false;
}

int OrderedMultiList::uniqueSize(){
	int uniqueSize = 0;
	index = 0;
	while(myArray[index].character != NULL && myArray[index].character != DEFAULT_MAX_ITEMS){
		uniqueSize++;
		index++;
	}
	return uniqueSize;
}

int OrderedMultiList::size(){
	int size = 0;
	index = 0;
	while(myArray[index].character != NULL && myArray[index].character != DEFAULT_MAX_ITEMS){
		size = size + myArray[index].frequency; //adding the amount in that spot to the total
		index++;
	}
	return size; 
}

bool OrderedMultiList::find(char val){
	index = 0;
	while(myArray[index].character != NULL && myArray[index].character != DEFAULT_MAX_ITEMS){
		if(myArray[index].character == val){
			return true;
		}
			index++;
	}
	return false;
}

int OrderedMultiList::count(char val){
	bool temp = find(val);

	if(temp == true){
		return myArray[index].frequency;
	}

	return 0;
}

void OrderedMultiList::print(){
	index = 0;
	while(myArray[index].character != NULL && myArray[index].character != DEFAULT_MAX_ITEMS){
		cout << myArray[index].frequency << " " << myArray[index].character << endl;
		index++;
	}
}

bool OrderedMultiList::insert(char val){
	return insert(val, 1);
}

bool OrderedMultiList::insert(char val, int count){
	index = 0;
	while(index != DEFAULT_MAX_ITEMS){
		if(myArray[index].character == NULL){
			myArray[index].character = val;
			myArray[index].frequency = count;
			return true;
		}
		else if(myArray[index].character == val){
			myArray[index].frequency += count;
			return true;
		}
		else if(myArray[index].character > val){
			if(myArray[DEFAULT_MAX_ITEMS - 1].character != NULL){
				return false;
			}
			for(int i = DEFAULT_MAX_ITEMS -	1; i > index; i--){
				myArray[i].character = myArray[i - 1].character;
				myArray[i].frequency = myArray[i - 1].frequency;
			}
			myArray[index].character = val;
			myArray[index].frequency = count;
			return true;
		}
		index++;
	}
	return false;
}

bool OrderedMultiList::remove(char val){
	bool temp = find(val);
	if(temp == true){
		if(myArray[index].frequency = 1){
			myArray[index].character = NULL;
			myArray[index].frequency = NULL;
			for(int i = index; i < DEFAULT_MAX_ITEMS - 1; i++){
				myArray[i].character = myArray[i + 1].character;
				myArray[i].frequency = myArray[i + 1].frequency;
			}
		myArray[DEFAULT_MAX_ITEMS - 1].character = NULL;
		myArray[DEFAULT_MAX_ITEMS - 1].frequency = NULL;
		return true;
		}
		else{
			myArray[index].frequency -= 1;
			return true;
		}
	}
	return false;
}

/*int OrderedMultiList::removeAll(char val){
	int itemsRemoved = 0;
	int itemCount = count(val);
	if(find(val) == true){
		for(int i = 0; i < itemCount; i++){
			myArray[i].frequency -= 1;
			itemsRemoved ++;
		}
		myArray[index].character = NULL;
		myArray[index].frequency = NULL;
		for(int i = index; i < DEFAULT_MAX_ITEMS - 1; i++){
			myArray[i].character = myArray[i + 1].character;
			myArray[i].frequency = myArray[i + 1].frequency;
		}
		myArray[DEFAULT_MAX_ITEMS - 1].character = NULL;
		myArray[DEFAULT_MAX_ITEMS - 1].frequency = NULL;
	}


	return itemsRemoved;
}*/