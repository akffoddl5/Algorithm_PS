#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
#include <limits.h>

#define MAX INT_MAX
using namespace std;

int dik(int start, int get);
int* dp;
int N, E;
vector<vector<pair<int, int>>> v;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	cin >> N >> E;
	v = vector<vector<pair<int,int>>>(N + 1, vector < pair<int, int>>(1));
	dp = new int[N + 1];
	

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int need_a, need_b;
	cin >> need_a >> need_b;
	

	//cout << need_a << " " << need_b;

	//1->A
	int a = dik(1, need_a);


	//A->B A->N
	int b = dik(need_a, need_b);
	int c = dik(need_a, N);

	// B->N
	int d = dik(need_b, N);
	int e = dik(1, need_b);


	//1->A->B->N
	//1->B->A->N

	//cout << a + b + d;
	//cout << e + b + c;

	int answer = -1;

	if (a < MAX && b < MAX && d < MAX) {
		answer = a + b + d;
	}

	if (e < MAX && b < MAX && c < MAX) {
		if (answer == -1) answer = e + b + c;
		else answer = min(answer, e + b + c);
	}

	cout << answer;
	
	
	

	return 0;
}


int dik(int start, int get) {
	fill(dp, dp + N + 1, MAX);
	dp[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });
	
	while (!pq.empty()) {
		int point = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_point = v[cur][i].second + point;
			if (dp[next] > next_point) {
				dp[next] = next_point;
				pq.push({ next_point, next });
			}
			
		}

	}

	//cout << "일단 구했어" << dp[get];

	return dp[get];
}