
#include <iostream>
#include <string>
using namespace std;


int findPerms(string leftToDo, string soFar){//sofar = done
//left to do is empty = done
	int count = 0;

	for(unsigned int i = 0; i < leftToDo.length(); i ++) 
		count += findPerms(leftToDo.substr(0, i) + leftToDo.substr(i+1, leftToDo.length()-(i+1)), soFar + leftToDo.substr(i, 1));
	
	if(leftToDo.empty()){
		cout << leftToDo + soFar << endl;
		count ++;
	}

	return count;
}

int permutations(string input) {//prints all permutations of the characters in str
  //returns the number of permutations found
  //you will need to call another function that takes more than 1 parameter
  //intuition of recursion is to decide which of the remaining characters should go next


	return findPerms(input, "");
	

}


/*Useful string information:
+ is overloaded for string concatentation, can also add string + char
string string1="abc", string2="def";
char ch='z';
string sum= string1 + string2;  //sum will be abcdef
sum += ch;	//sum will be abcdefz

string substr(int offset, int count) is a member of the string class that returns a string
made starting from offset and having count number of characters in it.  Original string unchanged.
Example:  
string str = "abcde", result;
result = str.substr(1, 1);	result is "b"
result = str.substr(2, 3);  result is "cde";
result = str.substr(1, str.length() -1);  result is "bcde"
*/

void main () {//my output is in alphabetical order, yours doesn't have to be
  cout << permutations("abc") <<endl;/*Should print out (in some order):
abc
acb
bac
bca
cab
cba
6*/
  cout << endl;
  cout << endl;

  cout << permutations("abcd") <<endl;/*Should print out (in some order):
abcd
abdc
acbd
acdb
adbc
adcb
bacd
badc
bcad
bcda
bdac
bdca
cabd
cadb
cbad
cbda
cdab
cdba
dabc
dacb
dbac
dbca
dcab
dcba
24*/
}