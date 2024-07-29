#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i];
    }

    vector<int> lis;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), items[i]);
        if (it == lis.end()) {
            lis.push_back(items[i]);
        } else {
            *it = items[i];
        }
    }

    cout << lis.size() << endl;
    return 0;
}