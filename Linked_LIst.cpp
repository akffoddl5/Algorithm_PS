#include <iostream>
#include <algorithm>
#include <map>
#include <vector>



using namespace std;

class Red {
public:
	static inline int red = 666;

};

struct Node {
	Node* pre = NULL;
	Node* next = NULL;
	int data;
};

class CustomList {
	Node* head;
	Node* body;
public:
	CustomList() {
		head = new Node();
		body = NULL;
	}

	void addNode(int a);
	void addFrontNode(int a);
	void printList();
	void removeNode(int idx);

};

void CustomList::printList() {
	Node* nextNode = body;

	while (nextNode != NULL) {
		cout << nextNode->data << " -> ";
		nextNode = nextNode->next;
	}
}

//마지막 부분에 추가
void CustomList::addNode(int a) {
	if (body != NULL) {
		Node* nextNode = body;
		while (nextNode->next != NULL) {
			nextNode = nextNode->next;
		}

		Node* new_Node = new Node();
		new_Node->data = a;
		new_Node->pre = nextNode;
		nextNode->next = new_Node;

	}
	else {
		Node* new_Node = new Node();

		new_Node->data = a;
		new_Node->pre = head;
		body = new_Node;
	}
}

//특정 인덱스 제거
void CustomList::removeNode(int idx) {
	if (body != NULL) {
		Node* next_node = body;
		int cur_idx = -1;
		while (next_node != NULL) {
			cur_idx++;
			//cout << cur_idx;
			if (idx == cur_idx) {
				//cout << cur_idx << " !!" << (next_node->pre)->data <<" " << (next_node->data);
				//(next_node->pre)->data = 666;
				if (next_node != body) {
					(next_node->pre)->next = next_node->next;
					(next_node->next)->pre = next_node->pre;
					//delete(next_node);
				}
				else {
					body = next_node->next;
					body->pre = head;
				}

				break;
			}

			next_node = next_node->next;
		}
	}
}

//첫 부분에 추가
void CustomList::addFrontNode(int a) {
	//body 가 없을 경우 바디에
	if (body == NULL) {
		Node* new_Node = new Node();
		new_Node->data = a;
		body = new_Node;
		return;
	}
	//바디가 있을 경우 첫번째에
	Node* new_Node = new Node();
	new_Node->data = a;
	new_Node->pre = head;
	new_Node->next = body;
	body->pre = new_Node;
	body = new_Node;
}

int main() {
	CustomList* customList = new CustomList();
	customList->addNode(5);
	customList->addNode(3);
	customList->addNode(7);
	customList->addFrontNode(99);
	customList->removeNode(0);
	customList->printList();
	
	map<int, int> mp;
	vector<int> v;
	
	Red* r = new Red();
	r->red += 10;
	Red* r2 = new Red();

	cout << r->red << " << red 값  \n"; 
	cout << r2->red << " << red2 값  \n"; 

		if (__cplusplus == 201703L)
			std::cout << "C++17" << endl;
		else if (__cplusplus == 201402L)
			std::cout << "C++14" << endl;
		else if (__cplusplus == 201103L)
			std::cout << "C++11" << endl;
		else if (__cplusplus == 199711L)
			std::cout << "C++98" << endl;
		else
			std::cout << "pre-standard C++" << endl;
		return 0;
	
	cout << mp[1];
	return 0;
}