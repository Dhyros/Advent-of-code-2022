/***************************************************************************/
//
// RAÚL GRANADOS LÓPEZ
// 2ºB GII - UGR
// 
// Advent of code - 2022
// 
// Day 4
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
		cerr << "Uso: Day4.2 <input>" << endl;
		exit(-1);
	}

	// Check if the input file can be opened
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << "Error opening file \"" << argv[1] << "\"." << endl;
		exit(-1);
	}

	// Reading the input file
	pair<int, int> p1, p2;
	int count = 0;
	string str;
	while(getline(fi, str, '-')) {
		p1.first = stoi(str);

		getline(fi, str, ',');
		p1.second = stoi(str);

		getline(fi, str, '-');
		p2.first = stoi(str);

		getline(fi, str);
		p2.second = stoi(str);

		if ((p2.first>=p1.first && p2.first<=p1.second) ||
			(p1.first>=p2.first && p1.first<=p2.second)) {
				count++;
		}
	}

	// Show the result
	cout << "The amount of pairs in which the ranges overlap is " << count
		<< endl;
	
	return 0;
}