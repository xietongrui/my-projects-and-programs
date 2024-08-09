#include <bits/stdc++.h>
using namespace std;
int is_p[10000000], prime[10000000];
int tot = 0;
int ola(int n) {
	tot = 0;
	for(int i = 0; i <= n; i++) is_p[i] = 1;
	memset(prime, 0, sizeof(prime));
	is_p[0] = is_p[1] = 0;
	for(int i = 2; i <= n; i++) {
		if(is_p[i]) {
			prime[++tot] = i;
		}
		for(int j = 1; j <= n && prime[j] * i <= n; j++) {
			is_p[prime[j] * i] = 0;
			if(i % prime[j] == 0)break;
		}
	}
	return tot;
}
int main() {
	int n;
	cin >> n;
	int x = ola(n);
	cout << x << endl;
	for(int i = 1; i <= x; i++) {
		cout << prime[i] << ' ';
	}
	return 0;
}
