#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <optional>


using namespace std;

set<pair<int, int>> total;
int* p1 = new int[4]{ 1,0,-1,0 };
int* p2 = new int[4]{ 0,-1,0,1 };

void generate(vector<pair<int, int>>* _small_total, pair<int, int>* last_point) {

	optional<pair<int, int>> red;
	
	vector<pair<int, int>> tmp;
	optional<pair<int, int>> next_last_point ;
	//cout << last_point->first << " , " << last_point->second << " 를 기준으로 \n";
	for (auto a : *_small_total) {
		
		int x = a.first - last_point->first;
		int y = a.second - last_point->second;
		//small total 에 넣으면 for문에 영향 주니까 따로 빼서 하자	

		//cout << -y + last_point->first << " , " << x + last_point->second << endl;
		tmp.push_back({ -y + last_point->first, x + last_point->second });

		if (!next_last_point.has_value()) {
			//cout << "red";
			next_last_point = { -y + last_point->first,x + last_point->second };
		}
	}

	for (int i = 0; i < tmp.size(); i++) {
		(*_small_total).push_back(tmp[i]);
	}

	(*last_point) = next_last_point.value();
	


	//(*last_point).first
	//last_point -> first
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;


	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<pair<int, int>> small_total;
		pair<int, int> last_point;
		last_point = { x + p1[d], y + p2[d] };
		small_total.push_back({ x,y });
		small_total.push_back(last_point);

		for (int j = 1; j <= g; j++) {
			generate(&small_total, &last_point);

			/*for (int i = 0; i < small_total.size(); i++) {
				cout << "\n" << small_total[i].first << " " << small_total[i].second << endl;
			}*/

			//cout << endl;
		}

		for (auto a : small_total) {
			total.insert(a);
		
		}

	}

	int answer = 0;
	//cout << "일단 정답쪽은" << total.size();
	vector<vector<int>> v(101, vector<int>(101));
	for (auto a : total) {
		//cout << a.first << " , " << a.second << endl;
		v[a.first][a.second] = 1;
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (v[i][j] == 1 && v[i+1][j] == 1 && v[i][j+1] == 1 && v[i+1][j+1]) {
				answer ++ ;

			}
		}
	}

	cout << answer;
}