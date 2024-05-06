#include <iostream>
using namespace std;

// Các nước đi hợp lệ của quân mã
int move_x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int move_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool solveKnightTour(int board[10][10], int row, int col, int move_count, int n) {
    // Đánh dấu ô hiện tại
    board[row][col] = move_count;

    // Nếu đã đi hết các ô, trả về true
    if (move_count == n * n) {
        return true;
    }

    // Thử các nước tiếp theo từ ô hiện tại
    for (int i = 0; i < 8; i++) {
        int next_row = row + move_x[i];
        int next_col = col + move_y[i];

        // Nếu nước đi hợp lệ, gọi đệ quy
        if (isValid(next_row, next_col, n, board)) {
            if (solveKnightTour(board, next_row, next_col, move_count + 1, n)) {
                return true;
            }
        }
    }

    // Bỏ đánh dấu ô hiện tại
    board[row][col] = 0;
    return false;
}

bool isValid(int row, int col, int n, int board[10][10]) {
    // Kiểm tra ô có nằm trong giới hạn bàn cờ và chưa được đánh dấu
    return (row >= 1 && row <= n+1 && col >= 1 && col <= n+1 && board[row][col] == 0);
}

int countKnightTour(int n) {
    int board[10][10];

    // Đánh dấu 1 vào các ô nằm ngoài bàn cờ
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || i == n+1 || j == 0 || j == n+1) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }

    int count = 0;

    // Thử đi từ ô (1, 1)
    if (solveKnightTour(board, 1, 1, 1, n)) {
        count++;
    }

    return count;
}

int main() {
    int n = 8;
    cout << "So phuong an quay ma o ban co " << n << "x" << n << " la: " << countKnightTour(n) << endl;
    return 0;
}
