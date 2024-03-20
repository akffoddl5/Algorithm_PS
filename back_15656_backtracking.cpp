#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a, b;
vector<int> v;
vector<int> his;

void track(int n) {
	if (n == b) {
		for (int i = 0; i < his.size(); i++) {
			cout << his[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (auto a : v) {
		his.push_back(a);
		track(n + 1);
		his.pop_back();

	}

	

}
	
int main() {
	cin >> a >> b;
	for (int i = 0, c; i < a; i++) {
		cin >> c;
		v.push_back(c);
	}

	sort(v.begin(), v.end());

	track(0);

	return 0;
}