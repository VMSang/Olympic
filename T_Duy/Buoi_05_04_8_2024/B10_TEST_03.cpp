#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Tạo danh sách liên kết chứa các đứa trẻ từ 1 đến n
    list<int> children;
    for (int i = 1; i <= n; ++i) {
        children.push_back(i);
    }
    
    auto it = children.begin(); // Con trỏ bắt đầu từ đầu danh sách
    list<int> result; // Danh sách lưu thứ tự nhận kẹo
    
    while (!children.empty()) {
        // Đếm tới số 2 và loại bỏ đứa trẻ nhận kẹo
        for (int count = 1; count <= 2; ++count) {
            if (count == 2) {
                result.push_back(*it); // Thêm đứa trẻ nhận kẹo vào danh sách kết quả
                it = children.erase(it); // Xóa đứa trẻ khỏi danh sách
                if (it == children.end()) { // Nếu kết thúc danh sách, quay lại đầu
                    it = children.begin();
                }
                break; // Đã loại bỏ, không cần đếm thêm
            }
            ++it;
            if (it == children.end()) { // Nếu kết thúc danh sách, quay lại đầu
                it = children.begin();
            }
        }
    }
    
    // In kết quả
    for (int number : result) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
