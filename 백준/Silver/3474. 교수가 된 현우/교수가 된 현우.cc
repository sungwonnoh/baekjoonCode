#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	int t, n;
	int two, five;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		two = 0, five = 0;
		for (int j = 2; j <= n; j*=2) {//소인수 분해 했을때 2,5의 개수
			two += n / j;
		}
		for (int j = 5; j <= n; j*=5) {
			five += n / j;
		}
		cout << min(two, five) << "\n";
	}
	return 0;
}