#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int* p1 = new int[4]{0,1,0, -1};
int* p2 = new int[4]{1,0,-1, 0 };

int main() {
	
	int N;
	cin >> N;
	int** mp = new int* [N];
	for (int i = 0; i < N; i++) {
		mp[i] = new int[N] {0};
	}

	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		mp[a-1][b-1] = 1;
	}

	int current_X = 0;
	int current_Y = 0;
	int current_tail_X = 0;
	int current_tial_Y = 0;
	int current_dir = 0;
	mp[0][0] = 2;

	int L;
	cin >> L;

	
	deque<pair<int, int>> q2;
	q2.push_front({ current_X, current_Y });


	int current_time = 0;
	int answer = 0;
	for (int i = 0; i < L+1; i++) {
		int a;
		char b;
		if (i == L)  a = 101;
		else {
			cin >> a >> b;
			a = a - current_time;

		}
		

		bool needBreak = false;

		

		for (int j = 0; j < a; j++) {
			int next_X = current_X + p1[current_dir];
			int next_Y = current_Y + p2[current_dir];
			current_time++;
			answer++;
			//cout << " 현재 .." << next_X << " , " << next_Y << endl;

			if (next_X >= 0 && next_Y >= 0 && next_X < N && next_Y < N) {
				//빈칸일떄 꼬리 엎애고 머리 앞으로 옮기고
				
				if (mp[next_X][next_Y] == 0) {
					current_X = next_X;
					current_Y = next_Y;
					mp[current_X][current_Y] = 2;
					q2.push_front({ current_X ,current_Y });
					pair<int, int> tmp = q2.back();
					q2.pop_back();
					mp[tmp.first][tmp.second] = 0;
				}
				//사과일떄 꼬리 냅두고 머리 앞으로 옮기고
				else if (mp[next_X][next_Y] == 1) {
					
					current_X = next_X;
					current_Y = next_Y;
					mp[current_X][current_Y] = 2;
					q2.push_front({ current_X ,current_Y });
				}
				//자기 몸일때
				else if (mp[next_X][next_Y] == 2) {
					needBreak = true;
					break;
				}
			}
			else {
				needBreak = true;
				break;
			}
			
		}

		if (needBreak) break;

		if (b == 'D') current_dir += 1;
		else if (b == 'L') current_dir -= 1;

		if (current_dir < 0) current_dir = 3;
		else if (current_dir > 3) current_dir = 0;
	}

	cout << answer;
	return 0;

}