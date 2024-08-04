#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_length = 0;
    int start_index = 0;
    int result_start = -1;
    int result_length = 0;

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += a[j];
            int length = j - i + 1;
            if (sum == k * length) { // Trung bình là k
                if (length > max_length) {
                    max_length = length;
                    result_start = i;
                    result_length = length;
                }
            }
        }
    }

    if (result_start == -1) {
        cout << 0;
    } else {
        cout << result_start + 1 << " " << result_length; // Cần cộng thêm 1 để xuất vị trí bắt đầu
    }

    return 0;
}
