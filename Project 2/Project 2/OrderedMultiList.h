class OrderedMultiList {
public:
	//Constructors/destructors, no copy constructor/= required
	OrderedMultiList();	//creates an empty list 
	~OrderedMultiList();	//destructor will be needed
		
	//accessors
	bool empty() const ;		//returns true iff (if and only if) list is empty
	int uniqueSize() const ;	//returns the number of distinct items in the list
	int size() const ;		//returns the total number of items in the list
//If 1, 10, 3, 10, 10, and 10 are inserted into an OrderedMultiList oml then //oml.uniqueSize() would return 3 and oml.size() would return 6.
	bool find(int val) const;   	//returns true iff the list contains val 
	int count (int val) const;	//returns number of times val is in the list
	void print() const ;		//prints out the content of the list in order, see below

	//mutators
	bool insert(int val);	//inserts item val into the list (in order), 
//returns true iff val was able to fit in list, the only reason it //returns false is if there is no more memory
	bool insert(int val, int count);	//inserts item val count number of times
//returns false if count less than 1 or if there is no more memory
	bool remove(int val);	//removes 1 instance of val from list
			//returns true iff val was in list
	int removeAll(int val); //removes all instances of val from list
			//returns number of items removed, which could be 0
private:
//Put node definition here, you may add any private methods you want.
	struct Node{
		Node(int d, int c, Node*n = 0):data(d), count(c),next(n){}
		int data, count;
		Node * next;
	};
	Node * head;
	Node * cur;
	Node * temp;
};
