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
	
	
	//세팅
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			//이미 history 에 있을 경우
			if (history.find(mp[i][j]) != history.end()) {
				history[mp[i][j]].push_back({ i,j });
			}
			//history 가 없을 경우
			else {
				vector<pair<int, int>> tmp;
				tmp.push_back({ i,j });
				history[mp[i][j]] = tmp;
			}
		}
	}

	//내 위치 일단 찾기
	pair<int, int> myPos = history[9][0];
	int myLevel = 2;
	int myEXP = 0;

	while (true) {
		//나보다 덩치 작은 물고기 길찾기
		
		

		break;
		

	}

	return 0;

}