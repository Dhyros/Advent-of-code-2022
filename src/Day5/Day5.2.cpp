/***************************************************************************/
//
// RAÚL GRANADOS LÓPEZ
// 2ºB GII - UGR
// 
// Advent of code - 2022
// 
// Day 5
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char **argv) {

	// Check the amount of arguments
	if (argc != 2) {
		cerr <<"Error: Invalid amount of arguments." << endl;
		cerr << "Uso: Day5.1 <input>" << endl;
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
	getline(fi, str);
		
	// Number of stacks
	int n_stacks = (str.length()+1)/4;
	stack<char> *aux = new stack<char>[n_stacks];

	// Insert the information in the auxiliar stacks (they are rerversed)
	while (str.at(1)!='1') {
		for (int i=1, cont=0; i<str.length(); i+=4, cont++) {
			if (!isspace(str[i])) {
				aux[cont].push(str.at(i));
			}
		}
		getline(fi, str);
	}

	// Flip the stacks
	stack<char> s[n_stacks];

	for (int i=0; i<n_stacks; i++) {
		while (!aux[i].empty()) {
			s[i].push(aux[i].top());
			aux[i].pop();
		}
	}

	delete [] aux;
	// Rearrangement
	while (fi >> str) {
		int amount, from, to;

		fi >> str;
		amount = stoi(str);

		fi >> str;
		fi >> str;
		from = stoi(str) - 1;

		fi >> str;
		fi >> str;
		to = stoi(str) - 1;

		stack<char> cratemover;
		for (int i=0; i<amount; i++) {
			cratemover.push(s[from].top());
			s[from].pop();

		}
		
		for (int j=0; j<amount; j++) {
			s[to].push(cratemover.top());
			cratemover.pop();
		}
	}


	// Show the result
	str.clear();
	for (int i=0; i<n_stacks; i++) {
		str.push_back(s[i].top());
	}

	cout << "The code is " << str << endl;

	return 0;
}