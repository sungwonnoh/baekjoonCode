#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	int arr[15001] = {};
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int start = 0, end = n - 1;
	int sum = 0, answer = 0;
	while(start<end){
		sum = arr[start] + arr[end];
		if (sum < m) {
			start++;
		}
		else if (sum > m) {
			end--;
		}
		else if (sum == m) {
			answer++;
			start++;
			end--;
		}
	}
	cout << answer;
	return 0;
}