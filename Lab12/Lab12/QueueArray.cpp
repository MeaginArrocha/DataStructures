#include <iostream>

using namespace std;

typedef int ItemType;

class QueueArr {
public:
 QueueArr(int max);	//creates an empty queue capable of holding max items
 ~QueueArr();
bool empty() const;		//return true iff queue is empty

//The next three return true iff item exists, i.e. the queue isn’t empty
bool front(ItemType &output) const;	//output set to first ‘front’ (oldest) item, 
bool back(ItemType &output) const;	//like front but for most recent item
bool pop();				//remove item from ‘front’ of queue

bool push (ItemType val);		//add val to ‘back’ of queue, 
//return true iff there is enough room in the array 
private:
//declare your dynamic array and any private members you would like.
	ItemType * array;
	int size, fro, bac, count;
};

QueueArr::QueueArr(int max){
	array = new ItemType[max];
	size = max;
	count = 0;
	fro = 0;
	bac = -1;
}

QueueArr::~QueueArr(){
	delete [] array;
}

bool QueueArr::empty() const{
	if(count ==  0)
		return true;
	return false;
}

bool QueueArr::front(ItemType &output) const{
	if(empty()) //doesn't exist
		return false;
	output = array[fro];
	return true;
}

bool QueueArr::back(ItemType &output) const{
	if(empty())
		return false;
	output = array[bac];
	return true;
}

bool QueueArr::push(ItemType val){
	if(count == size)
		return false;
	if(empty()){
		bac = -1;
		fro = 0;
	}
	bac = (bac+1) % size;
	array[bac] = val;
	count++;
	return true;
}

bool QueueArr::pop(){
	if(empty())
		return false;
	if(count == 1){
		bac = -1;
		fro = 0;
		count = 0;
		cout << "this is count" << count << endl;
		return true;
	}
	fro = (fro + 1) % size;
	count--;
	cout << "this is count" << count << endl;
	return true;
}

void main(){
	QueueArr test(5);
	ItemType o;
	cout << test.empty() << endl; // returns true
	cout << test.push(2) << endl; // returns true
	cout << test.front(o) << endl; //returns true
	cout << o << endl; //prints 2
	cout << test.back(o) << endl; // returns true
	cout << o << endl;
	cout << test.push(3) << endl;
	cout << test.push(4) << endl;
	cout << test.push(5) << endl;
	cout << test.push(6) << endl;
	cout << test.push(7) << endl; //returns false; no more room
	cout << test.empty() << endl; //retuns false
	cout << endl;

	test.front(o);
	cout << o << endl; //returns 2
	cout << test.pop() << endl; //prints true
	test.front(o);
	cout << o << endl; //returns 3
	cout<< test.pop() << endl; //prints true
	test.front(o);
	cout << o << endl; //returns 4
	cout<< test.pop() << endl; //prints true
	test.front(o);
	cout << o << endl; //returns 5
	cout<< test.pop() << endl; //prints true
	test.front(o);
	cout << o << endl; //returns 6
	cout<< test.pop() << endl; //prints true
	cout << endl;

	cout << test.front(o) << endl; //returns false
	cout << test.back(o) << endl; //returns false




}