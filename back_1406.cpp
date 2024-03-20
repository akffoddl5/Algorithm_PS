#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

void print_li(list<char>& li ) {
	//cout << "print_li \n";
	list<char>::iterator iter = li.begin();
	for (auto a = li.begin(); a != li.end(); a++) {
		cout << *a  ;
	}

}

int main() {
	//01:49 시작
	//문제 이해 01:50
	//02:10 끝
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	
	string input;
	cin >> input;
	int n;
	cin >> n;

	list<char> li ;
	for (int i = 0; i < input.size(); i++) {
		li.push_back(input[i]);
	}

	
	list<char>::iterator iter;
	iter = li.end();
	
	

	for (int i = 0; i < n; i++) {
		char command;
		cin >> command;

		if (command == 'L') {
			if (iter == li.begin()) continue;
			iter--;
		}
		else if (command == 'D') {
			if (iter == li.end()) continue;
			iter++;
		}
		else if (command == 'B') {
			if (iter == li.begin()) continue;
			iter--;
			iter = li.erase(iter);
			//수정해야댈지도
		}
		else {
			char tmp;
			cin >> tmp;
			iter = li.insert(iter, tmp);
			iter++;
		}
		
	}
	print_li(li);

	return 0;
	


}