#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> v_chicken;
	vector<pair<int, int>> v_house;
	vector<int> v_val;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				v_house.push_back({ i,j });

			}
			else if (a == 2) {
				v_chicken.push_back({ i,j });

			}
		}
	}

	vector<bool> comb(v_chicken.size(), true);
	int del_num = v_chicken.size()- m;
	for (int i = 0; i < del_num; i++) {
		comb[i] = false;
	}

	long answer = 500000 * 15;
	do {
		long min_sum = 0;
		for (int i = 0; i < v_house.size(); i++) {
			int min = 500000;
			int house_X = v_house[i].first;
			int house_Y = v_house[i].second;
			for (int j = 0; j < v_chicken.size(); j++) {
				if (!comb[j]) continue;
				int chick_X = v_chicken[j].first;
				int chick_Y = v_chicken[j].second;
				if (abs(house_X - chick_X) + abs(house_Y - chick_Y) < min) min = abs(house_X - chick_X) + abs(house_Y - chick_Y);

			}

			min_sum += min;
		}
		//cout << "min_sum : " << min_sum << endl;
		if (answer > min_sum) answer = min_sum;

	} while (next_permutation(comb.begin(), comb.end()));

	cout << answer;

	/*

	for (int i = 0; i < v_chicken.size(); i++) {
		int chick_X = v_chicken[i].first;
		int chick_Y = v_chicken[i].second;

		int val = 0;
		
		for (int j = 0; j < v_house.size(); j++) {
			int house_X = v_house[j].first;
			int house_Y = v_house[j].second;
			val += abs(house_X - chick_X) + abs(house_Y - chick_Y);
		}
		v_val.push_back(val);
	}*/

	//for (int i = 0; i < v_chicken.size(); i++) {
	//	cout << v_val[i] << endl;
	//}

	

}