#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {

	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}

}

int main() {

	int n;
	cin >> n;

	queue<int> a;
	priority_queue<int> b;

	
	

	vector<pair<int, int>> v;


	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));

	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		//cout << v[i].first << " " << v[i].second << endl;
	}

	int answer = 1;
	int current_time = v[0].second;
	for (int i = 1; i < n; i++) {
		int _start = v[i].first;
		int _end = v[i].second;
		if (current_time <= _start) {
			answer++;
			current_time = _end;
		}

	}

	cout << answer;


	//sort(v, v.begin(), v.end());

	
}

