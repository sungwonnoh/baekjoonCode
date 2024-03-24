#include <iostream>
using namespace std;

int suga(int n) {
	int cnt = 0;
	while (n >= 0) {
		if (n % 5 == 0) {
			cnt += n / 5;
			return cnt;
		}
		n -= 3;
		cnt++;
	}
	return -1;
}
int main() {
	int n;
	cin >> n;
	int ans = suga(n);
	cout << ans;
	return 0;
}