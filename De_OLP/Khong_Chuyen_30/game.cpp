//wa
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min_segments = n;
    for (int l = 0; l < n; l++) {
        int sum = 0;
        for (int r = l; r < n; r++) {
            sum += a[r];
            int current_sum = 0;
            int max_segment_length = 0;
            int segment_length = 0;
            bool valid_partition = true;
            for (int k = 0; k < n; k++) {
                current_sum += a[k];
                segment_length++;
                if (current_sum == sum) {
                    max_segment_length = max(max_segment_length, segment_length);
                    current_sum = 0;
                    segment_length = 0;
                } else if (current_sum > sum) {
                    valid_partition = false;
                    break;
                }
            }
            if (valid_partition && current_sum == 0) {
                min_segments = min(min_segments, max_segment_length);
            }
        }
    }

    cout << min_segments << endl;
    return 0;
}
