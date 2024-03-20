#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;
	int n;
	int current_n = 0;
	cin >> k >> n;
	vector<char> v;
	char tmp;

	for (int i = 0; i < k; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	stack<char> st;
	for (int i = 0; i < v.size(); i++) {
		if (st.empty()) {

			st.push(v[i]);
			//cout << st.top() << " << push " << endl;
		}
		else {
			while (current_n < n) {
				if (st.empty()) break;
				//cout << "top : " << st.top() << " " << v[i]  << endl;
				if (st.top() < v[i]) {
					//cout << "pop" << endl;
					st.pop();
					current_n++;

				}
				else {
					break;
				}

				if (current_n >= n) break;
			}
			//cout << "puish : " << v[i];
			st.push(v[i]);
		}
	}

	for (int i = 0; i < n - current_n; i++) {
		st.pop();
	}

	string answer = "";
	stack<char> answer_st;

	while (!st.empty()) {
		//answer = st.top() + answer;
		answer_st.push(st.top());
		st.pop();
	}

	while (!answer_st.empty()) {
		//answer = st.top() + answer;
		cout << answer_st.top();
		answer_st.pop();
	}





	return 0;

}