#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, t;
	cin >> n >> k;

	vector<int> sum(n+1);
	for (int i = 1; i <=n; i++) {
		cin >> t;
		sum[i] = t + sum[i - 1];
	}

	int ans = sum[k];
	for (int i = k; i <= n; i++) {//n-k개
		ans = max(ans, sum[i] - sum[i - k]);
	}
	cout << ans;

	return 0;
}