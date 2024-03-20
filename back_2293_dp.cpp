#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, K;
vector<int> v;
vector<int> dp;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	cin >> N >> K;
	dp = vector<int>(K + 1, 0);
	for (int i = 0, a; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}


	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - v[i] == 0) dp[j]++;
			else if (j - v[i] > 0 && dp[j - v[i]] > 0) dp[j]+= dp[j - v[i]];
		}
		for (auto a : dp) cout << a << " ";
		cout << endl;
	}

	cout << dp[K];

	return 0;
}