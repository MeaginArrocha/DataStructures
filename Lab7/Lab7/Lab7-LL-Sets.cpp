#include <iostream>
using namespace std;

class LList {
public:
  LList() {head=0;}
  void insert(int val) {// always add to the beginning, ignoring memory issues
	head=new Node(val, head);
  }
  void print () const {
	Node * cur = head;
	while (cur) {
	  cout << cur->data << " ";
	  cur = cur->next;
	}
	cout << endl;
  }
  bool find(int val) const {
	Node * cur = head;
	while (cur && cur->data != val) 
	    cur = cur->next;
	return (cur != NULL) ;
  }
  void listIntersection(const LList &first, const LList &second);
	/*'this' should have the values that are in both first and second
	you may assume first and second have no duplicates
	resulting list should have no duplicates*/

  void listUnion(const LList &first, const LList &second);
	/*'this' should have the values that are in either first or second
	you may assume first and second have no duplicates
	resulting list should have no duplicates*/

  /*LList& operator = (const LList& src){
	Node * cur = head;
	Node * srcCur = src.head;
	while(srcCur != NULL){
		cur ->data = srcCur -> data;
		cur = cur -> next;
		srcCur = srcCur -> next;
	}
	return *this;
  }*/
  

private:
  struct Node {
	Node(int d, Node *n=0) { data=d; next=n;}//constructor
	int data;
	Node *next;
  };
  Node * head;

};


void LList::listIntersection(const LList &first, const LList &second){
	Node * cur = head;
	Node * curFirst = first.head;
	Node * curSecond = second.head;
	int count = 0;

	/*while(cur -> next != NULL){
		Node * killMe = cur ->next;
		cur = cur -> next -> next;
		delete killMe;
	}*/

	while(curFirst != NULL){
		while(curSecond != NULL){				
			if(curFirst -> data == curSecond -> data){
				insert(curFirst -> data);
				count++;
				//cur -> data = curFirst -> data;
				//cur = cur -> next;
			}
			curSecond = curSecond -> next;
		}
		curFirst = curFirst -> next;
		curSecond = second.head;
	}

	/*while( count != 0){
		cur = cur -> next;
	}
	while( cur -> next != NULL){
		Node * killMe = cur;
		while(killMe -> next != NULL){
			killMe = killMe -> next;
		}
		//if(killMe -> next == NULL){
			delete killMe;
		//}
	}*/



	/*while(count != 0){
		Node * killMe = cur;
		killMe = killMe + count;
		delete killMe;
		count --;
	}*/
}

void LList::listUnion(const LList &first, const LList &second){
	Node * cur = head;
	Node * curFirst = first.head;
	Node * curSecond = second.head;

	while(curFirst != NULL){
		insert(curFirst -> data);
	}
	while(curSecond != NULL){
		if(! find(cur ->data)){
			insert(cur -> data);
		}
	}
}


//sample tests, not sufficient for full testing, watch out for aliasing
void main () {
  LList list1, list2, list3, list4;
  for (int i=0; i< 7; i++) list1.insert(i);
  for (int i=0; i< 9; i+=2) list2.insert(i);
  for (int i=0; i< 15; i+=3) list3.insert(i);
  cout <<"list 1: ";
  list1.print();
  cout <<"list 2: ";
  list2.print();
  cout <<"list 3: ";
  list3.print();
  list4=list3;
  cout <<"list 4 (=list3): ";
  list4.print();
  /*LList list5(list2);
  cout <<"list 5 (CC of list2): ";
  list5.print();*/
  LList list6, list7;
  list6.listIntersection (list1, list2);
  cout <<"list 6 (list 1 Int list 2): ";
  list6.print();
  list4.listIntersection (list1, list2);
  cout <<"list 4 (list 1 Int list 2): ";
  list4.print();
  /*list7.listUnion(list1, list2);
  cout << "list 7 (list 1 Int list 2):";
  list7.print();*/
  /*list3.listIntersection (list3, list2);
  cout <<"list 3 (list 3 Int list 2): ";
  list3.print();
  list3.listUnion(list1, list3);
  cout <<"list 3 (list 3 union list 1): ";
  list3.print();*/
}