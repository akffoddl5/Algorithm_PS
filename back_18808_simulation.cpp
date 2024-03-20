#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N, M, K;
vector<vector<vector<int>>> candi;
vector<vector<int>> mp;

bool check(int x, int y, const vector<vector<int>>& v) {
	//cout << x << " " << y << " " <<  v.size() << " " << v[0].size() <<"에서 체크 \n";
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			if (v[i][j] == 1) {
				//cout << "flag2.3 " << x+i << " "  << y+j << "\n" ;
				if (mp[x + i][y + j] == 1) {
					//cout << "red";
					return false;
				}
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			if (v[i][j] == 1) {
				mp[x + i][y + j] = 1;
			}
		}
	}

	return true;
}

vector<vector<int>> Rotate(const vector<vector<int>>& input) {
	//cout << "Rotate \n";
	vector<vector<int>> v;
	v = vector<vector<int>>(input[0].size(), vector<int>(input.size()));
	for (int j = 0; j < input.size(); j++) {
		for (int k = 0; k < input[0].size(); k++) {
			v[k][v[0].size() - 1 - j] = input[j][k];
		}
	}

	/*for (int j = 0; j < v.size(); j++) {
		for (int k = 0; k < v[0].size(); k++) {
			cout << v[j][k] << " ";
		}
		cout << endl;
	}*/
	//cout << "\n================= " << v.size() << " " << v[0].size() <<"\n";
	

	return v;
}

void Go() {
	for (int i = 0; i < candi.size(); i++) {
		//0,0 부터 size 계산해서 거기까지

		//세로는 N- size 세로까지

		vector<vector<int>> v = candi[i];

		for (int tc = 0; tc < 4; tc++) {
			if (tc != 0) v = Rotate(v);

			for (int j = 0; j <= N - static_cast<int>(v.size()); j++) {

				for (int k = 0; k <= M - static_cast<int>(v[0].size()); k++) {
						//cout << "이걸해?" << j << " " << k << " " << N - v.size() << " " << M - v[0].size() << " \n";
					if (check(j, k, v)) {
						//cout << "got it \n";
						goto A;
					}
				}
			}
		}
		A:;
		

	}

}

int main() {
	cin >> N >> M >> K;

	mp = vector<vector<int>>(N, vector<int>(M));

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		vector<vector<int>> v(a, vector<int>(b));
		
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < b; k++) {
				cin >> v[j][k];
			}
		}

		//vector<vector<int>> red = Rotate(v);
		//vector<vector<int>> red2 = Rotate(red);


		//for (int j = 0; j < red2.size(); j++) {
		//	for (int k = 0; k < red2[0].size(); k++) {
		//		cout << red2[j][k] << " ";
		//	}
		//	cout << endl;
		//}

		candi.push_back(v);
	}

	

	Go();
	int cnt = 0;
	for (int i = 0; i < mp.size(); i++) {

		for (int j = 0; j < mp[0].size(); j++) {
			//cout << mp[i][j] << " ";
			if (mp[i][j] == 1) cnt++;
		}
		//cout << endl;
	}

	cout  << cnt;

	return 0;
}