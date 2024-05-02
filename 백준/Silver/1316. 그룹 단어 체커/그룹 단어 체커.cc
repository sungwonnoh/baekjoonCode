#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string word;
	int cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> word;
		int size = word.length();
		bool check = true;
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < j; k++) {
				if (word[j - 1] != word[j] && word[j] == word[k]) {
					check = false;
					break;
				}
			}
		}
		if (check) {
			cnt++;
		}
		
	}
	cout << cnt;
	return 0;
}