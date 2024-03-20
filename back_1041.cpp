#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n;
	int* arr = new int[6];
	cin >> n;
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}

	if (n == 1) {
		long long answer = 0;
		int max = 0;
		for (int i = 0; i < 6; i++) {
			answer += arr[i];
			if (arr[i] > max) max = arr[i];
			
		}
		cout << answer - max;
		return 0;
	}
	
	vector<pair<int, pair<int, int> > > v3;
	vector<pair<int, int> >  v2;
	vector<int>  v1;
	v3.push_back(make_pair(0, make_pair(1, 3)));
	v3.push_back(make_pair(0, make_pair(1, 2)));
	v3.push_back(make_pair(1, make_pair(3, 5)));
	v3.push_back(make_pair(1, make_pair(2, 5)));
	v3.push_back(make_pair(5, make_pair(4, 3)));
	v3.push_back(make_pair(5, make_pair(4, 2)));
	v3.push_back(make_pair(0, make_pair(3, 4)));
	v3.push_back(make_pair(0, make_pair(2, 4)));

	v2.push_back(make_pair(0, 1));
	v2.push_back(make_pair(1, 5));
	v2.push_back(make_pair(5, 4));
	v2.push_back(make_pair(0, 4));
	v2.push_back(make_pair(4, 3));
	v2.push_back(make_pair(3, 1));
	v2.push_back(make_pair(1, 2));
	v2.push_back(make_pair(2, 4));
	v2.push_back(make_pair(0, 3));
	v2.push_back(make_pair(3, 5));
	v2.push_back(make_pair(5, 2));
	v2.push_back(make_pair(2, 0));

	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	int v3_min = 350, v2_min = 350, v1_min = 350;
	for (int i = 0; i < v3.size(); i++) {
		if (arr[v3[i].first] + arr[v3[i].second.first] + arr[v3[i].second.second] < v3_min) {
			v3_min = arr[v3[i].first] + arr[v3[i].second.first] + arr[v3[i].second.second];
		}
	}

	for (int i = 0; i < v2.size(); i++) {
		if (arr[v2[i].first] + arr[v2[i].second] < v2_min) {
			v2_min = arr[v2[i].first] + arr[v2[i].second];
		}
	}

	for (int i = 0; i < v1.size();  i++) {
		if (arr[v1[i]] < v1_min) {
			v1_min = arr[v1[i]];
		}
	}

	unsigned long long answer3 = 4;
	unsigned long long answer2 = 8 * n - 12;
	unsigned long long answer1 = (n - 1) * (n - 2) * 4 + (n-2) * (n-2);
	unsigned long long answer = answer3 * v3_min + answer2 * v2_min + answer1 * v1_min;
	/*cout << answer3 << " " << answer2 << " " << answer1 << " " << answer << endl;
	cout << v3_min << " " << v2_min << " " << v1_min << " " << answer << endl;*/
	cout << answer;
	




}