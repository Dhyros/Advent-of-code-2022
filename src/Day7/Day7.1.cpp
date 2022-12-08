/***************************************************************************/
//
// RAÚL GRANADOS LÓPEZ
// 2ºB GII - UGR
// 
// Advent of code - 2022
// 
// Day 7
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_TAM = 100000;

class node {
private:
	int space;
	char type;		// 'f' for file, 'd' for directory
	string name;
	node *father;
	vector<node> son;

public:
	node() {		// root
		space = 0;
		type = 'd';
		father = nullptr;
		name = "/";
	}

	node(char t, node * f, string n, int s=0) {
		if (t == 'f') {
			type = 'f';
			space = s;
		}
		else {
			type = 'd';
			space = 0;
		}

		name = n;
		father = f;
	}

	void setSpace(int s) {
		space = s;
	}

	int getSpace() const {
		return space;
	}

	node * getSon(int i) {
		return &son[i];
	}

	node * getFather() {
		return father;
	}

	string getName() const {
		return name;
	}

	char getType() const {
		return type;
	}

	int numSons() const {
		return son.size();
	}

	void addSon(node & n) {

		son.push_back(n);

		if (n.getSpace() != 0) {
			node *aux = this;
			while (aux != nullptr) {
				aux->space += n.getSpace();
				aux = aux->father;
			}
		}
	}

	// To see the entire tree
	string ToString() const {
		string str;

		if (type == 'd') {
			str += "- " + name + " (dir)\n";
			for (int i=0; i<son.size(); i++) {
				str += son[i].ToString();
			}
		}
		else {
			str += "- " + name + " (file, size=" + to_string(space) + ")\n";
		}

		for (int i=0; i<str.size()-1; i++) {
			if (str.at(i) == '\n') {
				str.insert(i+1, "  ");
			}
		}

		return str;
	}
};

int inorderCount(node *nod) {

	int sum = 0;
	if (nod != nullptr) {
		if (nod->getType() == 'd') {
			if (nod->getSpace() <= MAX_TAM) {
				sum += nod->getSpace();
			}

			for (int i=0; i<nod->numSons(); i++) {
				sum += inorderCount(nod->getSon(i));
			}
		}
	}

	return sum;
}

int main(int argc, char **argv) {

	// Check the amount of arguments
	if (argc != 2) {
		cerr <<"Error: Invalid amount of arguments." << endl;
		cerr << "Uso: Day7.1 <input>" << endl;
		exit(-1);
	}

	// Check if the input file can be opened
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << "Error opening file \"" << argv[1] << "\"." << endl;
		exit(-1);
	}


	node root, *nod;

	// Reading the input file
	string str;
	while (!fi.eof()) {
		if (fi.peek()=='$') {
			fi >> str;
			fi >> str;

			if (!strcmp(str.c_str(), "cd")) {
				fi >> str;
				if (!strcmp(str.c_str(), "/")) {
					nod = &root;
					getline(fi, str);
				}
				else {
					if (!strcmp(str.c_str(), "..")) {
						nod = nod->getFather();
						getline(fi, str);
					}
					else {
						bool found = false;
						for (int i=0; i<nod->numSons() && !found; i++) {
							if (!strcmp(nod->getSon(i)->getName().c_str(), str.c_str())) {
								nod = nod->getSon(i);
								found = true;
							}
						}
						getline(fi, str);
					}
				}
			}

			if (!strcmp(str.c_str(), "ls")) {
				getline(fi, str);

				while (fi.peek()!='$' && !fi.eof()) {
					if (fi.peek() == 'd') {
						fi >> str;
						fi >> str;

						node n('d', nod, str);
						nod->addSon(n);
						getline(fi, str);
					}
					else {
						fi >> str;
						int s = stoi(str);
						fi >> str;

						node n('f', nod, str, s);
						nod->addSon(n);
						getline(fi, str);
					}
				}
			}
		}
	}

	// Show the result
	cout << "The sum of the total sizes of those directories is " 
	<< inorderCount(&root) << endl;

	// Show the tree
	// cout << root.ToString();

	return 0;
}