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

using namespace std;

int main(int argc, char **argv) {

	// Check the amount of arguments
	if (argc != 2) {
		cerr <<"Error: Invalid amount of arguments." << endl;
		cerr << "Uso: Day8.1 <input>" << endl;
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
	int trees_visible = (tam-1)*4;
	int visibility;	// Indicates how many directions a tree can be seen
	bool resume;
	for (int r=1; r<tam-1; r++) {
		for (int c=1; c<tam-1; c++) {
			// If the tree height is 0 it cannot be seen
			if (m[r][c] != 0) {
				visibility = 4;
				// Check if it can be seen from the top
				resume = true;
				for (int i=r-1; i>=0 && resume; i--) {
					if (m[i][c] >= m[r][c]) {
						visibility--;
						resume = false;
					}
				}

				// Check if it can be seen from the right
				resume = true;
				for (int i=c+1; i<tam && resume; i++) {
					if (m[r][i] >= m[r][c]) {
						visibility--;
						resume = false;
					}
				}

				// Check if it can be seen from the left
				resume = true;
				for (int i=c-1; i>=0 && resume; i--) {
					if (m[r][i] >= m[r][c]) {
						visibility--;
						resume = false;
					}
				}

				// Check if it can be seen from the bottom
				resume = true;
				for (int i=r+1; i<tam && resume; i++) {
					if (m[i][c] >= m[r][c]) {
						visibility--;
						resume = false;
					}
				}

				if (visibility != 0) {
					trees_visible++;
				}
			}
		}
	}

	// Show the result
	cout << "The amount of trees that are visible is " << trees_visible << endl;

	return 0;
}