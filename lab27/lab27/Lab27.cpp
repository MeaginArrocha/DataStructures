#include <iostream>
#include <string>
#include <map>
using namespace std;

class Date {
public:
	Date(string m , int d) :month(m), day(d) {
		monthMap["Jan"] = 1;
		monthMap["Feb"] = 2;
		monthMap["Mar"] = 3;
		monthMap["Apr"] = 4;
		monthMap["May"] = 5;
		monthMap["June"] = 6;
		monthMap["July"] = 7;
		monthMap["Aug"] = 8;
		monthMap["Sept"] = 9;
		monthMap["Oct"] = 10;
		monthMap["Nov"] = 11;
		monthMap["Dec"] = 12;
	}
	Date(int integer) : day(integer){month = "";}
	string getMonth() const;
	int getDay() const;
	int getMap() const;
private:
	string month;//3 letter abbreviation of month, Jan Feb, Mar, etc.  
	//you may assume that the constructor and >> overload are always given valid months
	int day;
	map <string, int> monthMap;
};

string Date::getMonth() const{
	return month;
}

int Date::getDay() const{
	return day;
}

int Date::getMap() const{
	return monthMap.at(month);
}

/* You need to implement operator overloads for the above Date class to do comparison, <<, and + int

The overload << for cout should print  month-day
where month and day are the current values including the - but no spaces or endl.  
Eg.
Date t1 ("Oct",17);
cout <<t1;  //should print exactly 6 characters: Oct-17
Date t2 ("May",7);
cout <<t2;  //should print exactly 5 characters: May-7

The overload >> for cin should read one string and one int as the month and day.

To add an integer and a Date treat the integer as a number of days to add to the date.
You may assume the addition will not rollover the month.*/


ostream &operator << (ostream &out, Date &value){//cout
	out << value.getMonth() << "-" << value.getDay();
	return out;
}

istream &operator >> (istream &in, Date &value){//cin
	string month;
	int day;
	in >> month >> day;
	Date temp(month, day);
	value = temp;
	return in;
}

Date operator +(const Date &left, const Date &right){//add integer to Date w/ integer being number of days to add to the date
	//no rollover
	Date temp(left.getMonth() + right.getMonth(), left.getDay() + right.getDay());
	return temp;
}


/*Two Dates are == if they have the same month and day values

t1 < t2 iff month1 < month2 or (month1==month2 and day1 < day2).  So compare month first, then day.
note months should be compared as their ordinal values, not alphabetical
to accomplish this, set up a map that goes from string to int so that
map of Jan is 1, map of Feb is 2, etc.

You may add additional public methods as needed to Date.  You will also need
to add functions outside the class.

You should implement overloads for all 6 comparisons == != < <= > >=
Only == and < should have any mention of month or day
(as we did inclass the other overloads should use == and < intelligently)
The other overloads must have exactly 1 and only 1 call to either == or <, but not both.
They shouldn't use the other overloaded comparisons.
*/

bool operator ==(const Date &left, const Date &right){//are two dates equal - same month and day
	return (left.getMonth() == right.getMonth() && left.getDay() == right.getDay());
}

bool operator !=(const Date &left, const Date &right){//are dates not equal
	return !(left == right);
}

bool operator <(const Date &left, const Date &right){
	return (left.getMap() < right.getMap()) || 
		(left.getMap() == right.getMap() && left.getDay() < right.getDay());
}

bool operator >(const Date &left, const Date &right){
	return !(left < right);
}

bool operator <=(const Date &left, const Date &right){
	return !(right < left);
}

bool operator >=(const Date &left, const Date &right){
	return !(left < right);
}


void compare(const Date &lhs, const Date &rhs) {//just saves some space and typing for my tests
	if (lhs < rhs) cout <<"less\n";
	else if (lhs == rhs) cout <<"equal\n";
	else if (lhs > rhs) cout <<"greater\n";
}

void compare2(const Date &lhs, const Date &rhs) {//just saves some space and typing for my tests
	if (lhs != rhs) cout <<"not equal and  ";
	else cout <<"equal and ";

	if (lhs >= rhs) cout <<"greater=\n";
	else if (lhs <= rhs) cout <<"less=\n";
}
void main () {
	Date current("Dec",3), previous("Nov",15), later("Dec",5), later2("Dec",5);
	cout <<current <<endl;  //Dec-3
	cout <<later<<endl;	  //Dec-5
	cout <<previous <<endl; //Nov-15
	cout <<endl;
	compare (current , later) ; //less
	compare (current , previous) ;//greater
	compare (later , current) ;//greater
	compare (previous ,current) ;//less
	cout <<endl;

	compare(later, later2);//equal
	compare2(later,later2);//equal and greater= 
	compare2(previous, current);//not equal and less=
	compare2(later, current);//not equal and greater=

	cout <<endl;

	current = current + 4;
	cout <<current <<endl;//Dec-7
	current = 20 + current ;
	cout <<current <<endl;//Dec-27
	
	cin >> current;
	cout <<current <<endl;//whatever is typed in above
}