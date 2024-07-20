#include <bits/stdc++.h>
using namespace std;

/*
Ý tưởng: sử dụng mảng đánh dấu để có thể kiểm tra nhanh
 một số có phải là số nguyên tố hay không sau khi sàng

điều kiện: tối thiểu thì chỉ số của mảng đánh dấu này phải lớn hơn hoặc bằng N
Sàng Số Nguyên Tố Trên Đoạn: cần xây dựng được mảng đánh dấu có cỡ R - L + 1.


*/
const int N = 10000001; // N = 10^7
int prime[N]; // == 0
void sang_Co_Ban() {
	prime[0] = prime[1] = 1; //khong phai snt
	for (int i = 2; i * i <= N; i++) {
		if (prime[i] == 0) {
			for (int j = i * i; j <= N; j += i) {
				prime[j] = 1;
			}
		}
	}
}

void sang_TrenDoan_L_R(int L, int R) {
	//cac pha tu cua prime khai bao o day KHONG co gia tri == 0
	int prime[R - L + 1]; //chỉ tạo số ô nhớ trong khoảng l->r chứ không tạo r+1 ô
	for (int i = 0; i <= R - L; i++) {
        prime[i] = 1;
    }
	for (int i = 2; i*i <= R; i++) {
		//đánh dấu từ bội đầu tiên trong đoạn L->R, nếu L <=2 thì đi từ 4 vì 2 là snt nhỏ nhất
		// tìm max của i * i với số nhỏ nhất ≥ L mà chia hết cho i để giảm số vòng lặp không cần thiết
		//nếu l nhỏ thì đi từ i*i còn lớn thi đi tại bội đó luôn
		for (int j = max(i * i, ((L + i - 1) / i) * i); j <= R; j += i) {
			prime[j -  L] = 0;
		}
	}
	
	for (int i = max(2, L); i <= R; i++) {
		if (prime[i - L])
			cout << i << " ";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sang_Co_Ban();
	sang_TrenDoan_L_R(10, 41);

	return 0;
}