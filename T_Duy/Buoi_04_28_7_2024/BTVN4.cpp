#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    //chỉ có 1 ngôi nhà
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    vector<long long> dp(n);
    dp[0] = a[0];
    //chỉ có 2 ngôi nhà
    dp[1] = a[0] + a[1];    

    //từ hai ngôi nhà trở lên
    for (int i = 2; i < n; ++i) {
        // Không trộm ngôi nhà hiện tại, tức là thiệt hại tối đa là giống như khi xét ngôi nhà trước đó
        long long option1 = dp[i - 1];

        // Trộm ngôi nhà hiện tại nhưng không trộm ngôi nhà trước đó, tức là thiệt hại là giá trị của ngôi nhà hiện tại cộng với thiệt hại tối đa từ ngôi nhà cách 1 ngôi
        long long option2 = a[i] + dp[i - 2];

        // Trộm ngôi nhà hiện tại và ngôi nhà trước đó, tức là thiệt hại là tổng giá trị của hai ngôi nhà này cộng với thiệt hại tối đa từ ngôi nhà cách 2 ngôi
        // Chỉ thực hiện nếu i > 1 để tránh lỗi truy cập chỉ số âm
        long long option3 = (i > 2) ? (a[i] + a[i - 1] + dp[i - 3]) : (a[i] + a[i - 1]);

        // Lấy giá trị lớn nhất trong ba tùy chọn
        dp[i] = max({option1, option2, option3});
        
        // cout << "i = " << i << " " << "o1 = " << option1 << " " << "o2 = " << option2 << " " << "o3 = " << option3 << "\n";
        // cout<<dp[i]<<endl;
    }


    cout << dp[n - 1] << endl;

    return 0;
}
