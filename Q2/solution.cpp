#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ifstream infile("./test.txt");
	
	int a;
	vector<int> opcodes;

	while (infile >> a)
		opcodes.push_back(a);

	// modification
	opcodes[1] = 12;
	opcodes[2] = 2;

	for (int i = 0; i < opcodes.size(); i += 4) {
		
		if (opcodes[i] == 1) {
			
			auto op1 = opcodes[opcodes[i+1]];
			auto op2 = opcodes[opcodes[i+2]];

			opcodes[opcodes[i+3]] = op1 + op2;

		} else if (opcodes[i] == 2) {
		
			auto op1 = opcodes[opcodes[i+1]];
			auto op2 = opcodes[opcodes[i+2]];

			opcodes[opcodes[i+3]] = op1 * op2;

		} else if (opcodes[i] == 99) {
			cout << "HALT: " << opcodes[0] << endl;
			return -1;
		} else {
			cout << "SOMETHING WENT WRONG" << endl;
			return 0;
		}
	}

	return 0;
}
