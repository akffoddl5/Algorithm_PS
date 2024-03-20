#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	
	int N, M;
	cin >> N >> M;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}



	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		reverse(v.begin() + a - 1, v.begin() + b );

		//for (int j = 0; j < N; j++) {
		//	printf("%d , ", v[j]);
		//}
		//cout << endl;
	}
	
	for (int i = 0; i < N; i++) {
		printf("%d ", v[i]);
	}

	

	return 0;

}