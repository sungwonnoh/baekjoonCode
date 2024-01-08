#include <iostream>
#include <string>
using namespace std;

int main() {
	int n,k;//단어 개수, 성의 인덱스
	string name;
	int cnt[26] = {};

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name;
		k = name[0] - 97;
		cnt[k] += 1;
	}
	bool PREDAJA = true;//기권 여부
	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 5) {
			cout << (char)(i + 97);
			PREDAJA = false;//참가
		}
	}
	if (PREDAJA == true) {
		cout << "PREDAJA";
	}
	return 0;
}