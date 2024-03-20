#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> input;
//vector<int> tmp;

void quick_sort(int st, int ed) {
	cout << "red";
	if (st + 1 >= ed) return;

	int pivot = input[st];
	int idx1 = st + 1;
	int idx2 = ed - 1;
	while (true) {
	cout << "red2" << " " << idx1 << " " << idx2;
		while (idx1 <= idx2 && input[idx1] <= pivot) idx1++;
		while (idx1 <= idx2 && input[idx2] >= pivot) idx2--;
		cout << "red3" << " " << idx1 << " " << idx2;;
		if (idx1 > idx2) break;
		swap(input[idx1], input[idx2]);
		cout << "red4" << " " << idx1 << " " << idx2;;
		cout << "red5" << " " << idx1 << " " << idx2;;
	}
	
	swap(input[st], input[idx2]);
	
	cout << endl << st << " " << idx2 << " " << ed << endl;

	quick_sort(st, idx2);
	quick_sort(idx2+1, ed);
	

	for (auto a : input) {
		cout << a << " ";
	}
	cout << endl;

}

int main() {
	cin >> N;

	int a;
	while (N--) {
		cin >> a;
		input.push_back(a);
	}

	//tmp = input;

	quick_sort(0, input.size());



	for (auto a : input) {
		cout << a << " ";
	}



	return 0;
}