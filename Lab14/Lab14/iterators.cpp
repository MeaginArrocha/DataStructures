#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

//******************place your printVec, printIts, and printContainer functions here

template <typename Item>
void printVec(Item const &vec){
	for(int unsigned i = 0; i < vec.size(); i++){ 
		cout << vec[i] << " ";
	}
	cout << endl;
}

template <typename any>
void printIts(any beg, any const &end){
	while(beg != end){
		cout << * beg << " ";
		beg++;
	}
	cout << endl;
	
}

template <typename contain>
void printContainer(contain con){
	typename contain::iterator co = con.begin();
	while(co != con.end()){
		cout << *co << " ";
		co++;
	}

	cout << endl;
}

void main () {
  vector<int> vec;
  for (int i=0; i<50; i+=10) vec.push_back(i);
  cout << "printVec:       ";//extra spacing just lines up output
  printVec(vec);//parameter of printVec is a vector of integers

  cout << "printIts(vec):  ";
  printIts(vec.begin(), vec.end());	  
    //printIts' parameters are two iterators over ANY item type in ANY container 
    //that supports (constant) forward iteration using STL style iterators

  list <int> ls(vec.begin(), vec.end());

//************************** list<int> ls ....something....
    //make a linked list named ls of ints with the same items as in the vector vec
    //for FULL credit you must do this in one line using a constructor from the list class
    //hint: use intellisense to your advantage
    //if you can't get it in one line, do a loop or something

  cout << "printIts(list): ";
  printIts(ls.begin(), ls.end());  //notes that printIts works for vectors and integers

  cout << "printContainer: ";
  printContainer(vec);
    //parameter is ANY container supporting (constant) forward iteration
    //using STL style iterators
  cout << "printContainer: ";
  printContainer(ls);

  cout <<endl;

  vector<string> strVec;
  char str[]="ABCDE";
  for (int i=0; i<5; i++) strVec.push_back(&str[i]);  //string has a contructor that will make a string from a char *
  cout << "printIts:       ";
  printIts(strVec.begin(), strVec.end());//printIts also works for strings
  cout << "printContainer: ";
  printContainer(strVec);
  
/*The next printIts should print A B C D E
It is treating the char array str as a container and passing 'iterators' to printIts*/
  cout <<endl;
  cout << "printIts(arr):  ";
  printIts(&str[0], &str[5]);
}

/*
This lab covers two main topics, templates and iterators.  Since it is using vector and list
from the STL you will get a little practice seeing their use as well.  

You are to write the printVec, printIts, and printContainer functions called from main() 
such that they work. The print functions simply iterate through printing each item
separated with spaces and an endl after printing all the items. The output should be the
same for each way of printing, for the integer containers the output is:
0 10 20 30 40 in that order.
For the string data the output is ABCDE BCDE CDE DE E
  (yes the above is corret, remember cout treats char arrays as C-strings?)

Note that the same printIts and printContainer are used for both list and vector over both 
int and string data.  printIts is even used on a char array.

For ***full*** credit, use const reference as much as possible for parameter passing and 
const iterators where possible.

If you are unable to get certain functions to work, comment out those calls in main such that 
your code does run w/o crashing. I should be able to execute your code as submitted w/o any 
changes. Put notes in comments in the iterators.cpp file to explain what doesn't work.  If 
you started a function but couldn't complete it, then note if it compiles and what it doesn't
do correctly.

Work on the functions in order: printVec, printIts, printContainer.
All functions return void.
All functions print items one at a time space separated with an endl after the last item.
  So you would have some form of a loop that prints each item followed by a space
  Then an endl after the loop.

  Parameters:
printVec  one vector over some type
printIts  a iterator-ish thing for the first item and another parameter just past the last item
    similar to how begin and end work
printContainer  a single parameter that is a container supporting iteration

Submit a single file, iterators.cpp with the included code plus your print functions.
You are NOT allowed to change the function calls to printVec, printIts or printContainer
(unless you need to comment them out b/c your code doesn't work)

When you start work on print vec, you will need to comment out calls to printIts, 
printContainer, and ls (the list) so that the code can compile.  Uncomment those as you 
start to work on them.

*/