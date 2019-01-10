#include <string>

using namespace std;

class CCount{
public:
	CCount(string w);
	
	string subtractFrom(CCount input) const;
	bool lessThan(CCount input);
	string getWord() const;
private:
	char arr[26];
	string word;
	
	string getResult();
	void decrementArr(char cha);
	int getLength();
	char getCharAmount(char cha);
	
};