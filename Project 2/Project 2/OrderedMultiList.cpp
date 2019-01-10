#include "OrderedMultiList.h"
#include <iostream>

using namespace std;

OrderedMultiList::OrderedMultiList(){
	head = NULL;
}

OrderedMultiList::~OrderedMultiList(){
	Node * cur = head;
	while(cur != NULL){
		Node * killMe = cur;
		cur = cur -> next;
		delete killMe;

	}
	head == NULL;
}

bool OrderedMultiList::empty() const{
	if(head == NULL)//if head is null, list is empty
		return true;
	return false;
}

int OrderedMultiList::uniqueSize() const{
	Node * cur = head;
	if(empty())
		return -1;
	int size = 0;
	while(cur != NULL){
		size ++;
		cur = cur -> next;
	}
	return size;
}

int OrderedMultiList::size() const{
	Node * cur = head;
	int size = 0;
	if(empty())
		return -1;
	while(cur != NULL){
		size = size + cur -> count;
		cur = cur -> next;
	}
	return size;
}

bool OrderedMultiList::find(int val) const{//so you don't make a new node of the same val
	Node * cur = head;
	if(empty()){
		return false;
	}
	while(cur != NULL){
		if(cur -> data == val)//finding repeats
			return true;
		cur = cur -> next;
	}
	return false;
}

int OrderedMultiList::count(int val) const{
	Node * cur = head;
	if(find(val)){
		while(cur -> data != val){
			cur = cur -> next;
		}
		return cur -> count;
	}
	return 0;
}

void OrderedMultiList::print() const{
	Node * cur = head;
	while(cur != NULL){
		cout << cur -> count << " " << cur ->data << endl;;
		cur = cur -> next;
	}
}

bool OrderedMultiList::insert(int val){
	if(insert(val, 1))
		return true;

	return false;
}

bool OrderedMultiList::insert(int val, int count){
	if(count <= 0){
		cout << "you gave me an invalid count for val " << val << endl;
		return false;
	}
	Node * cur = head;
	bool isEmpty = empty();//if list is empty
	if(isEmpty){
		head = new Node (val, count, NULL);
		if(head == NULL){
			cout << " out of memory" << endl;
			return false;
		}
		return true;
	}
	if(find(val)){
		while(cur -> data != val)//finding spot in list
			cur = cur -> next;
		cur -> count = cur -> count + count; //increments frequency
		return true;
	}
	if(val < head -> data){//if val is < the head
		head = new Node (val, count, head);
		if(head == NULL){
			cout << "out of memory" << endl;
			return false;
		}
		return true;
	}
	Node * temp;
	while(cur -> next != NULL && val > cur -> next -> data ){//to check for > and move cur
		cur = cur -> next;
	}
	if(cur -> next == NULL){//if its greater than all of the vals
		temp = new Node (val, count, NULL);
		if(temp == NULL){
			cout << " out of memory" << endl;
			return false;
		}
		cur -> next = temp;
		return true;
	}
	if(val < cur -> next -> data){//if its in between vals
		temp = new Node (val, count, cur -> next);
		if(temp == NULL){
			cout << "out of memory" << endl;
			return false;
		}
		cur -> next = temp;
		return true;
	}
	return false;
}

bool OrderedMultiList::remove(int val){
	Node * cur = head;
	if(find(val)){
		while(cur != NULL && cur -> data != val){
			cur = cur -> next;
		}
		if(cur -> data == val){
			if( cur -> count == 1){
				removeAll(val);
				return true;
			}
		cur -> count--;
		return true;
		}

	}
	return false;
}

int OrderedMultiList::removeAll(int val){
	int countTemp = 0;
	Node * cur = head;
	if(find(val)){
		if(val == head -> data){
			countTemp = head -> count;
			Node * killMe = head;
			head = head -> next;
			delete killMe;
			return countTemp;

		}
		while(cur -> next -> data != val){
			cur = cur -> next;
		}
		if(cur -> next -> data == val){
			countTemp = cur -> next -> count;
			Node * killMe = cur -> next;
			cur -> next = cur -> next -> next;
			delete killMe;
		}
		return countTemp;
	}
	
	return 0;
}
