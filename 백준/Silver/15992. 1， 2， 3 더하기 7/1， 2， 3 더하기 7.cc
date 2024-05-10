#include <iostream>
using namespace std;

int dp[1001][1001];
int mod = 1000000009;
int main() {
	int t, n, m;
	cin >> t;

	dp[1][1] = dp[2][1] = dp[3][1] = 1;
	for (int i = 2; i < 1001; i++) {
		for (int j = 2; j < 1001; j++) {
			dp[i][j] += dp[i - 1][j - 1]; //i를 j개의 수를 이용해서 만듦
			dp[i][j] %= mod;
			if (i >= 2) {
				dp[i][j] += dp[i - 2][j - 1];
				dp[i][j] %= mod;
			}
			if (i >= 3) {
				dp[i][j] += dp[i - 3][j - 1];
				dp[i][j] %= mod;
			}
		}
	}
	//dp[i][j] = dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1];
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << dp[n][m] << "\n";
	}
	return 0;
}