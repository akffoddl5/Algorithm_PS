#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, K;
vector<int> v;
vector<int> dp;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	cin >> N >> K;
	dp = vector<int>(K + 1, 0);
	for (int i = 0, a; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}




	cout << s.size();

	return 0;
}