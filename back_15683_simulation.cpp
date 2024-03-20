#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> v;
vector<pair<int, int>> candi;
vector<int> his;
int min_val = 100;
int p1[4] = { 1,0,-1,0 };
int p2[4] = { 0,-1,0,1 };

vector<vector<int>> min_v;

void cal() {
	vector<vector<int>> tmp = v;

	for (int i = 0; i < his.size(); i++) {
		auto cur = candi[i];
		auto dir = his[i];
		auto dir_90 = (his[i] + 1) % 4;
		auto dir_180 = (his[i] + 2) % 4;
		auto dir_270 = (his[i] + 3) % 4;
		int cur_X = cur.first;
		int cur_Y = cur.second;
		if (v[cur_X][cur_Y] == 1) {
			int idx = 1;
			while (true) {
				int next_X = cur_X + p1[dir] * idx;
				int next_Y = cur_Y + p2[dir] * idx;
				if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M || v[next_X][next_Y] == 6) break;
				tmp[next_X][next_Y] = -1;
				idx++;
			}
			
		}
		else if (v[cur_X][cur_Y] == 2) {
			int idx = 1;
			while (true) {
				int next_X = cur_X + p1[dir] * idx;
				int next_Y = cur_Y + p2[dir] * idx;
				if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M || v[next_X][next_Y] == 6) break;
				tmp[next_X][next_Y] = -1;
				idx++;
			}

			idx = 1;
			while (true) {
				int next_X = cur_X + p1[dir_180] * idx;
				int next_Y = cur_Y + p2[dir_180] * idx;
				if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M || v[next_X][next_Y] == 6) break;
				tmp[next_X][next_Y] = -1;
				idx++;
			}
		}
		else if (v[cur_X][cur_Y] == 3) {
			int idx = 1;
			while (true) {
				int next_X = cur_X + p1[dir] * idx;
				int next_Y = cur_Y + p2[dir] * idx;
				if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M || v[next_X][next_Y] == 6) break;
				tmp[next_X][next_Y] = -1;
				idx++;
			}

			idx = 1;
			while (true) {
				int next_X = cur_X + p1[dir_90] * idx;
				int next_Y = cur_Y + p2[dir_90] * idx;
				if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M || v[next_X][next_Y] == 6) break;
				tmp[next_X][next_Y] = -1;
				idx++;
			}

		}
		else if (v[cur_X][cur_Y] == 4) {
			int idx = 1;
			while (true) {
				int next_X = cur_X + p1[dir] * idx;
				int next_Y = cur_Y + p2[dir] * idx;
				if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M || v[next_X][next_Y] == 6) break;
				tmp[next_X][next_Y] = -1;
				idx++;
			}

			idx = 1;
			while (true) {
				int next_X = cur_X + p1[dir_90] * idx;
				int next_Y = cur_Y + p2[dir_90] * idx;
				if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M || v[next_X][next_Y] == 6) break;
				tmp[next_X][next_Y] = -1;
				idx++;
			}

			idx = 1;
			while (true) {
				int next_X = cur_X + p1[dir_180] * idx;
				int next_Y = cur_Y + p2[dir_180] * idx;
				if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M || v[next_X][next_Y] == 6) break;
				tmp[next_X][next_Y] = -1;
				idx++;
			}

		}
		else if (v[cur_X][cur_Y] == 5) {
			int idx = 1;
			while (true) {
				int next_X = cur_X + p1[dir] * idx;
				int next_Y = cur_Y + p2[dir] * idx;
				if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M || v[next_X][next_Y] == 6) break;
				tmp[next_X][next_Y] = -1;
				idx++;
			}

			idx = 1;
			while (true) {
				int next_X = cur_X + p1[dir_90] * idx;
				int next_Y = cur_Y + p2[dir_90] * idx;
				if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M || v[next_X][next_Y] == 6) break;
				tmp[next_X][next_Y] = -1;
				idx++;
			}

			idx = 1;
			while (true) {
				int next_X = cur_X + p1[dir_180] * idx;
				int next_Y = cur_Y + p2[dir_180] * idx;
				if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M || v[next_X][next_Y] == 6) break;
				tmp[next_X][next_Y] = -1;
				idx++;
			}

			idx = 1;
			while (true) {
				int next_X = cur_X + p1[dir_270] * idx;
				int next_Y = cur_Y + p2[dir_270] * idx;
				if (next_X < 0 || next_Y < 0 || next_X >= N || next_Y >= M || v[next_X][next_Y] == 6) break;
				tmp[next_X][next_Y] = -1;
				idx++;
			}

		}


		//tmp °¹¼ö¼¼±â
		int cnt = 0;
		for (int j = 0; j < tmp.size(); j++) {
			for (int k = 0; k < tmp[0].size(); k++) {
				if (tmp[j][k] == 0) cnt++;
			}
		}
		//cout << cnt << endl;
		if (min_val > cnt) {
			min_v = tmp;
		}
		min_val = min(min_val, cnt);
		
	}

}

void track(int n) {
	if (n == candi.size()) {
		//ÃÖ¼Ò °¹¼ö °è»ê
		cal();
		/*for (auto a : his) {
			cout << a << " ";
		}*/
		//cout << endl;
		return;
	}

	for (int i = 0; i < 4; i++) {
		his.push_back(i);
		track(n + 1);
		his.pop_back();
	}

}

int main() {
	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M;
	
	v = vector<vector<int>>(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] >= 1 && v[i][j] <= 5) {
				candi.push_back({ i,j });
			}
		}
	}
	if (candi.empty()) {
		//tmp °¹¼ö¼¼±â
		int cnt = 0;
		for (int j = 0; j < v.size(); j++) {
			for (int k = 0; k < v[0].size(); k++) {
				if (v[j][k] == 0) cnt++;
			}
		}
		min_val = min(min_val, cnt);
	}
	track(0);

	cout  << min_val;
	
	//
	/*cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << min_v[i][j] << " ";
			
		}
		cout << endl;
	}*/
	
	return 0;
}