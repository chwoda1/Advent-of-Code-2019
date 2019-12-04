#include <string>
#include <vector>
#include <iostream>

using namespace std;

int findValues(int,int);
int findValuesDP(int,int);

int main() {

	cout << findValues(165432, 707912) << endl;   // P1
	cout << findValuesDP(165432, 707912) << endl; // P2 
}

int findValues(int lbound, int ubound ) {

	int count = 0;

	for (int i = lbound; i < ubound; i++) {
	
		bool ok = true;
		auto tmp = to_string(i);

		for (int i = 1; i < tmp.size(); i++) {
			if (tmp[i-1]-'0' > tmp[i]-'0')
				ok = false;
		}

		bool okVal = false;

		for (int i = 1; i < tmp.size(); i++) {
			if (tmp[i-1]-'0' == tmp[i]-'0') {
				okVal = true;
			}
		}

		if (ok && okVal)
			count++;
	}

	return count;
}

int findValuesDP(int lbound, int ubound) {

	int count = 0;
	for (int j = lbound; j < ubound; j++) {

		bool ok1   = true;
		bool ok2   = false;

		auto tmp = to_string(j); 

		vector<int> dp(tmp.size(), 1); // longest match group

		for (int i = 1; i < tmp.size(); i++) {
			if (tmp[i-1]-'0' > tmp[i]-'0')
				ok1 = false;
			if (tmp[i-1]-'0' == tmp[i]-'0') 
				dp[i] = dp[i-1] + 1;
		}

		for (int i = 0; i < dp.size(); i++) {
			if (i+1 < dp.size() && (dp[i] == 2 && dp[i+1] == 1))
				ok2 = true;
			else if (dp[i] == 2 && i+1 == dp.size())
				ok2 = true;
		}

		if (ok1 && ok2)
			count++;

	}

	return count;
}
