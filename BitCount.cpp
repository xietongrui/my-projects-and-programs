#include <iostream>
using namespace std;
int CountBit(int x) {
	if(x == 0) return 0;
	return CountBit(x & x - 1) +1;
}
int main() {
	int n;
	cin >> n;
	cout << CountBit(n);
	return 0;
}
