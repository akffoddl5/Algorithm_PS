#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> current;
int n, m, cnt;
void search(int person) {
	int min = n + 2;
	int idx = -1;
	string red = "red";
	
	for (int i = 0; i < current.size(); i++) {
		int x = current[i][0];
		int y = current[i][1];
		if (y == person) {
			if (x < min) idx = i;
		}
	}

	if (idx != -1) {
		cout << current[idx][0] << " , " << current[idx][1] << " 삭제\n";
		current.erase(current.begin() + idx);
	}

}

void move() {
	//우선 이동
	for (int i = 0; i < current.size(); i++) {
		int x = current[i][0];
		int y = current[i][1];
		int speed = current[i][2];
		int dir = current[i][3];
		
		if (dir == 1) {
			x -= speed;
			while (true) {
				if (x <= 0) {
					x = -x+1;
				}

				if (x > n) {

				}
			}
		}

	}


	//중복되는거 끼리 없애기

}

int main() {
	
	cin >> n >> m >> cnt;


	v.resize(n, vector<int>(m));
	current.resize(cnt, vector<int>(5));
	

	for (int i = 0; i < cnt; i++) {
		cin >> current[i][0];
		cin >> current[i][1];
		cin >> current[i][2];
		cin >> current[i][3];
		cin >> current[i][4];
	}

	int person_idx = 0;

	while (true) {
		person_idx++;
		if (person_idx == m+1) break;
		
		//사람 칸에 있는 가장 가까운 상어 골라내서 없애기
		search(person_idx);

		//상어 움직이기
		move();

		//겹치는거 잡아먹기


	}



	return 0;
}