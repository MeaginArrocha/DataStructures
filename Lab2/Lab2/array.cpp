#include <iostream>

using namespace std;

void intersection(int array1[], int size1, int array2[], int size2, int array3[], int &size3){

	for(int i = 0; i < size1; i++){
		for(int k = 0; k < size2; k++){
			if(array1[i] == array2[k]){
				array3[size3] = array1[i];
				size3++;
			}
		}
	}
}

void findLongestIncreasing(int array1[], int size1, int &starting, int &length){
	int longestChain = 1;
	int startingPoint = 0;

	for(int i = 1; i < size1; i++){
		if(array1[i] > array1[i-1]){
			  longestChain++;
		}
		else{
			if(longestChain > length){
			length = longestChain;
			starting = startingPoint;
			}
			longestChain = 1;
			startingPoint = i;
		}
	}
}

void main(){

	int ex1[] = {10, 11, -1, 5, 6, 7, 2};
	int ex2[] = {1, 2, 9, 10, 7};
	int ex3[5];
	int size3 = 0;
	int starting = 0;
	int length = 1;

	intersection(ex1, 7, ex2, 5, ex3, size3);
	for(int i = 0; i < size3; i ++){
		cout << ex3[i] << endl;
	}

	findLongestIncreasing(ex1, 7, starting, length);
		cout << "starting is " << starting << " longest chain is " << length <<endl;
}
