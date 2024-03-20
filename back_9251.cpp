#include <iostream>

using namespace std;


int** dp;
int main() {
	
	string a, b;
	cin >> a >> b;

	dp = new int* [a.length()];
	for (int i = 0; i < a.length(); i++) {
		dp[i] = new int[b.length()]{0};
	}


	for (int i = 0; i < a.length(); i++) {
		if (b[i] == a[0])
			dp[0][i] = 1;
	}

	


	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}


	//dp[i][j] = max(dp[i-1][j-1] ~ dp[i-1][0])
	//for(int i=1;i<)


	return 0;

}