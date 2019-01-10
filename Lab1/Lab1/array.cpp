#include <iostream>

using namespace std;



int countNegatives(int array[], int size){
	int count = 0;
	for(int i = 0; i < size; i++){
		if(array[i] < 0)
			count++;
	}
	return count;
}

int findMinMultOf5(int array[], int size){
	int minMult = 0;
	for(int i = 0; i < size; i++){
		if(array[i] % 5 == 0 && minMult == 0){
			minMult = array[i];
		}
		else if(array[i] % 5 == 0 && array[i] < minMult)
			minMult = array[i];
	}
	return minMult;
}

int findMinMultOf5Index(int array[], int size){
	int index = -1;
	int minMult = 0;
	for(int i = 0; i < size; i++){
		if(array[i] % 5 == 0 && minMult == 0){
			minMult = array[i];
			index = i;
		}
		else if(array[i] % 5 == 0 && array[i] < minMult){
			minMult = array[i];
			index = i;
		}
	}
	return index;
}

bool remove(int array[], int size, int index){
	if(size > index && index >= 0){
		for(int i = index; i < size - 1; i++){
			array[i] = array[i + 1];
		}
		return true;
	}
	else
		return false;
}

/* 
void main(){

	
	int ex1[]={3, 1, 5, -1, 10};
	//cout << countNegatives(ex1, 5) << endl;
	//cout << countNegatives(ex1, 3) << endl;

	//cout << findMinMultOf5(ex1, 5) << endl;
	//cout << findMinMultOf5(ex1, 3) << endl;

	cout << findMinMultOf5Index(ex1, 5) << endl;
	cout << findMinMultOf5Index(ex1, 4) << endl;
	cout << findMinMultOf5Index(ex1, 3) << endl;
	cout << findMinMultOf5Index(ex1, 2) << endl;
	cout << findMinMultOf5Index(ex1, 1) << endl;

	//remove(ex1, 5, 0);
	//remove(ex1, 5, 1);
	
	//remove(ex1, 4, 0);
	//remove(ex1, 4, 4);


	if(remove(ex1, 5, 4) == true){
	for(int i = 0; i < 5; i ++)
	{
		cout << ex1[i] << endl;;
	}
	doesn't do anything when it is the last index 
	because there are no later elements to shift forward.
	
}*/