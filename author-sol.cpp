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
		// count the no. of elements which have a set bit in a particular k-th bit
		// since B[x] = A[i] & A[j], we need to check if a particular k-th bit will
		// be included in the final answer
		vector<int> set_bit_counter(30);
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			for (int i = 0; i < 30; i++) {
				if (num & (1 << i)) {
					set_bit_counter[i]++;
				}
			}
		}
		// if a particular k-th bit has more than 1 elements that have a set bit on it,
		// then include this bit in calculating the final answer
		int ans = 0;
		for (int i = 0; i < 30; i++) {
			if (set_bit_counter[i] > 1) {
				ans |= (1 << i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
