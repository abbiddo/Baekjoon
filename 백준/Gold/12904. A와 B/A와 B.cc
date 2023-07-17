#include <iostream>
#include <algorithm>
using namespace std;

string input, output;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> input >> output;

	while (input.size() != output.size()) {
		if (output[output.size() - 1] == 'A') output = output.substr(0, output.size() - 1);
		else {
			output = output.substr(0, output.size() - 1);
			reverse(output.begin(), output.end());
		}
	}
	if (input == output) cout << 1;
	else cout << 0;
}