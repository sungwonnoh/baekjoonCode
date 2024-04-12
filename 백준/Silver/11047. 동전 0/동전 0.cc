#include <iostream>
using namespace std;

int main() {
	int n, k;
	int coin[11];
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (coin[i] <= k) {
			cnt += k / coin[i];
			k %= coin[i];
		}
		if (k == 0) {
			break;
		}
	}
	cout << cnt;
	return 0;
}