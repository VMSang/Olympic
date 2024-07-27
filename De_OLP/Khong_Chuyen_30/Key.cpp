//tle
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 30;
int h, w, k;
char board[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pair<int, int>> cells;
vector<vector<pair<int, int>>> all_combinations;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w && board[x][y] == '#';
}

bool isConnected(vector<pair<int, int>>& combination) {
    int n = combination.size();
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            visited[i][j] = false;

    queue<pair<int, int>> q;
    q.push(combination[0]);
    visited[combination[0].first][combination[0].second] = true;

    int count = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        count++;
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny) && !visited[nx][ny] && find(combination.begin(), combination.end(), make_pair(nx, ny)) != combination.end()) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return count == n;
}

void generateCombinations(vector<pair<int, int>>& current, int start) {
    if (current.size() == k) {
        if (isConnected(current)) {
            all_combinations.push_back(current);
        }
        return;
    }
    for (int i = start; i < cells.size(); ++i) {
        current.push_back(cells[i]);
        generateCombinations(current, i + 1);
        current.pop_back();
    }
}

int main() {
    cin >> h >> w >> k;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> board[i][j];
            if (board[i][j] == '#') {
                cells.push_back({i, j});
            }
        }
    }

    vector<pair<int, int>> current;
    generateCombinations(current, 0);

    cout << all_combinations.size() << endl;

    return 0;
}
