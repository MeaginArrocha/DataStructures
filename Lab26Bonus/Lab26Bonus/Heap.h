#ifndef HEAP_H
#define HEAP_H
template <typename Item>
class Heap {
public:
	Heap(int maxSiz = 10){arrSize = 0; arr[maxSiz];} //maxSiz is the capacity, defaults to 10
	bool empty() const{return arr.empty();}
	int size() const{return arrSize;}  //number of items currently in heap
	int capacity() const{return arr.size();} //maximum internal array can hold 
	bool insert(Item val){
		if(arrSize < capacity()){//less than capacity means more room to insert
			//insert at end to keep shape
			arrSize++;
			arr[arrSize] = val;
			//bubble up
			int index = arrSize;
			int temp = 0;
			while(arr[index] > arr[index * .5] && index >= 1){//half works because of truncation
				temp = arr[index];
				arr[index] = arr[index * .5];
				arr[index * .5] = temp;
				index = index * .5;
			}

			return true;
		}
		else//equal to capacity
			return false;
		
	}//return true iff there was room to insert, duplicates allowed
	bool removeMin(){
		if(!arr.empty()){
			//swap min with last index
			arr[0] = arr[arrSize - 1];
			arrSize --;
			int temp = 0;
			//bubble down
			int index = 1;
			while(arr[index] < arr[index * 2] || arr[index[ < arr[index * 2 + 1]){
					if(arr[index * 2] > arr[index * 2 + 1]){//left child
						temp = arr[index];
						arr[index] = arr[index * 2];
						arr[index * 2] = temp;
						index = index * 2;
					}
					else{//right child
						temp = arr[index]
						arr[index] = arr[index * 2 + 1];
						arr[index * 2 + 1] = temp;
						index = index * 2 + 1;
					}
			}
			return true;
		
		}
		else//no item to remove
			return false;
	}//return true iff there is item to remove
	bool getMin(Item &out){
		if(!arr.empty()){
			//min always at top
			out = arr[0];
			return true;
		}
		else
			return false;
	}//return true iff there is item to get, set out to the minimum item if present
	//getMin is similar to top from stacks and queues


	//the next two are just for debugging
	void printArray() const {
		for (int i=0; i < curSize; i++) cout <<data[i]<<" ";
		cout <<endl;
	}

	void printTree() const {//this only prints up to the first 7 values, but they are in a treeish shape
		std::string tabs[]={"\t\t\t\t", "\n\t", "\t\t\t\t\t\t", "\n", "\t\t", "\t\t\t\t", "\t\t"};
		for (int i=0; i < 7 && i < curSize; i++) cout <<tabs[i]<<data[i];
		cout <<"\n\n";
	}
private:
	Item arr;
	int arrSize;
};
#endif