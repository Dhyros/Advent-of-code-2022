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

	// cout << (int)'p'% (int)'a' +1 << endl;
	// cout << (int)'L'% (int)'A' + 27 << endl;

	// Reading the input file
	string str[3];
	char c;
	int sum = 0;			// Sum of the priorities
	bool found;				// True if the element in common is found
	while (fi >> str[0]) {
		fi >> str[1];
		fi >> str[2];
		found = false;

		// traverse the two parts of the string in search of the element 
		// in common
		for (int i=0; i<str[0].length() && !found; i++) {
			for (int j=0; j<str[1].length() && !found; j++) {
				for (int k=0; k<str[2].length() && !found; k++) {
					if (str[0].at(i) == str[1].at(j) &&
						str[0].at(i) == str[2].at(k)) {
							c = str[0].at(i);

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
	}

	// Show the result
	cout << "The sum of the priorities is " << sum << endl;
	
	return 0;
}