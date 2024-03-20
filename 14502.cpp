//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//vector<vector<int>> mp;
//vector<vector<int>> mp_copy;
//vector<vector<bool>> visit;
//vector<pair<int, int>> empty_place;
//vector<pair<int, int>> virus_place;
//int* p1 = new int[4]{ 1,0,-1,0 };
//int* p2 = new int[4]{ 0,-1,0,1 };
//
//int n, m;
//
//int bfs(vector<pair<int, int>> tmp_wall);
//
//int main() {
//
//	
//
//	cin >> n >> m;
//	
//	for (int i = 0; i < n; i++) {
//		vector<int> tmp;
//		for (int j = 0; j < m; j++) {
//			int a;
//			cin >> a;
//			tmp.push_back(a);
//			if (a == 0) {
//				empty_place.push_back({ i,j });
//
//			}
//			else if (a == 2) {
//				virus_place.push_back({ i,j });
//			}
//
//		}
//		mp.push_back(tmp);
//	}
//
//	vector<bool> comb(empty_place.size(), true);
//	for (int i = 0; i < 3; i++) {
//		comb[i] = false;
//	}
//
//	do {
//		vector<pair<int, int>> tmp_wall;
//		for (int i = 0; i < empty_place.size(); i++) {
//			if (!comb[i]) {
//				tmp_wall.push_back(empty_place[i]);
//			}
//		}
//
//		int answer = bfs(tmp_wall);
//
//
//	} while (next_permutation(comb.begin(), comb.end()));
//
//
//	return 0;
//}
//
//int bfs(vector<pair<int, int>> tmp_wall) {
//	fill(visit.begin(), visit.end(), false);
//	
//	copy(mp.begin(), mp.end(), mp_copy.begin());
//
//	for (int i = 0; i < tmp_wall.size(); i++) {
//		mp_copy[tmp_wall[i].first][tmp_wall[i].second] = 1;
//	}
//	queue<pair<int, int>> q;
//	for (int i = 0; i < virus_place.size(); i++) {
//		q.push(virus_place[i]);
//	}
//
//	while (!q.empty()) {
//		int virus_X = q.front().first;
//		int virus_Y = q.front().second;
//
//		visit[virus_X][virus_Y] = true;
//
//		for (int i = 0; i < 4; i++) {
//			int next_X = virus_X = p1[i];
//			int next_Y = virus_Y = p2[i];
//			if (next_X >= 0 && next_Y >= 0 && next_X < n && next_Y < m && !visit[virus_X][virus_Y]) {
//				if (mp_copy[next_X][next_Y] == 0) {
//					q.push({ next_X, next_Y });
//				}
//			}
//
//		}
//
//
//	}
//
//
//}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> autocomplete(vector<string> inputs, string query) {
    vector<int> results;

    for (const string& input : inputs) {
        size_t len = min(input.size(), query.size());
        int score = 0;

        for (size_t i = 0; i < len; ++i) {
            if (input[i] == query[i]) {
                score++;
            }
            else {
                break;
            }
        }

        results.push_back(score);
    }

    return results;
}

int main() {
    vector<string> inputs = { "000", "1110", "01", "001", "110", "11" };
    vector<int > red = {1,2,3};
    int max = *max_element(red.begin(), red.end());
    
    cout << " >> "   <<  find(inputs.begin(), inputs.end(), "000") - inputs.begin();

    /*string query = "11";

    vector<int> output = autocomplete(inputs, query);
    

    for (int score : output) {
        cout << score << " ";
    }

    cout << endl;*/

    return 0;
}