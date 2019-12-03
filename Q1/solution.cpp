#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

	ifstream infile("./test.txt");

	int a;
	int sum = 0;
	while (infile >> a) {
		int tmp = floor(a/3);
		sum += (tmp-2);
	}

	cout << "SOL: " << sum << endl;

	return 0;

}
