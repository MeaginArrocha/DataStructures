
#include <iostream>
#include <string>
#include <map>

using namespace std;
//using namespace stdext;

class DateConverter {
public:
	DateConverter();
	//~DateConverter();

	/*Convert takes a date as a string in the format Month Day, Year 
	It returns a string in the format mm/dd/yyyy.
	It also sets its pass by reference variables month, day, and year appropriately

	For example:
	string str="January 5, 2004";
	int m, d, y;
	string out=convert(str, m, d, y);
	out will be 01/05/2004, m will be 1, d will be 5, and y will be 2004.
	Notice the leading 0 on month and day.  Your output should have 2 digit day and month and 4 digit years.
	The input string may have the day as 1 or 2 digits.  The year could be 1-4 digits as this convert function
	handles dates like April 4, 33.  This would convert to 04/04/0033.
	*/
	string convert(const string &, int &month, int &day, int &year) const;


	//This method prints out your map, 1 key/value pair per line, each line is of the form:  key maps to value
	void printOut() const;

private:
	//you must use the STL map to store the mappings from months to number (like January to 1).
	//you may add anything else you want/need to the private section 
	map <string,int> monthMap;
};