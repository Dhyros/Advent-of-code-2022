/***************************************************************************/
//
// RAÚL GRANADOS LÓPEZ
// 2ºB GII - UGR
// 
// Advent of code - 2022
// 
// Day 3
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
	
	// Check the amount of arguments
	if (argc != 2) {
		cerr <<"Error: Invalid amount of arguments." << endl;
		cerr << "Uso: Day3.1 <input>" << endl;
		exit(-1);
	}

	// Check if the input file can be opened
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << "Error opening file \"" << argv[1] << "\"." << endl;
		exit(-1);
	}

	// Reading the input file
	string str;
	char c;
	int sum = 0;			// Sum of the priorities
	bool found;				// True if the element in common is found
	while (fi >> str) {
		
		found = false;

		// traverse the two parts of the string in search of the element 
		// in common
		for (int i=0; i<str.length()/2 && !found; i++) {
			for (int j=str.length()/2; j<str.length() && !found; j++) {
				if (str.at(i) == str.at(j)) {
					c = str.at(i);

					// Add the priority of the item to the sum
					if (isupper(c)) {
						sum += (int)c % (int)'A' + 27;
					}
					else {
						sum += (int)c % (int)'a' + 1;
					}

					found = true;
				}
			}
		}
	}

	// Show the result
	cout << "The sum of the priorities is " << sum << endl;
	
	return 0;
}