#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define ll long long

using namespace std;

int TC;
int N;

int main() {
	cin >> TC;

	while (TC--) {
		cin >> N;
		multiset<ll> s;
		for (int i = 0; i < N; i++) {
			char c;
			ll val;
			cin >> c >> val;
			if (c == 'I') {
				s.insert(val);
			}
			else {
				if (s.empty()) continue;
				if (val==1) {
					s.erase(prev(s.end()));
				}
				else {
					s.erase(s.begin());
				}
			}


		}

		if (s.empty()) cout << "EMPTY\n";
		else cout   << *prev(s.end()) << " " << *s.begin() << '\n';


	}

	return 0;
}