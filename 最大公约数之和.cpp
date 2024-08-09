#include <bits/stdc++.h>
using namespace std;
int gcd(int n, int m) {
	if(m == 0) return n;
	return gcd(m, n % m);
}
int main() {
	int n, a[100000];
	cin >> n;
	int l = 0;
	for(int i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			a[++l] = i;
			if(n / i != i) a[++l] = n / i;
		}
	}
	int ans = 0;
	for(int i = 1; i <= l; i ++) {
		for(int j = i + 1; j <= l; j++) {
			ans += (gcd(a[i], a[j])) % 10007;
		}
	}
	cout << ans;
	return 0;
}
