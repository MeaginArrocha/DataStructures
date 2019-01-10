#include "OrderedMultiList.h"
#include <iostream>

using namespace std;

void main(){
	OrderedMultiList oml;
	//cout << oml.empty() <<endl; //prints true (meaning 1)
	oml.insert('A');
	//cout << oml.empty() <<endl; //prints false (meanging 0)
	oml.insert('A'); //prints 2 A's
	oml.insert('B');
	oml.insert('a');
	oml.insert('&'); //inserts at the beginning, shifts chars. and freques.
	//oml.print();

	/*cout << oml.size() << endl;
	cout << oml.uniqueSize() << endl;

	cout << oml.find('A') << endl; //print true/1
	cout << oml.find('C') << endl; //print false/0
	cout << oml.count('A') << endl; //print 2
	cout << oml.count('C') << endl; //print 0
	cout << oml.count('&') << endl; //print 1
	*/
	oml.insert('D' , 2);
	/*oml.print();
	cout << endl;
	cout << oml.remove('B') << endl; //prints 1 & removes B
	cout << oml.remove('3') << endl; //prints 0
	oml.print();*/

	oml.insert('7', 5);
	oml.insert('*');
	oml.insert('t');
	oml.insert('U');
	oml.insert('0');
	oml.insert('?', 4);
	oml.insert('-');
	oml.insert('9');
	oml.insert('N', 6);
	oml.insert('M');
	oml.insert('O' , 9);
	oml.insert('P');
	oml.insert('Q' , 100);
	oml.insert('r');
	oml.insert('s' , 50);
	oml.insert('y'); //20th unique
	oml.insert('z'); //doesn't add anything

	//oml.print();
	cout << oml.size() << endl;
	cout << oml.uniqueSize() << endl;

	cout << oml.remove('z') << endl; //prints 0
	oml.remove('y');
	oml.insert('z');
	oml.print();
}
