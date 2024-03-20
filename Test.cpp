#include <iostream>
using namespace std;


class A {
public :
	int data = 10;

};

void red2(A a) {
	a.data++;

}


int main() {
	
	A* a = new A();
	A a2;

	red2(a2);

	std::cout << a2.data << std::endl;
	

	return 0;

}



