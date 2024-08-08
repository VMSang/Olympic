#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int a[MAXN];

//ý tưởng: đi theo hai hướng trước sau, loại bỏ các idx không nằm trong k
//và idx có giá trị bỏ hơn a[hiện tại]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    //lưu giá vị trí của hợp lớn nhất nằm ở đầu tiên đầu tiên đảm bảo k đúng
    deque<int> dq;
    int result = INT_MIN;

    for (int i = 0; i < n; ++i) {
        // cout<<"i = "<<i<<endl;
        //bỏ các chỉ số không hợp lệ so với k
        while (!dq.empty() && dq.front() < i - k) {
            dq.pop_front();
        }
        if (!dq.empty()) {
            result = max(result, a[dq.front()] - a[i]);
            cout<<"res = "<<result<<endl;
        }
        //đi từ sau ra trước với chỗ nào giá trị nhỏ hơn thì bỏ hết
        while (!dq.empty() && a[dq.back()] <= a[i]) {
            dq.pop_back();
        }
        // for(auto x : dq) cout<<x<< " ";
        // cout<<endl;
        dq.push_back(i);
    }

    cout << result << "\n";
    return 0;
}
