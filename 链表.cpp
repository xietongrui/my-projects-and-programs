#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct node {
	T val; // 头结点的val中不存放任何内容 
	node *next; // 头结点的next域中存放第一个元素节点的地址,
				// 而指针h记录头结点的地址。 
};
template<typename T>
class LinkList{ 
private:
	node<T> *head;
public:
	LinkList(T x) {
		head->val = x;
		head->next = NULL;
	}
	
	/* Impotant!!!!!
	 * 在头结点前插入:
	 * p->next = head;
	 * head = p;
	 * head -> [1] -> [2] -> [3]
	 *     ^
	 *     p->next = head
	 *     head = p
	 */
	
	void shift(T x) {
		if(head != NULL) {
			node<T> *p = new node<T>;
			p->val = x;
			p->next = head;
			head = p;
		}
	}
	
	void un_shift() {
		node<T> *p = head;
		head = head->next;
		delete p;
	}
	
	void append(T x) {
		if(head != NULL) {
			node<T> *newNode = new node<T>;
			newNode->val = x;
			newNode->next = NULL;
			
			node<T> *p = head;
			while(p->next != NULL) {
				p = p->next;
			}
			p->next = newNode;
		} else {
			head->val = x;
			head->next = NULL;
		} 
	}
	
	void insert(int n, T x) {
		node<T> *newNode = new node<T>;
		newNode->val = x;
		newNode->next = NULL;
		if(n == 1) {
			newNode->next = head;
			head = newNode;
		} else {
			node<T> *p = head;
			for(int i = 1; i <= n - 2; i++) {
				p = p->next;
				if(p == NULL) {
					break;
				}
			}
			if(p == NULL) {
				throw "argument \"n\" is wrong!";
			} else {
				newNode->next = p->next;
				p->next = newNode;
			}
		}
	}
	
	void erase(T data) {
		node<T> *p = head, *pre = NULL;
		while(p != NULL) {
			if(data == p->val) {
				if(p == head) {
					head = p->next;
				} else {
					pre->next = p->next;
				}
				delete p;
				break;
			}
			pre = p;
			p = p->next; 
		}
	}
	
	void remove(int pos) {
		node<T> *p = head, *t;
		if(pos == 1) {
			if(head != NULL) {
				head = head->next;
				delete p;
			} else {
				throw "The list is empty!";
			}
		} else {
			for(int i = 1; i <= pos - 2; i++) {
				p = p->next;
				if(p == NULL) {
					break;
				}
			}
			if(p == NULL || p->next == NULL) {
				throw "argument \"n\" is wrong!";
			} else {
				t = p->next;
				p->next = t->next;
				delete t;
			}
		}
	}
	
	void print(char de = ' ') {
		node<T> *p = head;
		while(p != NULL) {
			cout << p->val << de;
			p = p->next;
		}
	}
	
	int length() {
		node<T> *p = head;
		int len = 0;
		while(p != NULL) {
			len++;
			p = p->next;
		}
		return len;
	}
	
	bool empty() {
		return head == NULL;
	}
};
int main() {
	LinkList<int> l(0);
	for(int i = 1; i <= 10; i++) {
		l.append(i);
	}
	l.erase(2);
	l.remove(5);
	l.print(' ');
	cout << endl;
	cout << l.length();
	return 0;
}
