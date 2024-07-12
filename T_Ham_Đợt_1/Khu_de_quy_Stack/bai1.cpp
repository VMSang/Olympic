#include <iostream>
using namespace std;

void hoanVi(int arr[], int start, int end) {
    // Trường hợp cơ sở: nếu đã hoán vị xong, in ra hoán vị
    if (start == end ) {
        for (int i = 0; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    // Duyệt qua các số còn lại và hoán vị
    for (int i = start; i <= end; i++) {
        // Hoán đổi arr[start] và arr[i]
        swap(arr[start], arr[i]);

        // Gọi đệ quy cho các phần tử tiếp theo
        hoanVi(arr, start + 1, end);

        // Hoán đổi lại để khôi phục hoán vị ban đầu
        swap(arr[start], arr[i]);
    }
}

int main() {
    int n;
    cout << "Nhap n (n < 20): ";
    cin >> n;

    int arr[20];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    hoanVi(arr, 0, n - 1);

    return 0;
}