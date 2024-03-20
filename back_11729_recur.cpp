#include <iostream>
#include <algorithm>

using namespace std;

int recur(int a, int b, int num) {
	if (num == 1) {
		cout << a << " >" << b << endl;
		return 1;
	}
	//a를 c로 옮기려면
	//a-1 을 b로 옮기고
	int val1 = recur(a, 6-a-b, num - 1);
	//a를 c로 옮기고
	int val2 = recur(a, b, 1);
	//b를 c로 옮겨야해
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