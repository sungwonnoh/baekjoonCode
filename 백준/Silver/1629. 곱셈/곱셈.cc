#include <iostream>
using namespace std;

long long int f(long long int a, long long int b, long long int c) {//모듈러 연산 분배법칙
	if (b == 0) {
		return 1;
	}
	if (b == 1) {
		return a % c;
	}
	long long k = f(a, b / 2, c) % c;

	if (b % 2 == 0) {//짝수일때 곱셈공식
		return (k * k) % c;
	}
	else {
		return k * k % c * a % c;
	}
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << f(a, b, c);
	return 0;
}
