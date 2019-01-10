
#include <iostream>
using namespace std;

template <typename ItemType>
class BST {//unbalanced binary search tree, no duplicates allowed, templated
public:
  BST() {root=0;}//empty tree


  bool empty() const {return (root==0);} //return true iff no nodes

  bool insert (ItemType val) { //insert val into a correct spot, return false if duplicate or out of memory
	if (empty()) {//special case since root must change
	  root=new Node(val);
	  return (root != 0); //return true if root is not NULL, NULL if no memory
	}
	return insert(val, root);
  }


  bool search (ItemType val) const{	//return true iff val found in tree
	return search(val, root);
  }

  bool remove (ItemType val) { //remove val, return true iff val found in tree
	if (empty()) return false;//depending on your implementation of remove, this may not be needed
	return remove(val, root, root); //remove this line and use something appropriate for the next line instead
	//return remove(val, ????);	//choice of number of parameters is up to you
  }

  //print values in order separated by spaces
  void traverseInOrderPrint() const {traverseInOrderPrint(root);}
  
private:
  struct Node {//constructor provided for simplicity of insert
	Node (ItemType d) : data(d), lChild(0), rChild(0) {}
	ItemType data;
	Node *lChild, *rChild;
  };
  Node * root;

  //below are recursive helpers for public methods with the same name
  bool insert (ItemType val, Node* &cur) {//note pass by reference, this is critical
	if (cur == 0) {//fell off tree, so new Node goes here
	  cur= new Node(val);//since this is pass by reference, parent's child pointer will be changed
	  return (cur !=0);
	}
	if (cur->data==val)  return false;
	if (val < cur->data) return insert(val, cur->lChild);
	else				 return insert(val, cur->rChild);
  }

  bool search (ItemType val, Node *cur) const {
	if (cur==0)			  return false;
	if (cur->data == val) return true;
	if (val < cur->data)  return search(val, cur->lChild);//val smaller so we go left
	else				  return search(val, cur->rChild);
  }

  void traverseInOrderPrint(Node *cur) const {
  //this should be about 4-6 lines, if it is more, think harder or talk to me
	  if(cur == NULL) return;
	  traverseInOrderPrint (cur -> lChild);
	  cout << cur -> data << " ";
	  traverseInOrderPrint (cur -> rChild);
  }

  bool remove (ItemType val, Node * &cur, Node * &parent){
	  if(cur == NULL)
		  return false;

	  if(cur -> data < val){ // val is on left
		 return remove(val, cur -> rChild, cur);
	  }
	  else if(cur -> data > val){ // val is on right
		 return remove(val, cur -> lChild, cur);
	  }
	  if(cur -> data == val){ //found val
		  if(cur -> lChild != NULL && cur -> rChild != NULL){
			 Node * end = cur -> lChild;
			 while(end -> rChild != NULL){
				end = end -> rChild;
			 }
			 if(cur -> lChild != end){
				 parent = cur -> lChild;
				 while(parent -> rChild != end)
					 parent = parent -> rChild;
			 }
			 else
				 parent = cur;

			 ItemType temp = end -> data;
			 end -> data = cur -> data;
			 cur -> data = temp;
			 cur = end;

		  }
		  if(cur -> lChild == NULL && cur -> rChild != NULL){// has one child (right)
			  if(parent -> rChild != NULL && val == parent -> rChild -> data)
				 parent -> rChild = cur -> rChild;
			  else if(parent -> lChild != NULL && val == parent -> lChild -> data)
				 parent -> lChild = cur -> rChild;
			  delete cur;
			  return true;
		  }
		  else if(cur ->lChild != NULL && cur -> rChild == NULL){ // has one child (left)
			  if(parent -> lChild != NULL && val == parent -> lChild -> data)
				parent -> lChild = cur -> lChild;
			  else if(parent -> rChild != NULL && val == parent -> rChild -> data)
				parent -> rChild = cur -> lChild;
			  delete cur;
			  return true;
		  }
		  else if(cur -> lChild == NULL && cur -> rChild == NULL){ // has no children
			  if(cur == root)
				  root = NULL;
			  if(parent -> rChild != NULL && val == parent -> lChild -> data)
				  parent -> rChild = NULL;
			  else if(parent -> lChild != NULL && val == parent -> lChild -> data)
				  parent -> lChild = NULL;
			  delete cur;
			  return true;
		  }
	
	  }
	  
  }

};

void main() {
  BST<int> tree;//your test code would go here
  int arr[] = {10, 5, 3, 4, 8, 9, 17, 14, 13, 25, 20, 29, 32};
  for (int i=0; i< 13; i++) tree.insert(arr[i]);
  tree.traverseInOrderPrint();//should get 3 4 5 8 9 10 13 14 17 20 25 29 32
  //now remove various nodes and make sure the resulting tree is correct
  //be sure to test removing nodes with 0, 1, and 2 children and the root special cases

  cout << endl;
  cout << tree.remove(1) << endl;//prints false
  cout << tree.remove(3) << endl;
  tree.traverseInOrderPrint();

  //cout << tree.remove(5) << endl;
 // tree.traverseInOrderPrint();
}