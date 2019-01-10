#include <string>
#include <vector>
#include "CCount.h"

using namespace std;

class AnagramMaker{
public:
	AnagramMaker(const std::string &dictionaryFile);

	unsigned int findAnagrams(const string &input, const bool &print) const;
	//returns number of anagrams it was able to make for input

	

private:
	vector <CCount> dictionaryVec;

	unsigned int findAnagrams (string &soFar,const string &input, const bool &print, const int &index, vector <CCount> &newDict) const;

};