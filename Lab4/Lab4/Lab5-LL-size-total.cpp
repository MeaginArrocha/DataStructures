//Implement the size and total methods of LList
#include <iostream>

using namespace std;

class LList {
public:
  LList() {head=0;}
  void insert(int val) {// always add to the beginning, ignoring memory issues
	Node * newGuy = new Node;
    newGuy->data = val;
    newGuy->next = head;
    head = newGuy;
  }
  int size() const{ //returns number of Nodes in LList
	  int nodeCount = 0; //keeps track of number of Nodes
	  Node * cur = head; //starts from the beginning
	  while(cur != NULL){
		  nodeCount ++;
		  cur = cur -> next;
	  }
	  return nodeCount;

  }
  int total() const{ //returns sum of all the integers in the LList
	  int sum = 0;
	  Node * cur = head;
	  while( cur != NULL){
		  sum = sum + cur -> data;
		  cur = cur -> next;
	  }
	  return sum;
  }
private:
  struct Node {
	
	int data;
	Node *next;
  };
  Node * head;
};


void main () {
    LList test;
    cout << test.size() << endl;  //should print 0 since there are 0 nodes (it is empty)
    cout << test.total() << endl;  //should print 0 since the sum of all the values (all none of them) is 0
    test.insert(5);
    test.insert(8);
    test.insert(23);
    test.insert(-6);
    cout << test.size() << endl;  //should print 4 since there are 4 nodes
    cout << test.total() << endl;  //should print 30 since 5 + 8 + 23 + -6 is 30
}