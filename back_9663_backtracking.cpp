#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mp[20][20];
vector<pair<int,int>> queen_list;
int n;
int ans;

bool avail(int a, int b) {

	for (auto t : queen_list) {
		if (t.first == a) return false;
		if (t.second == b) return false;
		if (t.first + t.second == a + b) return false;
		if (t.first - t.second == a - b) return false;
	}
	return true;
}

int track(int d) {

	if (d == n) ans++;

	for (int i = 1; i <= n; i++) {
		if (avail(d+1, i)) {
			queen_list.push_back({ d + 1,i });
			track(d + 1);
			queen_list.pop_back();
		}
	}


	return 0;
}

int main() {
	
	
	cin >> n;

	track(0);

	cout << ans;

}


