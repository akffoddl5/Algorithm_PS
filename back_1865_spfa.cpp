#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

#define ll long long
#define VMAX 1001
using namespace std;

const ll INF = LLONG_MAX / 10;

ll N, M, W;
vector<vector < pair <ll, ll >>> mp;
vector<ll> dp(VMAX, INF);




bool spfa(int s = 1) {
	
	vector<ll> cnt(VMAX);
	bool inq[VMAX];
	fill(inq, inq + VMAX, false);

	int start = s;
	queue<int> q;
	q.push(start); inq[start] = true; cnt[start] = 1; dp[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop(); inq[u] = false;
		//cout << "flag1\n";
		for (auto red : mp[u]) {
			ll v = red.first;
			ll w = red.second;
			
		//cout << "flag2"<< dp[v] << " " << dp[u] + w <<"\n";
			if (dp[v] > dp[u] + w) {
				dp[v] = dp[u] + w;
				//cout << dp[v] << "로 초기화" << endl;
				if (!inq[v]) {
					if (++cnt[v] > N) return 0;
					q.push(v), inq[v] = 1;
				}
				//cout << "현재 .." << v << " " << w << " \n";
				//for (int i = 1; i <= N; i++) cout << dp[i] << ", ";
				//cout << endl;
			}
			
		}

		
	}

	

	for (int i = 1; i <= N; i++) if (dp[i] == INF) if(!spfa(i)) return 0;
	//for (int i = 1; i <= N; i++) if (dp[i] == INF) return spfa(i);
	return 1;

	
	


	return false;
}


int main() {
	int tc;
	cin >> tc;

	ios::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < tc; i++) {
		cin >> N >> M >> W;
		
		mp = vector<vector < pair <ll, ll >>>(VMAX, vector<pair<ll, ll>>(1));
		fill(dp.begin(), dp.end(), INF);


		for (int j = 0,a,b,c; j < M; j++) {
			cin >> a >> b >> c;
			mp[a].push_back({ b,c });
			mp[b].push_back({ a,c });
		}

		for (int j = 0, a, b, c; j < W; j++) {
			cin >> a >> b >> c;
			mp[a].push_back({ b,-c });
		}

		cout << (spfa()?"NO\n":"YES\n");
		
		
	}
	


	return 0;
}


/*
* #include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll MAX_V=1010, INF=LONG_LONG_MAX/4;
ll N, M, W, D[MAX_V];
vector<pair<int,int>> G[MAX_V];

bool SPFA(int s=1) {
	vector<int> inQ(MAX_V), cnt(MAX_V);
	queue<int> q;
	q.push(s), inQ[s]=1, cnt[s]=1, D[s]=0;
	while(!q.empty()) {
		int u=q.front(); q.pop(), inQ[u]=0;
		for(auto [v,w]:G[u]) if(D[u]+w < D[v]) {
			D[v]=D[u]+w;
			if(!inQ[v]) {
				if(++cnt[v]>=N) return 0;
				q.push(v), inQ[v]=1;
			}
		}
	}
	for(int i=1;i<=N;i++) if(D[i]==INF) return SPFA(i);
	return 1;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) {
		for(int i=0;i<MAX_V;i++) D[i]=INF, G[i].clear();
		cin >> N >> M >> W;
		for(int i=0,a,b,c;i<M;i++) cin >> a >> b >> c, G[a].push_back({b,c}), G[b].push_back({a,c});
		for(int i=0,a,b,c;i<W;i++) cin >> a >> b >> c, G[a].push_back({b,-c});
		cout << (SPFA()?"NO\n":"YES\n");
	}
	return 0;
}
*
*
* */