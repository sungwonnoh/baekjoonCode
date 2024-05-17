#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[100001] = { 0, };
	for (int i = 0; i <= n; i++) {
		arr[i] = i; //초기화
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j* j<= i; j++) {//ㅓ는 1부터 i보다 작은 제곱수
			arr[i] = min(arr[i], arr[i - j * j]+1);//이전의 수인 arr[i-j*j]
		}
	}
	cout << arr[n];
	return 0;
}