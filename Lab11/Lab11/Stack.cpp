#include <iostream>

using namespace std;

typedef  int ItemType;
class Stack {
public:
  Stack();	
  ~Stack();		//clean up dynamic memory
  bool empty() const;	//return true iff stack has no elements
  bool top(ItemType &output) const;//return true iff there is a top item
  bool push(const ItemType &item); //return true iff push succeeds
  bool pop(); 		//return true iff there is an item to pop
private:
	struct Node{
		Node(ItemType, Node * n = 0) {ItemType; next = n;}
		int ItemType;
		Node * next;
	};
	Node * head;
};

Stack::Stack(){
	head = NULL;
}

Stack::~Stack(){
	while(head != NULL){
		Node * killMe = head;
		head = head -> next;
		delete killMe;
	}
}

bool Stack::empty() const{
	if(head == NULL) //list will be empty
		return true;
	
	return false;
}

bool Stack::top(ItemType &output) const{ //why takes a parameter???????
	if(empty()) //if empty there is no top
		return false;
	
	return true;
}

bool Stack::push(const ItemType  &item){
	if(head == NULL){
		head = new Node(item, NULL);
		if(head == NULL) //b/c wasn't added = no memory
			return false;
		return true;
	}
	head = new Node(item, head);
	if(head == NULL) //becuase it wasn't added = no memory
		return false; 
	return true;
}

bool Stack::pop(){
	if(empty()) //nothing to pop off
		return false;

	Node * killMe = head;
	head = head -> next;
	delete killMe;
	return true;
}

void main(){
	Stack myStack;
	int x;
	cout << myStack.empty() << endl; //returns true
	cout << myStack.pop() << endl; //returns false no item to pop
	cout << myStack.top(x) << endl; //returns false no item for top
	cout << myStack.push(3) <<endl; //returns true item on stack now
	cout << endl;

	cout << myStack.empty() << endl; // returns false not empty
	cout << myStack.top(x) << endl; //returns true x is now 3
	cout << myStack.pop() << endl; //returns true
	cout << myStack.empty() << endl; // returns true
	cout << endl;

	for( int i = 0; i < 5; i ++)
		cout << myStack.push(i) <<endl; //should all return true
	cout << endl;

	cout << myStack.empty() << endl; //returns false
	cout << myStack.top(x) << endl; //returns true x is now 4
	cout << endl;

	for( int j = 5; j > 0; j --)
		cout <<  myStack.pop() << endl; //returns true for all
	cout << endl;

	cout << myStack.pop() << endl; // returns false
	cout << myStack.empty() << endl; //returns true



}
