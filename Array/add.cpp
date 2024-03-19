#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a{5, 6, 9, 8, 5, 7};
    vector<int> b{9, 5, 6, 5, 7};
    int k = 0;
    vector<int> r;

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 && j >= 0) {
        int sum = a[i] + b[j] + carry;
        r.push_back(sum % 10);
        carry = sum / 10;
        i--;
        j--;
    }

    while (i >= 0) {
        int sum = a[i] + carry;
        r.push_back(sum % 10);
        carry = sum / 10;
        i--;
    }

    while (j >= 0) {
        int sum = b[j] + carry;
        r.push_back(
            sum % 10);
        carry = sum / 10;
        j--;
    }

    if (carry > 0) {
        r.push_back(carry);
    }

    // Print the result in reverse order to get the correct answer
    for (int i = r.size() - 1; i >= 0; i--) {
        cout << r[i];
    }

    return 0;
}











