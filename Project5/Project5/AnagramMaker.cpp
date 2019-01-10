#include "AnagramMaker.h"
#include "StopWatch.h"
#include <fstream>
#include <iostream>

using namespace std;

AnagramMaker::AnagramMaker(const std::string &dictionaryFile){
	ifstream myFile;
	string word;
	myFile.open(dictionaryFile);
	while(!myFile.eof()){
		getline(myFile, word);
		CCount add(word);
		dictionaryVec.push_back(add);
	}

	myFile.close();
}


unsigned int AnagramMaker::findAnagrams(const string &input, const bool &print) const{
	string empty = "";
	int index = 0;
	CCount temp(input);
	vector <CCount> newDict;
	for(unsigned int i = 0; i < dictionaryVec.size(); i++){
		CCount temp1 = dictionaryVec[i];
		if(temp1.lessThan(temp))
			newDict.push_back(dictionaryVec[i]);
	}
	return findAnagrams(empty, input, print, index, newDict);
}

unsigned int AnagramMaker::findAnagrams(string &soFar,const string &input, const bool &print,const int &index, vector <CCount> &newDict) const{
	unsigned int count = 0;
	CCount temp(input);//makes a new CCount object and makes char arr
	for(unsigned int i = index; i < newDict.size(); i++){
		if(newDict[i].lessThan(temp)){
			string result = newDict[i].subtractFrom(temp);
			if(result == ""){
				count++;
				if(print) cout << soFar << " " << newDict[i].getWord();
			}
			else{
				count+=findAnagrams(soFar + newDict[i].getWord(), result, print, i, newDict);
			}
		}


	}
	return count;
}
