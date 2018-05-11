
// This project is a wator project, We had to implement this project as a part of our Concurrent 4th Year Subject
// Date: 11/05/2018
// Authors: Wojciech Teodorowicz, Sahan Ekanayake

#include <iostream>
#include <random>
#include <vector>
#include <unistd.h>
#include <time.h> 
#include <math.h>


using namespace std;

int NumberOfFishes = 11;
int NumberOfSharks = 5;
int const width = 20;
int const height = 20;

long int microseconds = 100000; // Timer variable

//initialiez symbols for fishes and sharks

char const water = '-'; //water symbol
char const fish = '>'; //fish symbol
char const shark = 'S'; //shark symbol


class Grid {
	public:
		char symbol;
		// Constructor for the water
		Grid() {
			symbol = water;
	   	}
		// Contstructor for types: Fish and Sharks
	   	Grid(char type) {
	  		if (type == fish) {
				symbol = fish;
	   		}
	   		else {
				symbol = shark;
	   		}
		}
};

class Species {
	public:
		int setX (int x) {
			_x = x;
	   	}

	   	int setY (int y) {
	   		_y = y;
	   	}

	   	int getX () {
	   		return _x;
	   	}

	   	int getY() {
	   		return _y;
	   	}

	   	void moveX (int rX) {
	   		_x = _x + rX;
	   		if(_x > width - 1) {
		        _x = 0;
		    }
		    if(_x < 0) {
		        _x = width - 1;
		    }
	   	}

	   	void moveY (int rY) {
	   		_y = _y + rY;
	   		if(_y > height - 1) {
		        _y = 0;
		    }
		    if(_y < 0) {
		        _y = height - 1;
		    }
	   	}
	protected:
		int _x;
		int _y;
};




class Fish: public Species {
	public:

		void reset () {
			ReproduceSpecies = 0;
		}

		bool FishReproduction() {
			return Reproduce == ReproduceSpecies;
		}
		int getReproduction () {
			return ReproduceSpecies;
		}
		void increaseReproduction () {
			ReproduceSpecies++;
		}
	private:
		int Reproduce = 5;
		int ReproduceSpecies = 0;
};

//creating the sea grid
void draw(vector<vector<Grid>> &sea) {
	for(int i = 0; i < height; i++) {
    	for(int j= 0; j < width; j++) {
        	cout << sea[j][i].symbol;
        }
 	cout << endl;
    }
    cout << endl;

}

void removeFishObj (vector<Fish> &ArrFishes, int x, int y) {
	for (int i=0; i < NumberOfFishes; i++) {
    	if (ArrFishes[i].getX() == x && ArrFishes[i].getY() == y) {
    		ArrFishes.erase(ArrFishes.begin() + i);
    		NumberOfFishes--;
    	}
    }
}

//Show Fish on Screen
void populateFish(vector<vector<Grid>> &sea, vector<Fish> &ArrFishes, int NumberOfFishes) {
    for (int i=0; i < NumberOfFishes; i++) {
    	ArrFishes[i] = Fish();
    	do {
        	ArrFishes[i].setX(rand() % width);
        	ArrFishes[i].setY(rand() % height);
        }
        while (sea[ArrFishes[i].getX()][ArrFishes[i].getY()].symbol != water);
    	sea[ArrFishes[i].getX()][ArrFishes[i].getY()] = Grid(fish);
    }
}

class Shark: public Species {
	public:
		bool checkFish (vector<vector<Grid>> &sea) {
			if (checkLeft(sea) || checkTop(sea) || checkRight(sea) || checkBottom(sea)) {
				return true;
			}
			return false;
		}
		//Check if left side has fishes
		bool checkLeft (vector<vector<Grid>> &sea) {
			
			if (_x - 1 >= 0) {
				if (sea[_x - 1][_y].symbol == fish) {
					_x = _x - 1;
					increaseEnergy();
					resetHunger();
					return true;
				}
			}
			// Check if left edge of tha map has fishes
			if (_x - 1 < 0) {
				if (sea[width - 1][_y].symbol == fish) {
					_x = width - 1;
					increaseEnergy();
					resetHunger();
					return true;
				}
			}
			return false;
		}
		//Check Right Side for fishes
		bool checkRight (vector<vector<Grid>> &sea) {
			if (_x + 1 < width) {
				if (sea[_x + 1][_y].symbol == fish) {
					_x = _x + 1;
					increaseEnergy();
					resetHunger();
					return true;
				}
			}
			// Check if the right edges contains fishes
			if (_x + 1 == width) {
			//if yes increase breed
				if (sea[0][_y].symbol == fish) {
					_x = 0;
					increaseEnergy();
					resetHunger();
					return true;
				}
			}
			return false;
		}
		//check top edge for fish
		bool checkTop (vector<vector<Grid>> &sea) {
			// check top position for fish
			if (_y - 1 >= 0) {
				if (sea[_x][_y - 1].symbol == fish) {
					_y = _y - 1;
					increaseEnergy();
					resetHunger();
					return true;
				}
			}
			if (_y - 1 < 0) {
				if (sea[_x][height - 1].symbol == fish) {
					_y = height - 1;
					increaseEnergy();
					resetHunger();
					return true;
				}
			}
			return false;
		}
		// check bottom side for fishes
		bool checkBottom (vector<vector<Grid>> &sea) {
			// check bottom position for fish
			if (_y + 1 < height) {
				if (sea[_x][_y + 1].symbol == fish) {
					_y = _y + 1;
					increaseEnergy();
					resetHunger();
					return true;
				}
			}
			// check bottom edge for fish
			if (_y + 1 == height) {
				if (sea[_x][0].symbol == fish) {
					_y = 0;
					increaseEnergy();
					resetHunger();
					return true;
				}
			}
			return false;
		}
		//Assign all the functiuon to make a shark breed, increase in energy, reset , Hunger...

		void increaseEnergy () {
			energy++;
		}

		bool canSharkBreed () {
			return energy == SharkReproduce;
		}

		void resetEnergy () {
			energy = 0;
		}

		void gettingHungry () {
			hunger++;
		}

		bool hasStarved () {
			return hunger == starve;
		}

		void resetHunger () {
			hunger = 0;
		}

		int getEnergy() {
			return energy;
		}
		int	getHunger () {
			return hunger;
		}
	private:
		int SharkReproduce = 2;
		int starve = 17;
		int energy = 0;
		int hunger = 0;
};
// Show Shark on Screen
void populateSharks(vector<vector<Grid>> &sea, vector<Shark> &ArrSharks, int NumberOfSharks) {
    for (int i=0; i < NumberOfSharks; i++) {
    	ArrSharks[i] = Shark();
    	do {
    	   	ArrSharks[i].setX(rand() % width);
        	ArrSharks[i].setY(rand() % height);
        }
        while (sea[ArrSharks[i].getX()][ArrSharks[i].getY()].symbol != water);
        sea[ArrSharks[i].getX()][ArrSharks[i].getY()] = Grid(shark);
    }
}
// go left top right or bottom
int makeDecision () {
	return rand() % 100 > 50 ? 1 : -1;
}

int main(void) {
	srand(time(0));
	vector<Fish> ArrFishes;
	ArrFishes.resize(NumberOfFishes);

	vector<Shark> ArrSharks;
	ArrSharks.resize(NumberOfSharks);

    vector<vector<Grid>> sea;
    sea.resize(width);

    for( int i = 0; i < width; i++) {
    	sea[i].resize(height);
    }

	populateFish(sea, ArrFishes, NumberOfFishes);
	populateSharks(sea, ArrSharks, NumberOfSharks);

	draw(sea);

	int move = 0;
    while(NumberOfFishes > 0 && NumberOfSharks > 0) {
		//cin.get();
    	int newFish = 0;
    	int blocked = 0;
    	for (int i=0; i < NumberOfFishes; i++) {
    		int previousX = ArrFishes[i].getX();
    		int previousY = ArrFishes[i].getY();
    		makeDecision() < 0 ? ArrFishes[i].moveX(makeDecision()): ArrFishes[i].moveY(makeDecision());

			// if next position is free, move fish there
    		if (sea[ArrFishes[i].getX()][ArrFishes[i].getY()].symbol == water) {
	        	sea[ArrFishes[i].getX()][ArrFishes[i].getY()] = Grid(fish);
				// increase breed age
	        	ArrFishes[i].increaseReproduction();
				// when fish can breed, move and add new fish in old position
	        	if (ArrFishes[i].FishReproduction()) {
	        		newFish++;
	        		ArrFishes[i].reset();
	        		ArrFishes.resize(NumberOfFishes + newFish);
	        		ArrFishes[NumberOfFishes + newFish - 1] = Fish();
			        ArrFishes[NumberOfFishes + newFish - 1].setX(previousX);
			        ArrFishes[NumberOfFishes + newFish - 1].setY(previousY);
	        	} else {
	        		sea[previousX][previousY] = Grid();
	        	}
	        } else {
	        	blocked++;
	        	ArrFishes[i].setX(previousX);
        		ArrFishes[i].setY(previousY);
				// if fish is blocked don't move
	        	if (blocked < 10) {
	        		continue;
	        	}
	        }
    	}
    	blocked = 0;
    	NumberOfFishes = NumberOfFishes + newFish;

    	int newShark = 0;
    	for (int i=0; i < NumberOfSharks; i++) {
    		int previousX = ArrSharks[i].getX();
    		int previousY = ArrSharks[i].getY();
			// Fish is close to shark, move shark
    		if (ArrSharks[i].checkFish(sea)) {
    			sea[ArrSharks[i].getX()][ArrSharks[i].getY()] = Grid(shark);
    			removeFishObj(ArrFishes, ArrSharks[i].getX(), ArrSharks[i].getY());
    			NumberOfFishes = ArrFishes.size();
				// Shark can produce, move shark
    			if (ArrSharks[i].canSharkBreed()) {
    				newShark++;
    				ArrSharks[i].resetEnergy();
    				ArrSharks.resize(NumberOfSharks + newShark);
    				ArrSharks[NumberOfSharks + newShark -1] = Shark();
    				ArrSharks[NumberOfSharks + newShark - 1].setX(previousX);
			        ArrSharks[NumberOfSharks + newShark - 1].setY(previousY);
    			} else {
    				sea[previousX][previousY] = Grid();
    			}
    		} else {
    			makeDecision() < 0 ? ArrSharks[i].moveX(makeDecision()): ArrSharks[i].moveY(makeDecision());
				// move shark to free position
	    		if (sea[ArrSharks[i].getX()][ArrSharks[i].getY()].symbol == water) {
		        	sea[previousX][previousY] = Grid();
		        	ArrSharks[i].gettingHungry();
					// shark has starved
		        	if (ArrSharks[i].hasStarved()) {
		        		ArrSharks.erase(ArrSharks.begin() + i);
		        		NumberOfSharks--;
		        	} else {
		        		sea[ArrSharks[i].getX()][ArrSharks[i].getY()] = Grid(shark);
		        	}
		        } else {
		        	blocked++;
		        	ArrSharks[i].setX(previousX);
	        		ArrSharks[i].setY(previousY);
					// Dont move if shark has been blocked by empty space
	        		if (blocked < 10) {
	        			ArrSharks[i].gettingHungry();
		        		continue;
		        	}
		        }
    		}
    	}
    	NumberOfSharks = NumberOfSharks + newShark;
    	blocked = 0;

    	move++;
		cout << "Position movement: " << move << endl;
		usleep(microseconds);
    	draw(sea);
		cout << "Number Of Fishes: " << NumberOfFishes << " \nNumber of Sharks: " << NumberOfSharks << "" << endl;
		cout << endl;
    }
}
