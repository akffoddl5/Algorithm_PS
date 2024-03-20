#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int* p1 = new int[4]{ 1,0,-1,0 };
int* p2 = new int[4]{ 0,1,0,-1 };
vector<pair<int, int>> dfs_his;
vector<vector<char>> v(12, vector<char>(6));

void dfs(pair<int,int> cor, vector<vector<bool>>* his, char c) {

	int cur_X = cor.first;
	int cur_Y = cor.second;

	(*his)[cur_X][cur_Y] = true;

	dfs_his.push_back({ cur_X, cur_Y });


	for (int i = 0; i < 4; i++) {
		int next_X = cur_X + p1[i];
		int next_Y = cur_Y + p2[i];

		if (next_X >= 0 && next_Y >= 0 && next_X < 12 && next_Y < 6) {
			if ((*his)[next_X][next_Y] == false && v[next_X][next_Y] == c) {
				dfs({ next_X,next_Y }, his, c);
				(*his)[next_X][next_Y] = true;
			}
		}
	}
	
}

int main() {
	try {
		

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				cin >> v[i][j];
			}
		}


		/*for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				cout << v[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;*/

		int answer = 0;

		while (true) {
			vector<vector<bool>> his(12, vector<bool>(6));
			bool exist_erase = false;

			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 6; j++) {
					if (v[i][j] == '.') continue;
					else {
						dfs_his.clear();
						dfs({ i,j }, &his, v[i][j]);
						if (dfs_his.size() >= 4) {
							//cout << "찾았다 요놈" << dfs_his.size() << " " << v[i][j];
							//지우고
							for (int k = 0; k < dfs_his.size(); k++) {
								v[dfs_his[k].first][dfs_his[k].second] = '.';
							}

							exist_erase = true;
						}
					}
				}
			}

			//지운게 잇다면 내리고 계속 진행
			if (exist_erase) {
				answer++;

				for (int i = 0; i < 6; i++) {
					for (int j = 11; j >= 0; j--) {
						if (v[j][i] == '.') {
							for (int k = j - 1; k >= 0; k--) {
								if (v[k][i] != '.') {
									v[j][i] = v[k][i];
									v[k][i] = '.';
									break;
								}
							}
						}
					}
				}
			}
			//아니라면 멈춰
			else {
				cout << answer;
				break;
			}
			

		}

	}
	catch (exception e) {
		//cout << e.what() << endl;
	}

	return 0;

}