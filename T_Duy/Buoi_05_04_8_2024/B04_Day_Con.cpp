#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    int Q;
    cin >> Q;
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<int> prefix_sum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    for (const auto& query : queries) {
        int X = query.first;
        int Y = query.second;
        int max_sum = INT_MIN;

        for (int L = 1; L <= X; ++L) {
            for (int R = Y; R <= N; ++R) {
                int current_sum = prefix_sum[R] - prefix_sum[L - 1];
                max_sum = max(max_sum, current_sum);
            }
        }

        cout << max_sum << endl;
    }

    return 0;
}