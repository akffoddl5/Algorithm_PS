#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll recur(ll c, ll a, ll b) {
	if (c == 1) {
		if (a == 0 && b == 0) return 0;
		if (a == 0 && b == 1) return  1;
		if (a == 1 && b == 0) return  2;
		if (a == 1 && b == 1) return   3;
	}
	
	//if(c/2<=a && c/2 <= b) recur(c-1,a/2, b/2) 
	



	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	
	cout <<recur(1<<a, b, c);

	return 0;
}