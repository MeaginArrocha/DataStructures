const int DEFAULT_MAX_ITEMS=20;

class OrderedMultiList {
public:
	//Constructors/destructors

	OrderedMultiList();	//creates an empty list capable of storing 
		//DEFAULT_MAX_ITEMS unique items
	//~OrderedMultiList();	//destructor ONLY if needed
		
	//accessors
	bool empty();		//returns true iff (if and only if) list is empty
	int uniqueSize();	//returns the number of distinct items in the list
	int size();		//returns the total number of items in the list
		//If A, J, C, J, J, and J are inserted into an OrderedMultiList oml then 
		//oml.uniqueSize() would return 3 and oml.size() would return 6.
	bool find(char val);   	//returns true iff the list contains val 
	int count (char val);	//returns number of times val is in the list
	void print();		//prints out the content of the list in order, see below

	//mutators
	bool insert(char val);	//inserts item val into the list (in order), 
		//returns true iff val was able to fit in list
	bool insert(char val, int count);	//inserts item val count number of times
		//returns false if count less than 1 or if val would not fit
		//returns true if val was able to fit, note that if 1 val fits, they will all fit
	bool remove(char val);	//removes 1 instance of val from list
		//returns true iff val was in list
	int removeAll(char val); //removes all instances of val from list
		//returns number of items removed, which could be 0
private:
		//put whatever methods or data you need in here, you must put the
		//1-dimensional array here

	struct arrayTypes{
		char character;
		int frequency;
	}; //used so myArray can have both and int & and char in the same index

	struct arrayTypes myArray[DEFAULT_MAX_ITEMS];

	int index;

};	