#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1000005
using namespace std;

int N;

int dp[INF];
int his[INF];

int main() {
	fill(dp, dp + INF, INF);
	dp[1] = 0;
	his[1] = 0;

	cin >> N;
	
	for (int i = 2; i <= N; i++) {
		dp[i] = min({ dp[i - 1] +1,dp[i] }); his[i] = i - 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2]) dp[i] = min(dp[i], dp[i / 2]) +1, his[i] = i / 2;
		if (i % 3 == 0 && dp[i] > dp[i / 3]) dp[i] = min(dp[i], dp[i / 3]) + 1, his[i] = i / 3;
	}

	cout << dp[N] << endl;
	int cur = N;
	cout << N << " ";
	while (cur!=1) {
		
		cout << his[cur] << " ";
		cur = his[cur];

	}


	return 0;
}