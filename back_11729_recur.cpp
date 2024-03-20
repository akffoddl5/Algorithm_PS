#include <iostream>
#include <algorithm>

using namespace std;

int recur(int a, int b, int num) {
	if (num == 1) {
		cout << a << " >" << b << endl;
		return 1;
	}
	//a�� c�� �ű����
	//a-1 �� b�� �ű��
	int val1 = recur(a, 6-a-b, num - 1);
	//a�� c�� �ű��
	int val2 = recur(a, b, 1);
	//b�� c�� �Űܾ���
	int val3 = recur(6 - a - b,b, num - 1);
	
	return val1 + val2 + val3;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	cout << recur(1,3, n);


	return 0;
}