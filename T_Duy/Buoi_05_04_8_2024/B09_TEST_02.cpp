
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> segments(n);
    vector<int> contains(n, 0), contained_by(n, 0);
    
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (segments[i].first <= segments[j].first && segments[i].second >= segments[j].second) {
                    contains[i] = 1;
                }
                if (segments[j].first <= segments[i].first && segments[j].second >= segments[i].second) {
                    contained_by[i] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << contains[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < n; ++i) {
        cout << contained_by[i] << " ";
    }
    cout << endl;
    
    return 0;
}
