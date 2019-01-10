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


void LList::printReverse() const{
	Node * cur = tail;
	while(cur != NULL){
		cout << cur -> data << endl;
		cur = cur -> prev;
	}

}

bool LList::remove(int val){
	if(head == NULL) //empty
		return false;
	if(head -> data == val){ //beg
		Node * killMePlease = head;
		head = head -> next;
		head -> prev = NULL;
		delete killMePlease;
		return true;
		}
	if(tail -> data == val){
		Node * killMeNow = tail;
		tail = tail -> prev;
		tail -> next = NULL;
		delete killMeNow;
		return true;
	}
	Node * cur = tail;
	while ( cur != NULL && cur -> data != val){
		cur = cur -> prev;
	}
	if(cur == NULL)
		return false;
	Node * killMe = cur; //mid
	cur -> next -> prev = cur -> prev;
	cur -> prev -> next = cur -> next;
	delete killMe;
	return true;
}


void main(){
	LList list; 
	cout << list.remove(8) << endl; //prints 0
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(3);
	list.insert(7);
	list.printReverse();
	cout << endl;

	cout << list.remove(5) << endl;
	list.printReverse();
	cout << endl;

	cout << list.remove(3) << endl;
	list.printReverse();
	cout << endl;

	cout << list.remove(7) << endl;
	list.printReverse();

}