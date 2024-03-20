#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> mp;
vector<vector<int>> mp_copy;
vector<vector<bool>> visit;
vector<pair<int, int>> empty_place;
vector<pair<int, int>> virus_place;
int* p1 = new int[4]{ 1,0,-1,0 };
int* p2 = new int[4]{ 0,-1,0,1 };

int n, m;

void mp_copying() {
	mp_copy.clear();
	for (int i = 0; i < mp.size(); i++) {
		mp_copy.push_back(mp[i]);
	}
}

int bfs(vector<pair<int, int>> tmp_wall) {
	//fill(visit.begin(), visit.end(), false);
	mp_copying();
	//copy(mp.begin(), mp.end(), mp_copy.begin());

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mp_copy[i][j] << " ";
		}
		cout << endl;
	}*/
	
	for (int i = 0; i < tmp_wall.size(); i++) {
		mp_copy[tmp_wall[i].first][tmp_wall[i].second] = 1;
	}

	//cout << " ==========";


	queue<pair<int, int>> q;
	for (int i = 0; i < virus_place.size(); i++) {
		q.push(virus_place[i]);
		//cout << virus_place[i].first << " : " << virus_place[i].second;
	}
	
	while (!q.empty()) {
		int virus_X = q.front().first;
		int virus_Y = q.front().second;
		
		q.pop();


		for (int i = 0; i < 4; i++) {
			int next_X = virus_X + p1[i];
			int next_Y = virus_Y + p2[i];
			if (next_X >= 0 && next_Y >= 0 && next_X < n && next_Y < m ) {
				if (mp_copy[next_X][next_Y] == 0) {
					q.push({ next_X, next_Y });
					mp_copy[next_X][next_Y] = 2;

					//cout << next_X << " , " << next_Y << "      ";
				}
			}

		}


	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp_copy[i][j] == 0) answer++;
		}
	}

	return answer;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
			if (a == 0) {
				empty_place.push_back({ i,j });

			}
			else if (a == 2) {
				virus_place.push_back({ i,j });
			}

		}
		mp.push_back(tmp);
	}

	vector<bool> comb(empty_place.size(), true);
	for (int i = 0; i < 3; i++) {
		comb[i] = false;
	}
	int max = 0;
	do {
		vector<pair<int, int>> tmp_wall;
		for (int i = 0; i < empty_place.size(); i++) {
			if (!comb[i]) {
				tmp_wall.push_back(empty_place[i]);
			}
		}

		int answer = bfs(tmp_wall);
		if (max < answer) {
			max = answer;
		}
			


	} while (next_permutation(comb.begin(), comb.end()));

	cout << max;
	return 0;
}

