#include <iostream>

using namespace std;


int fun(int x) {
   int z=2;
   for (int i=1; i<x; i++) 
	   z*=2;
   return z;
 }
 void main(int N) {
   for (int i=1; i<N; i++)
	fun(N);
}

/*void main(){
	int z = 2;
for(int i = 0; i < 20; i++){
	z*=2;
	cout << z <<endl;
}
}*/