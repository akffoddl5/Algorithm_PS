#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

#define ll long long
const int VMAX = 501;
ll INF = LLONG_MAX/2;
int N, M;

using namespace std;

void spfa(vector < vector<pair<int, int>>>& mp) {
	vector<ll> inq(VMAX, 0);
	vector<ll> dp(VMAX, -INF);
	vector<ll> cnt(VMAX, 0);
	vector<ll> check(VMAX, 0);
	
	cnt[1] = 1;
	dp[1] = 0;
	inq[1] = 1;

	vector<vector<int>> node_his(VMAX);

	queue<int> q;
	vector<int> his;
	
	his.push_back(1);
	q.push(1);
	node_his[1].push_back(1);
	vector<int> answer_his;

	while (!q.empty()) {
		int u = q.front();  inq[u] = 0;
		bool needBreak = false;
		//cout << "현재 .." << u << endl;
		q.pop();
		for (auto [v, w] : mp[u]) {
			if (dp[u] + w > dp[v]) {
				

				dp[v] = dp[u] + w;
				/*for (int i = 1; i <= N; i++) {
					cout << dp[i] << " ,";
				}
				cout << endl;*/
				

				//cout << v << " " << w << endl;
				//cout << dp[N] << endl;
				auto cur = node_his[u];
				node_his[v] = node_his[u];
				node_his[v].push_back(v);

				if (!inq[v]) {
					inq[v] = 1;
					cnt[v]++;
					if (cnt[v] > N + 5) {
						//cout << -1;
						needBreak = true;
						break;
					}
					q.push( v );
					check[v] = 1;
				}

			}
		}

		if (needBreak) break;
		
	}

	if (check[N] == 1 && cnt[N] < N) {
		//cout << "일단 가긴 했네" << dp[N] ;
		for (int i = 0; i < node_his[N].size(); i++) {
			cout << node_his[N][i] << " ";
		}
		
	}
	else {
		cout << -1;
	}


}

int main() {
	//14:16 시작

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	vector < vector<pair<int, int>>> mp(VMAX);
	
	for (int i = 0, a, b, c; i < M; i++) {
		cin >> a >> b >> c;
		mp[a].push_back({ b,c });
	}

	spfa(mp);
}