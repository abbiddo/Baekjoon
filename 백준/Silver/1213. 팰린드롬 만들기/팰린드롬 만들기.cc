#include <iostream>
#include <algorithm>
using namespace std;

int arr[50];
int re[50];
int alpha[26];

int main() {
	string s;	cin >> s;
	int size = s.size();

	for (int i = 0; i < size; i++) {
		arr[i] = s[i];
		alpha[arr[i] - 'A'] ++;
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2) {
			if (size % 2 == 0) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			if (re[size/2]) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			re[size / 2] = i + 'A';
		}
	}

	sort(arr, arr + size);

	int index = 0;
	for (int i = 0; i < size/2; i++) {
		if (arr[index] == arr[index + 1]) {
			re[i] = re[size - i - 1] = arr[index];
			index += 2;
		}
		else {
			index++;
			i--;
		}
	}

	for (int i = 0; i < size; i++) {
		cout << (char)re[i];
	}
}