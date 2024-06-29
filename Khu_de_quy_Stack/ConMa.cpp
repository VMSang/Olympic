#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int MAX_N = 14;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int a[MAX_N][MAX_N], n, Count = 1;

void Init() {
    cout << "n= ";
    cin >> n;
    memset(a, '1', sizeof(a));
    for (int i = 2; i < n + 2; i++)
        for (int j = 2; j < n + 2; j++)
            a[i][j] = 0;
}

void Print() {
    cout << "\nPhuong an thu " << Count++ << "\n";
    for (int i = 2; i < n + 2; i++) {
        for (int j = 2; j < n + 2; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

void Move(int i, int j, int d) {
    int s[1000],tmp=0,k;
    stack <pair<int,pair<int,int>>> st;
    st.push(make_pair(0,make_pair(i,j)));
    s[0]=0;
    a[i][j]=1;
    while (true) {
        for (k = tmp; k < 8; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (a[x][y] == 0) {
                i = x;
                j = y;
                a[i][j] = ++d;// ghi dấu con mã ở bước thứ d
                st.push(make_pair(k+1,make_pair(i,j)));//đẩy vào stack vị trí mới này
                break;
            }
        }
        tmp=0;//reset lại cho con mã tiếp theo
        if (k==8){// không tồn tại đường đi cho nước đi hiện tại
            a[i][j]=0;//đặt lại vị trí hiện tại =0
            d--;//giảm đi 1 nước đi
            tmp=st.top().first;
            st.pop();//bỏ nước đi ra khỏi stack
            i=st.top().second.first;// lấy lại tọa độ của nước đi trước để xét tiếp
            j=st.top().second.second;
        }
        if (d == n*n)//đủ số bước đi
            Print();
        if (d==0)// lùi về con hậu đầu tiên
            break;
    }
}

int main() {
    Init();
    Move(2, 2, 1);
    return 0;
}