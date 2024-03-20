#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll pow_(ll a, ll b, ll c) {
	
	if (b == 1) return a % c;
	//else if (b == 0) return 1;

	ll val = pow_(a, b / 2, c);


	if (b % 2 == 0) return val * val % c;
	return (val * val%c) * a % c;
	

	/*
	ll val = pow_(a, b / 2, c);
	val = val * val % c;

	if (b % 2 == 0) return val;
	return val * a %c;
	
	
	
	* */
	

}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;

	cout << pow_(a, b, c);

	return 0;
}