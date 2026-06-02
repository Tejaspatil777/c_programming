#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }

    sort(digits.begin(), digits.end(), greater<int>());

    for (int d : digits) {
        cout << d;
    }

    return 0;
}