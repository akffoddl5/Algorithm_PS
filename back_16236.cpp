#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;



int main() {
	int n;
	cin >> n;
	int** mp = new int*[n];
	for (int i = 0; i < n; i++) {
		mp[i] = new int[n] {0};
	}

	map<int, vector<pair<int, int>> > history;
	
	
	//����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			//�̹� history �� ���� ���
			if (history.find(mp[i][j]) != history.end()) {
				history[mp[i][j]].push_back({ i,j });
			}
			//history �� ���� ���
			else {
				vector<pair<int, int>> tmp;
				tmp.push_back({ i,j });
				history[mp[i][j]] = tmp;
			}
		}
	}

	//�� ��ġ �ϴ� ã��
	pair<int, int> myPos = history[9][0];
	int myLevel = 2;
	int myEXP = 0;

	while (true) {
		//������ ��ġ ���� ����� ��ã��
		
		

		break;
		

	}

	return 0;

}