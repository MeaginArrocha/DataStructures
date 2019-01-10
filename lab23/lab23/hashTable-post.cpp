
#include <vector>
#include <list>
#include <iostream>
#include <string>
using namespace std;

class HashTable {
public:
	HashTable(int arraySize);  //arraySize is initial size of the underlying array itself
	//this means your internal array will be dynamic.
	//Some usable prime numbers for your array size (from http://primes.utm.edu/lists/small/10000.txt):
	// 11 101 503 1009 5003 7717 12829 17929  51539 
	// Basically, round up arraySize to the next prime

	~HashTable();  //since array is dynamic, this is needed.
	void insert(const string &val); //allows duplicates
	bool search(const string &val) const; //return true iff found
	bool remove(const string &val); //return true iff found, remove if found, 
	//if multiple instances exist, remove any 1 of them
	bool empty() const ; //return true iff no items in hash
private:
	//name your hash function hash or h, you may assume input is 
	//suitably random and use simple hash functions
	//array goes here together with whatever else you want/need

	
	vector <string> * hashArr;

	int hash(string input) const;

};

HashTable::HashTable(int arraySize){
	int primeSize[] = {11, 101, 503, 1009, 5003, 7717, 12829, 17929, 51539};
	int index = 0;
	 while(index != 9 && arraySize > primeSize[index])
		 index++;

	arraySize = primeSize[index];
	hashArr = new vector <string> [arraySize];

}

HashTable::~HashTable(){
	delete [] hashArr;
}

int HashTable::hash(string input) const{
	int ascTotal = 0;
	ascTotal = input[0] * input[input.length() - 1] * input[(input.length() - 1) / 2];
	ascTotal = ascTotal % sizeof(hashArr);

	return ascTotal;
}

void HashTable::insert(const string &val){
	int index = hash(val);
	hashArr[index].push_back(val);
}

bool HashTable::search(const string &val)const{
	int index = hash(val);

	vector <string> :: iterator it;
	for(it = hashArr[index].begin(); it != hashArr[index].end(); it++){
		if(val == *it)
			return true;
	}

	return false;
}

bool HashTable::remove(const string &val){
	bool isThere = search(val);
	if(isThere){
		int index = hash(val);
		vector <string> :: iterator it;
		for(it = hashArr[index].begin(); it != hashArr[index].end(); it++){
			if(*it == val){
				*it = hashArr[index].back();
				hashArr[index].pop_back();
				return true;
			}	
		}
	}

	return false;
}

bool HashTable::empty()const{
	return hashArr -> empty();
}

void main () {
	//create a HashTable then insert, search, and remove strings to test it.

	HashTable hash(10);
	cout << "Empty: " <<  hash.empty() <<endl; //return true
	cout << endl;

	hash.insert("hello");

	cout << "Search:" << endl;
	cout << hash.search("hello") << endl; // return true;
	cout << hash.search("Meagin")<< endl; //return false;
	hash.insert("Meagin");
	cout << hash.search("Meagin")<< endl; //return true;
	cout << hash.search("meagin")<< endl; //return false;

	cout << "Empty: " << hash.empty() << endl; //return false;

	cout << endl;

	cout << "Remove:" << endl;
	cout << hash.remove("bob") << endl;//return false;
	cout << hash.remove("Meagin")<< endl;//return true;
	

	cout << "empty: " << hash.empty() << endl;//return false;
	cout << hash.remove("hello") << endl;//return true;

	cout << "empty: " << hash.empty() << endl;//return true;

}