#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// basically, for every B[x] = A[i] & A[j] must be true
		// so that's why we need to check if at least two elements
		// have both set bits in a particular k-th bit
		vector<int> bit(32, 0);
		for (int i = 0; i < 32; i++) {
			bool checker = false;
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (a[j] & (1 << i)) {
					checker = true;
					cnt++;
				}
			}
			if (checker && cnt > 1) {
				bit[i] = 1;
			}
		}
		// for the OR operation (|), simply set the bit if an 
		// element has a set bit in this particular bit
		long long ans = 0;
		for (int i = 0; i < 32; i++) {
			if (bit[i] == 1) {
				ans += (1 << i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
