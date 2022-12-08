/***************************************************************************/
//
// RAÚL GRANADOS LÓPEZ
// 2ºB GII - UGR
// 
// Advent of code - 2022
// 
// Day 6
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
		cerr << "Uso: Day6.1 <input>" << endl;
		exit(-1);
	}

	// Check if the input file can be opened
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << "Error opening file \"" << argv[1] << "\"." << endl;
		exit(-1);
	}

	// Reading the input file
	string str, sub_str;
	fi >> str;
	int marker;

	// Find where the marker is
	bool found = false;
	for (int i=0; i<str.length()-4 && !found; i++) {
		sub_str = str.substr(i, 4);
		
		// Check if all the characters are different
		bool equal = false;
		for (int j=0; j<sub_str.length()-1 && !equal; j++) {
			for (int k=j+1; k<sub_str.length() && !equal; k++) {
				if (sub_str.at(j) == sub_str.at(k)) {
					equal = true;
				}
			}
		}

		if (!equal) {
			found = true;
			marker = i+4;
		}
	}

	// Show the result
	cout << "The amount of characters needed to be processed is " << marker
		<< endl;
	
	return 0;
}