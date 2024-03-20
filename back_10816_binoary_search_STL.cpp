#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N, M;
vector<int> v;

int get_binary_search(int val) {

	auto a = lower_bound(v.begin(), v.end(), val);
	if (a == v.end()) return 0;
	auto b = upper_bound(v.begin(), v.end(), val);

	return b - a;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int a;
	while (N--) {
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	/*for (auto a : v) {
		cout << a << " ";
	}*/

	cin >> M;
	int b;
	while (M--) {
		cin >> b;
		cout << get_binary_search(b) << " ";
	}



	return 0;
}