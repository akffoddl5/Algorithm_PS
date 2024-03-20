#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N, M;
vector<int> v;

int get_binary_search(int val) {

	int st = 0;
	int ed = v.size()-1;
	int left_idx = -1;
	int right_idx = v.size();
	while (st <= ed) {
		int mid = (st + ed) / 2;
		
		if (v[mid] > val) {
			ed = mid - 1;
		}
		else if (v[mid] == val) {
			ed = mid - 1;
			left_idx = mid;
		}
		else {
			st = mid + 1;
		}
	}

	if (left_idx == -1) return 0;
	
	st = 0;
	ed = v.size() - 1;
	while (st <= ed) {
		int mid = (st + ed) / 2;

		if (v[mid] > val) {
			ed = mid - 1;
		}
		else if (v[mid] == val) {
			st = mid + 1;
			right_idx = mid;
		}
		else {
			st = mid + 1;
		}
	}

	//cout << "left Idx : " << left_idx << " " << "right idx : " << right_idx << endl;

	return right_idx - left_idx + 1;
	

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