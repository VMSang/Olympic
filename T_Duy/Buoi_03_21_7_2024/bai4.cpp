#include <bits/stdc++.h>
using namespace std;

int min_time_to_clean(int m, int n, vector<int>& robots, vector<int>& trash) {
    sort(robots.begin(), robots.end());
    sort(trash.begin(), trash.end());

    vector<int> max_time(m, 0);

    for (int i = 0; i < n; i++) {
        int min_dist = INT_MAX;
        int best_robot = 0;
        for (int j = 0; j < m; j++) {
            int dist = abs(robots[j] - trash[i]);
            if (dist < min_dist) {
                min_dist = dist;
                best_robot = j;
            }
        }
        max_time[best_robot] = max(max_time[best_robot], min_dist);
    }

    int result = *max_element(max_time.begin(), max_time.end());
    return result;
}

int main() {
    ifstream cin("GARBOT.INP");
    ofstream cout("GARBOT.OUT");
    int m, n;
    cin >> m >> n;

    vector<int> robots(m);
    vector<int> trash(n);

    for (int i = 0; i < m; i++) {
        cin >> robots[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> trash[i];
    }

    int result = min_time_to_clean(m, n, robots, trash);

    cout << result << endl;

    return 0;
}
