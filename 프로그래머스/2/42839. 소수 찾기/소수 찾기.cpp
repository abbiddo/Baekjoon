#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2)
        if (num % i == 0) return false;
    return true;
}

int solution(string numbers) {
    unordered_set<int> primes; 
    sort(numbers.begin(), numbers.end());

    do {
        for (int i = 1; i <= numbers.size(); ++i) {
            string numStr = numbers.substr(0, i);
            int num = stoi(numStr);
            if (isPrime(num)) {
                primes.insert(num);
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return primes.size();
}