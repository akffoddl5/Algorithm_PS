#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class cmp {
public:
	bool operator() (int a, int b) {

		if (abs(a) > abs(b)) return true;
		else if (abs(a) < abs(b)) return false;
		else {
			if (a > b) return true;
			else return false;

		}

	}

};


int N;
int main() {

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> N;
	priority_queue<int, vector<int>, cmp> q;
	while (N--) {
		int a;
		cin >> a;

		if (a == 0) {
			if (q.empty()) cout << "0\n";
			else cout << q.top() << endl, q.pop();
		}
		else {
			q.push(a);
		}

	}
	


	return 0;
}