#include <iostream>
#include <string>
using namespace std;

class Vehicle{
public:
	Vehicle(string n){
		Name = n;
	}
	virtual~Vehicle(){
	cout << "The " << className << ": " << Name << ", is destroyed." << endl;
	}

	string getName() const {return Name;}
	virtual string getStartNoise() const = 0;
	virtual string getMoveNoise() const = 0;

	string className;

private:
	string Name;
};

class Rumbles:public Vehicle{
public:
	Rumbles(string n):Vehicle(n){}
	string getMoveNoise() const {return "rumbles";}
};

class Car:public Rumbles{
public:
	Car(string n):Rumbles(n){className = "Car";}
	string getStartNoise() const {return "wakens";}
};

class Truck:public Rumbles{
public:
	Truck(string n):Rumbles(n){className = "Truck";}
	string getStartNoise() const {return "roars";}
};

class RaceCar:public Vehicle{
public:
	RaceCar(string n, int m):Vehicle(n){mph = m; className = "RaceCar";}
	string getStartNoise() const {return "ROARS";}
	string getMoveNoise() const {
		if(mph >= 200)
			return  "screams";

	return "runs";
	}

private:
	int mph;
};


void drive (const Vehicle * vehicle) {
  cout << "You start " << vehicle->getName() << " which " << vehicle->getStartNoise() 
	   << " to life and " << vehicle->getMoveNoise() << " down the road.\n";
}

const int numWorking = 4;

void main () {

  Vehicle * autos[numWorking];
  cout << "Creating autos\n";
  autos[0] = new Car("Flo");
  autos[1] = new Truck("Mater");
  autos[2] = new RaceCar("Lightning McQueen", 300);
  autos[3] = new RaceCar("Chick Hicks", 180);

  cout << "\nNow driving them.\n";
  for (int i=0; i<numWorking; i++)
	drive(autos[i]);

  cout << "\nNow destroying them.\n";
  for (int i=0; i<numWorking; i++)
	delete autos[i];
}