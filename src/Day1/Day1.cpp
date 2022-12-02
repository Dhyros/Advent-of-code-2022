/***************************************************************************/
//
// RAÚL GRANADOS LÓPEZ
// 2ºB GII - UGR
// 
// Advent of code - 2022
// 
// Day 1
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {

	// Check the amount of arguments
	if (argc != 2) {
		cerr <<"Error: Invalida amount of arguments." << endl;
		cerr << "Uso: Day1 <input>" << endl;
		exit(-1);
	}

	// Check if the input file can be opened
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << "Error opening file \"" << argv[1] << "\"." << endl;
		exit(-1);
	}

	// Vector in which the calories that the elves are carrying are stored
	vector<int> v;

	// String used to insert values into the vector
	string valor;

	// First element of the vector
	v.push_back(0);

	// Advanced reading
	while (!fi.eof()) {
		if (!isspace(fi.peek())) {
			getline(fi, valor);
			v[v.size()-1] += stoi(valor);
		}
		else {
			// Each time there is an empty line a new extra storage location
			// in the array is added
			v.push_back(0);
			getline(fi, valor);
		}
	}

	// Finding the top three Elves carrying the most Calories
	const int AMOUNT = 3;
	for (int i=0; i<AMOUNT; i++) {
		for (int j=v.size(); j>i+1; j--) {
			if (v[j] > v[i]) {
				swap(v[j], v[i]);
			}
		}
	}

	// Top 3 elves shown
	int total = 0;
	for (int i=0; i<AMOUNT; i++) {
		cout << "The elfe " << i+1 << " carries " << v[i] << " calories." << endl;
		total += v[i];
	}

	// Amount of calories carried in total
	cout << "They carry " << total << " calories in total." << endl;
	
	return 0;
}
