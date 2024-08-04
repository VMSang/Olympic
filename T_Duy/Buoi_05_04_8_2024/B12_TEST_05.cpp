#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long result = 0;
    int left = 0;
    unordered_map<int, int> count;

    for (int right = 0; right < n; right++) {
        count[a[right]]++;

        while (count.size() > k) {
            count[a[left]]--;
            if (count[a[left]] == 0) {
                count.erase(a[left]);
            }
            left++;
        }

        result += right - left + 1;
    }

    cout << result << endl;

    return 0;
}
