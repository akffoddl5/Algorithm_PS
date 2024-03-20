#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int** mp;

int main() {
	int n, m;
	cin >> n >> m;
	
	mp = new int* [n + 1];
	for (int i = 0; i < n + 1; i++) {
		mp[i] = new int[n + 1]{0};
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		mp[a][b] = 1;

	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//cout << mp[i][j] << " ";

		}

		//cout << endl;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (mp[i][k] + mp[k][j] > mp[i][j] && mp[i][k] !=0 && mp[k][j] != 0) {
					mp[i][j] = mp[i][k] + mp[k][j];
					for (int i = 1; i <= n; i++) {
						for (int j = 1; j <= n; j++) {
							//cout << mp[i][j] << " ";

						}

						//cout << endl ;
					}
					//cout << endl;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//cout << mp[i][j] << " ";

		}

		//cout << endl;
	}

	vector<int> answer;

	for (int i = 1; i <= n; i++) {
		vector<int> tmp;
		for (int j = 1; j <= n; j++) {
			if (mp[j][i] > 0 ||  mp[i][j] > 0) {
				tmp.push_back(j);
			}

		}
		if (tmp.size() >= n - 1) {
			//cout << i << " 알 수 있음" << endl;
			answer.push_back(i);
		}

	}

	cout << answer.size();


}