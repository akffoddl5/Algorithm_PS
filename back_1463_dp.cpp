#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000005
using namespace std;
int n;
int dp[MAX];
int main() {
	cin >> n;
	fill(dp, dp + MAX, MAX);

	dp[n] = 0;
	for (int i = n; i >= 1; i--) {
		if (i % 3 == 0 && dp[i / 3] > dp[i]+1) dp[i / 3] = dp[i] + 1;
		if (i % 2 == 0 && dp[i / 2] > dp[i]+1) dp[i / 2] = dp[i] + 1;
		if (dp[i - 1] > dp[i] + 1) dp[i - 1] = dp[i] + 1;
	}

	cout << dp[1];

	
	return 0;
}