#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s; 
int n, numQueries; 
int cnt[26][1000005];

int main () {
    cin >> n >> numQueries; 
    cin >> s; 

    // Đếm tần suất xuất hiện của từng chữ cái ở mỗi vị trí
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a'][i + 1]++;
    }

    // Tính tổng tần suất xuất hiện từ đầu đến vị trí i
    for (int c = 0; c < 26; c++) {
        for (int i = 1; i <= n; i++) {
            cnt[c][i] += cnt[c][i - 1]; 
        }
    }

    for (int query = 1; query <= numQueries; query++) {
        int l, r;
        cin >> l >> r;
        l++;
        r++;

        int numb = 0; 
        for (int c = 0; c < 26; c++) {
            if ((cnt[c][r] - cnt[c][l - 1]) % 2 == 1) {
                numb++; 
            }
        } 

        cout << numb / 2 << endl;
    }
    
    return 0; 
}
