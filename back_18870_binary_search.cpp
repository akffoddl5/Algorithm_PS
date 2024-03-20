#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;
int main() {
	
	cin >> N;

	while (N--) {
		int a;
		cin >>a;
		v.push_back(a);
	}

	vector<int> origin = v;
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()), v.end());
	/*for (auto a : v) {
		cout << a << " ";
	}*/

	for (auto a : origin) {
		cout << lower_bound(v.begin(), v.end(), a)- v.begin()<< " ";
		//cout << lower_bound(v.begin(), v.end(), a)- v.begin() << " ";
		

	}

	return 0;
}