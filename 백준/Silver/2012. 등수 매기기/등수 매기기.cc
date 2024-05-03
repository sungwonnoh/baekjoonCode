#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* score = new int[n];
	
	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
	sort(score, score + n);

	long long sum = 0;

	for (int i = 0; i < n; i++) {
		sum += abs(score[i] - (i+1));
	}
	cout << sum;
	delete[] score;

	return 0;
}