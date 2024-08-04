#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isBeautifulNumber(const string& s) {
    int num = stoi(s);
    return num % 2 == 0;
}

int countBeautifulNumbers(const string& s, int l, int r) {
    int count = 0;
    for (int i = l; i <= r; ++i) {
        for (int j = i; j <= r; ++j) {
            string numStr = s.substr(i, j - i + 1);
            if (isBeautifulNumber(numStr)) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int li, ri;
        cin >> li >> ri;
        cout << countBeautifulNumbers(s, li, ri) << " ";
    }

    return 0;
}
