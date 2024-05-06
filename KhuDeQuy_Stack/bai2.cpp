#include <iostream>
#include <stack>
using namespace std;

const int MAX_SIZE = 8;
int n;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool visited[MAX_SIZE][MAX_SIZE];

int countPaths() {
    stack<pair<int, int>> st;
    st.push(make_pair(0, 0));
    visited[0][0] = true;
    int count = 0;

    while (!st.empty()) {
        pair<int, int> curr = st.top();
        st.pop();

        if (curr.first == n - 1 && curr.second == n - 1) {
            count++;
        } else {
            for (int i = 0; i < 8; i++) {
                int x = curr.first + dx[i];
                int y = curr.second + dy[i];

                if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]) {
                    visited[x][y] = true;
                    st.push(make_pair(x, y));
                }
            }
        }
    }

    return count;
}

int main() {
    cout << "Nhap kich thuoc ban co: ";
    cin >> n;

    if (n < 1 || n >= MAX_SIZE) {
        cout << "Kich thuoc ban co khong hop le!" << endl;
        return 0;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            visited[i][j] = false;
        }
    }

    int paths = countPaths();
    cout << "So phuong an di chuyen la: " << paths << endl;

    return 0;
}