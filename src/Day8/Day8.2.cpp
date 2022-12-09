/***************************************************************************/
//
// RAÚL GRANADOS LÓPEZ
// 2ºB GII - UGR
// 
// Advent of code - 2022
// 
// Day 8
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
		cerr <<"Error: Invalid amount of arguments." << endl;
		cerr << "Uso: Day8.2 <input>" << endl;
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
	fi >> str;
	int tam = str.size();

	int m[tam][tam];

	for (int i=0; i<tam; i++) {
		m[0][i] = str.at(i) - '0';
	}

	for (int i=1; i<tam; i++) {
		fi >> str;
		for (int j=0; j<tam; j++) {
			m[i][j] = str.at(j) - '0';
		}
	}

	// Calculations
	int *view = new int[4];		// 4 sides: north, east, south, west
	vector<int> scenic;
	bool resume;
	for (int r=1; r<tam-1; r++) {
		for (int c=1; c<tam-1; c++) {
			// If the tree height is 0 it cannot be seen
			if (m[r][c] != 0) {
				
				for (int i=0; i<4; i++) {
					view[i] = 0;
				}

				// Check if it can be seen from the top
				resume = true;
				for (int i=r-1; i>=0 && resume; i--) {
					if (m[i][c] < m[r][c]) {
						view[0]++;
					}
					else {
						view[0]++;
						resume = false;
					}
				}

				// Check if it can be seen from the right
				resume = true;
				for (int i=c+1; i<tam && resume; i++) {
					if (m[r][i] < m[r][c]) {
						view[1]++;
					}
					else {
						view[1]++;
						resume = false;
					}
				}

				// Check if it can be seen from the left
				resume = true;
				for (int i=c-1; i>=0 && resume; i--) {
					if (m[r][i] < m[r][c]) {
						view[2]++;
					}
					else {
						view[2]++;
						resume = false;
					}
				}

				// Check if it can be seen from the bottom
				resume = true;
				for (int i=r+1; i<tam && resume; i++) {
					if (m[i][c] < m[r][c]) {
						view[3]++;
					}
					else {
						view[3]++;
						resume = false;
					}
				}

				scenic.push_back(view[0] * view[1] * view[2] * view[3]);
			}
		}
	}

	// Search the gighest scenic
	int highest = 0;
	for (int i : scenic) {
		if (i > highest) {
			highest = i;
		}
	}

	// Show the result
	cout << "The highest scenic score is " << highest << endl;

	delete [] view;

	return 0;
}