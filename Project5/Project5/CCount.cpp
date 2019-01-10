#include "CCount.h"

CCount::CCount(string w){
	word = w;

	for(int j = 0; j < 26; j++)
		arr[j] = 0;


	for(unsigned int i = 0; i < word.length(); i++){
		arr[word[i] - 'a']++;
	}
}


bool CCount::lessThan(CCount input){
	int inputLength = input.getLength();
	if(word.length() > inputLength)
		return false;
	else{ //length is less than or equal to
		for(int i = 0; i < word.length(); i++){
			if(arr[i] > input.getCharAmount(word[i]))
				return false;
		}
		return true;
	}

}

string CCount::subtractFrom(CCount input) const{
	//subtracting dict from input

	for(int i = 0; i < word.length(); i ++)
		input.decrementArr(word[i]);

	return input.getResult();
}

void CCount::decrementArr(char cha){
	arr[cha - 'a']--;
}

string CCount::getResult(){
	string result;
	for(int i = 0; i < 26; i++){
		char temp = i + 'a';
		for(int j = arr[i]; j > 0; j--)
			result += temp;
	}

	return result;
}

int CCount::getLength(){
	return word.length();
}

char CCount::getCharAmount(char cha){
	return arr[cha - 'a'];
}


string CCount::getWord() const{
	return word;
}