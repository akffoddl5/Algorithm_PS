#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;
#define ll long long
const int VMAX = 501;
const ll MAX = LLONG_MAX / 20;
int N, M;

void spfa(vector<vector<pair<int, int>>>& mp) {
	vector<ll> dp(VMAX, MAX);
	vector<ll> inq(VMAX, 0);
	vector<ll> cnt(VMAX, 0);
	
	queue<int> q;
	q.push(1);
	cnt[1] = 1;
	dp[1] = 0;
	inq[1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop(); inq[u] = 0;
		//cout << "현재.. " << u << endl;
		for (auto [v,w] : mp[u]) {
			if (dp[u] + w < dp[v]) {
			//cout << v << " " << w << " 있고" << endl;
				dp[v] = dp[u] + w;


				if (!inq[v]) {
					inq[v] = 1;
					cnt[v]++;
					if (cnt[v] > N + 1) {
						cout << "-1";
						return;
					}
					q.push(v);

					/*for (int i = 1; i <= N; i++) {
						cout << dp[i] << " ";
					}
					cout << endl;*/
				}
			}

			
		}

	}
	for (int i = 2; i <= N; i++) {
		if (dp[i] == MAX) {
			cout << -1 << endl;
			continue;

		}
		cout << dp[i] <<'\n';
	}
	

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> N >> M;

	vector<vector<pair<int, int>>> mp(N + 1);
	
	for (int i = 0, a, b, c; i < M; i++) {
		cin >> a >> b >> c;
		mp[a].push_back({ b,c });
		//cout << b << " " << c << endl;
	}

	spfa(mp);


}