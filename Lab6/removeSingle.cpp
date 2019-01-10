class LList {
public:
  LList() :head(0), tail(0) {}  //same as head=tail=0;  same as head=tail=NULL;
  ~LList() {//works for both #1 and #2
 	Node * cur=head;
	while (cur) {
	  cur=cur->next;
	  delete head;
	  head=cur;
	}
  }
  void insert(int val) {// always add to the end, ignoring memory issues, for #1
    if (!head) {
	head=new Node (val);	//empty list, new head
    }
    else {
	Node * cur=head;
	while (cur->next) cur=cur->next;
	cur->next=new Node(val);
    }
  }
/*
  void insert(int val) {// always add to the end, ignoring memory issues, for #2
    if (!tail) {
	head=tail=new Node(val);	//new first element is both head and tail
    }
    else {
	tail->next=new Node(val, 0, tail);//new tail, its prev is old tail, no next
	tail=tail->next;
    }
  }
 
  //this prints the values in reverse starting with the last value, for #2 only
  void printReverse() const;

*/
  bool remove(int val);		//return true iff val was found

private:
  struct Node {
	Node(int d, Node *n=0, Node *p=0) : data(d), next(n), prev(p) {}
 	int data;
	Node *next, *prev;
  };
  Node * head, *tail;
};

#include <iostream>

using namespace std;

bool LList::remove(int val) {
//below is an optional line, depends on what you do later if it will be needed
	if (head == NULL){
		return false;
	}
	if(head -> data == val){
		Node * killMe =  head;
		head  = head -> next;
		delete killMe;
		return true;
	}
	Node * current= head;
	while (current -> next != NULL && current -> next -> data != val) {
		current = current -> next;
 	}
	if(current -> next == NULL)
		return false;
	Node * killMe = current -> next;
	current -> next = killMe -> next;

	delete killMe;
	return true;
}


void main(){
	LList list;
	cout << list.remove(8) << endl; // print 0
	list.insert(9);
	list.insert(4);
	list.insert(7);
	list.insert(3);
	list.insert(4);
	cout << list.remove(3) << endl; // print 1
	cout << list.remove(4) << endl; // print 1
	cout << list.remove(9) << endl; // print 1
	cout << list.remove(4) << endl; // print 1
	cout << list.remove(4) << endl; // print 0
}