#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

char mp[1005][1005];
int fire_dist[1005][1005];
int my_dist[1005][1005];
int p1[4] { 1,0,-1,0 };
int p2[4]{ 0,-1,0,1 };
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	pair<int, int> fire_start;
	pair<int, int> my_start;
	queue<pair<int, int>> q;
	queue<pair<int, int>> q2;

	for (int i = 0; i < N + 3; i++) {
		for (int j = 0; j < M + 3; j++) {
			fire_dist[i][j] = -1;
			my_dist[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'F') {
				q.push({ i,j });
				fire_dist[i][j] = 0;
			}

			if (mp[i][j] == 'J') {
				q2.push({ i,j });
				my_dist[i][j] = 0;
			}
		}
	}

	
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++) {
			int next_X = cur.first + p1[i];
			int next_Y = cur.second + p2[i];
			if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M) continue;
			if (mp[next_X][next_Y] == '#' || fire_dist[next_X][next_Y] != -1) continue;

			fire_dist[next_X][next_Y] = fire_dist[cur.first][cur.second] + 1;
			q.push({ next_X, next_Y });
		}

	}

	
	
	
	while (!q2.empty()) {
		pair<int, int> cur = q2.front(); q2.pop();

		/*if (cur.first == N - 1 || cur.second == M - 1 || cur.first == 0 || cur.second == 0) {
			cout << my_dist[cur.first][cur.second] +1 ;
			return 0;
		}*/

		for (int i = 0; i < 4; i++) {
			int next_X = cur.first + p1[i];
			int next_Y = cur.second + p2[i];
			if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M) {
				cout << my_dist[cur.first][cur.second] + 1;
				return 0;
			}
			if (mp[next_X][next_Y] == '#' || my_dist[next_X][next_Y] != -1 || (fire_dist[next_X][next_Y] != -1 && fire_dist[next_X][next_Y] <= my_dist[cur.first][cur.second] + 1)) continue;

			my_dist[next_X][next_Y] = my_dist[cur.first][cur.second] + 1;
			q2.push({ next_X, next_Y });
		}

	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << fire_dist[i][j] << " ";
		}
		cout << endl;
	}
	cout << "==============\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << my_dist[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << "IMPOSSIBLE";

	return 0;
}