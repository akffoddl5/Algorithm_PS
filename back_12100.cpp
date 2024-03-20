#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long

using namespace std;

ll answer = 0;
int n;

ll getMax(vector<vector<ll>> __v) {

	ll _max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			_max = max(_max, __v[i][j]);
		}
	}

	return _max;

}

vector<vector<ll>> right(vector<vector<ll>> _v, int dir) {

	//���������� �ű��
	if (dir == 1) {
		//n���� �ٹݺ�
		for (int i = 0; i < n; i++) {
			vector<bool> _his(n, false);
			
			//������ 2�������� 0��������
			for (int j = n - 2; j >= 0; j--) {
				//�� �ڿ������� ����������
				for (int k = j + 1; k < n; k++) {
					if (_v[i][k] == 0) {
						_v[i][k] = _v[i][k-1];
						_v[i][k-1] = 0;
					}else if (_v[i][k-1] == _v[i][k] && !_his[k]) {
						_v[i][k] *= 2;
						_v[i][k-1] = 0;
						_his[k] = true;
						break;
					}
					else {
						break;
					}
				}

			}

		}

	}
	//�������� �ű��
	if (dir == 2) {
		//n���� �ٹݺ�
		for (int i = 0; i < n; i++) {
			vector<bool> _his(n, false);

			//������ 2�������� 0��������
			for (int j = 1; j < n; j++) {
				//�� �ڿ������� ����������
				for (int k = j - 1; k >=0; k--) {
					if (_v[i][k] == 0) {
						_v[i][k] = _v[i][k+1];
						_v[i][k+1] = 0;
					}
					else if (_v[i][k+1] == _v[i][k] && !_his[k]) {
						_v[i][k] *= 2;
						_v[i][k+1] = 0;
						_his[k] = true;
						break;
					}
					else {
						break;
					}
				}

			}

		}

	}

	//���� �ű��
	if (dir == 3) {
		//n���� �ٹݺ�
		for (int i = 0; i < n; i++) {
			vector<bool> _his(n, false);

			//������ 2�������� 0��������
			for (int j = 1; j < n; j++) {
				//�� �ڿ������� ����������
				for (int k = j - 1; k >= 0; k--) {
					if (_v[k][i] == 0) {
						_v[k][i] = _v[k+1][i];
						_v[k+1][i] = 0;
					}
					else if (_v[k+1][i] == _v[k][i] && !_his[k]) {
						_v[k][i] *= 2;
						_v[k+1][i] = 0;
						_his[k] = true;
						break;
					}
					else {
						break;
					}
				}

			}

		}

		


	}

	//�Ʒ��� �ű��
	if (dir == 4) {
		//n���� �ٹݺ�
		for (int i = 0; i < n; i++) {
			vector<bool> _his(n, false);

			//������ 2�������� 0��������
			for (int j = n-2; j >=0 ; j--) {
				//�� �ڿ������� ����������
				for (int k = j + 1; k < n; k++) {
					if (_v[k][i] == 0) {
						_v[k][i] = _v[k-1][i];
						_v[k-1][i] = 0;
					}
					else if (_v[k-1][i] == _v[k][i] && !_his[k]) {
						_v[k][i] *= 2;
						_v[k-1][i] = 0;
						_his[k] = true;
						break;
					}
					else {
						break;
					}
				}

			}

		}

	}


	//cout <<"========================="<< endl;
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << _v[i][j] << " ";
	//	}
	//	cout << endl;
	//}



	return _v;
}

void dfs(int point, vector<vector<ll>> _v) {
	point++;
	answer = max(answer, getMax(_v));
	
	if (point == 6) return;

	dfs(point, right(_v , 1));
	dfs(point, right(_v , 2));
	dfs(point, right(_v , 3));
	dfs(point, right(_v , 4));
	

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	vector<vector<ll>> v(n, vector<ll>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << v[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	dfs(0, v);

	cout << answer;
	return 0;
}