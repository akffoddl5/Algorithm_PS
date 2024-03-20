#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public :
	int level;

	Student(int _lev) {
		this->level = _lev;

	}
};

struct Student2 {
	string name;
	int age;

	Student2(string a, int b) {
		name = a;
		age = b;

	}

};

bool compare(Student a, Student b) {
	return a.level < b.level;
}

bool compare2(Student2 a, Student2 b) {
	return a.age > b.age;
}

int main() {
	int n, k;
	cin >> n >> k;     // 물건, 무게제한
	vector<pair<int, int>> v; //	 무게, 밸류
	int _w, _v;
	for (int i = 0; i < n; i++) {
		cin >> _w >> _v ;
		v.push_back(make_pair(_w, _v));
	}
	
	int** dp = new int*[n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[k + 1]{0};

	}

	
	
	//cout << v.size() << " " << n  << " " << k;
	for (int i = 0; i<k + 1; i++) {
		if (i >= v[0].first) dp[0][i] = v[0].second;
		//else dp[0][i] = 0;
	}




	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < k + 1; j++) {
			int current_weight = v[i].first;
			int current_val = v[i].second;
			int tmp = 0;
			if (j >= current_weight) {
				tmp = current_val;
			}
			int tmp2 = 0;
			if (j - current_weight >= 0 ) tmp2 = dp[i-1][j-current_weight] + current_val;
			dp[i][j] = max(max(tmp, dp[i - 1][j]), tmp2);
			//cout << tmp << " , " << tmp2  << ", " << dp[i - 1][j] << "  , " << dp[i][j] << ", " << current_weight << ", " << current_val << endl;

		}
	}

	//cout << endl;
	
	//cout << endl;
	int max = 0;
	for (int i = 0; i < k + 1; i++) {
		if (dp[n - 1][i] > max) max = dp[n - 1][i];

	}

	cout << max;
	

	return 0;

	
}