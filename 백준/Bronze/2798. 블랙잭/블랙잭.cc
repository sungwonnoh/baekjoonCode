#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int arr[100];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	int result = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i+1; j < n - 1; j++) {
			for (int k = j+1; k < n; k++) {
				cnt = arr[i] + arr[j] + arr[k];
				if (cnt <= m && result < cnt) {
					result = cnt;
				}
			}
		}
	}
	cout << result;
	return 0;
}