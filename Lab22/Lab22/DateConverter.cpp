#include "DateConverter.h"

using namespace std;


DateConverter::DateConverter(){
	monthMap["January"] = 1;
	monthMap["February"] = 2;
	monthMap["March"] = 3;
	monthMap["April"] = 4;
	monthMap["May"] = 5;
	monthMap["June"] = 6;
	monthMap["July"] = 7;
	monthMap["August"] = 8;
	monthMap["September"] = 9;
	monthMap["October"] = 10;
	monthMap["November"] = 11;
	monthMap["December"] = 12;
}

string DateConverter::convert(const string &input, int &month, int &day, int &year) const{
	int index = 0;
	string monthString, finalStr;
	while(input[index] != ' ')//gets month
		index++;
	monthString = input.substr(0, index);
	month = monthMap.at(monthString);

	while(input[index] != ',')//gets day
		index++;
	if(input[index - 2] == ' ')
		day = atoi(input.substr(index - 1, 1).c_str());
	else
		day = atoi(input.substr(index - 2, 2).c_str());

	//index++;
	while(index != input.length())//gets year
		index++;
	if(input[index - 5] != ' ')
		year = atoi(input.substr(index - 2, 2).c_str());
	else
		year = atoi(input.substr(index - 4, 4).c_str());

	if(month <= 9)
		finalStr = '0' + to_string(month) + '/';
	else
		finalStr = to_string(month) + '/';

	if(day < 10)
		finalStr += '0' + to_string(day) + '/';
	else
		finalStr += to_string(day) + '/';

	if(year < 10)
		finalStr += "000" + to_string(year);
	else if(year < 100)
		finalStr += "00" + to_string(year);
	else
		finalStr += to_string(year);

	return finalStr;
}


void DateConverter::printOut() const{
	map <string, int> :: const_iterator mit;  
	for (mit = monthMap.begin(); mit != monthMap.end(); mit++) {
		cout << mit->first << " maps to value: " << mit->second<<endl;
	}

}

void main(){
	DateConverter dc;
	string date = "January 5, 2004";
	int month, day, year;
	cout << dc.convert(date, month, day, year);
	
	cout << endl;
	dc.printOut();
}