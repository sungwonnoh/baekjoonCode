#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> score;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		score.push_back(a);
	}
	sort(score.begin(), score.end());

	long long sum = 0;

	for (int i = 0; i < n; i++) {
		sum += abs(score[i] - (i+1));
	}
	cout << sum;

	return 0;
}