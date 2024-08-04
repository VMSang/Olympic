#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> timSoNhoHonGanNhatBenTrai(const vector<int>& mang) {
    int n = mang.size();
    vector<int> ketqua(n, 0);
    stack<int> nganxep;
    
    for (int i = 0; i < n; ++i) {
        while (!nganxep.empty() && mang[nganxep.top()] >= mang[i]) {
            nganxep.pop();
        }
        
        if (!nganxep.empty()) {
            ketqua[i] = nganxep.top() + 1;  // chuyển đổi từ chỉ số 0-based sang 1-based
        } else {
            ketqua[i] = 0;
        }
        
        nganxep.push(i);
    }
    
    return ketqua;
}

int main() {
    int n;
    cin >> n;
    vector<int> mang(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> mang[i];
    }
    
    vector<int> ketqua = timSoNhoHonGanNhatBenTrai(mang);
    
    for (int i = 0; i < n; ++i) {
        cout << ketqua[i] << " ";
    }
    cout << endl;
    
    return 0;
}
