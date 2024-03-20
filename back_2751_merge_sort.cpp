#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> input;
vector<int> tmp;


void merge(int st, int ed) {
	

	int mid = (st + ed) / 2;
	int idx1 = st;
	int idx2 = mid;

	for (int i = st; i < ed; i++) {
		if (idx1 == mid) tmp[i] = input[idx2++];
		else if (idx2 == ed) tmp[i] = input[idx1++];
		else if (input[idx1] < input[idx2]) tmp[i] = input[idx1++];
		else tmp[i] = input[idx2++];
	}

	for (int i = st; i < ed; i++) {
		input[i] = tmp[i];
	}
	


}

void merge_sort(int st, int ed) {
	
	if (st + 1 == ed) return;
	
	int mid = (st + ed) / 2;

	merge_sort(st, mid);
	merge_sort(mid, ed);
	merge(st, ed);
}



int main() {
	cin >> N;

		int a;
	while (N--) {
		cin >> a;
		input.push_back(a);
	}

	tmp = input;

	merge_sort(0, input.size());

	

	for (auto a : input) {
		cout << a << " ";
	}
	


	return 0;
}