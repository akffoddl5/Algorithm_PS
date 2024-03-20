#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int N = 10;
//int input[10] = { 1, 2,3,4,5,6,7,8,9,10 };
int input[10] = { 1, 5, 2, 1, 5, 7, 4, 1, 2, 5 };

void bubble_sort() {
	bool need_loop = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-i-1; j++) {
			cout << i << " " << j << "ºñ±³\n";
			if (input[j] > input[j+1]) swap(input[j], input[j+1]), need_loop = true;
		}
		if (!need_loop) break;
	}
	
}

void selection_sort() {
	
	for (int i = 0; i < N; i++) {
		int max_val = input[0];
		int max_idx = 0;
		for (int j = 0; j < N-i; j++) {
			if (max_val < input[j]) max_val = input[j], max_idx = j ;
			
		}
		cout << "max_val : " << max_val << endl;
		swap(input[max_idx], input[N - 1 - i]);
	}

}

void counting_sort() {
	int dp[30]{};

	for (int i = 0; i < N; i++) {
		dp[input[i]]++;
	}

	for (int i = 0; i < 30; i++) {
		while (dp[i]--) {
			cout << i << " , ";
		}
	}
}

int main() {
	
	//bubble_sort();
	//selection_sort();
	counting_sort();

	//for (int i = 0; i < N; i++) cout << input[i] << " ";
	


	return 0;
}