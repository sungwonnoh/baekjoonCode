#include <iostream>
using namespace std;

long long padoban[101] = { 0,1,1 };
long long p(int n) {
	if (n < 3) {
		return padoban[n];
	}
	else if(padoban[n]==0) {
		padoban[n] = p(n - 2) + p(n - 3);
	}
	return padoban[n];
}
int main() {
	int t,n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << p(n) << "\n";
	}
	return 0;
}