/***************************************************************************/
//
// RAÚL GRANADOS LÓPEZ
// 2ºB GII - UGR
// 
// Advent of code - 2022
// 
// Day 2
//
/***************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

// Types of shapes admitted in the game
enum struct Shape {
	Rock = 0,
	Paper = 1,
	Scissors = 2
};

// The shape depends on the char
Shape CharToShape(char c) {
	Shape s;

	switch (c) {
		case 'A':
			s = Shape::Rock;
			break;

		case 'B':
			s = Shape::Paper;
			break;

		case 'C':
			s = Shape::Scissors;
	}

	return s;
}

// Function that returns the outcome of the round
int Outcome(char elfe, char me) {
	int score;
	// Shows if the first shape wins the second shape
	bool result[3][3] = {
		{false, false, true },
		{true,  false, false},
		{false, true,  false}
	};

	// Score of the round
	if (me == 'Y') {
		score = 3 + (int)CharToShape(elfe)+1;
	}
	else {
		if (me == 'Z') {
			score = 6 + ((int)CharToShape(elfe) + 1) % 3 + 1;
		}
		else {
			score = 0 + ((int)CharToShape(elfe) + 2) % 3 + 1;
		}
	}

	return score;
}

int main(int argc, char **argv) {

	// Check the amount of arguments
	if (argc != 2) {
		cerr <<"Error: Invalid amount of arguments." << endl;
		cerr << "Uso: Day2.2 <input>" << endl;
		exit(-1);
	}

	// Check if the input file can be opened
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << "Error opening file \"" << argv[1] << "\"." << endl;
		exit(-1);
	}
	
	// Reading the input file
	char elfe, me;
	int score = 0;
	while (fi >> elfe) {
		fi >> me;

		// Add the outcome of the current round
		score += Outcome(elfe, me);
	}

	// Showing the final result
	cout << "Total score of " << score << endl;

	return 0;
}