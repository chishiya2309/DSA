/*
Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy thực hiện in ra danh sách các đỉnh được duyệt theo thuật toán BFS(s).

Trong quá trình mở rộng của thuật toán BFS luôn ưu tiên mở rộng đỉnh có số thứ tự nhỏ hơn trước.

Đầu vào
Dòng đầu tiên là 2 số n và m và s, tương ứng với số lượng đỉnh, cạnh của đồ thị và đỉnh bắt đầu duyệt.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=s<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra các đỉnh được duyệt theo thuật toán BFS(s).

Chú ý trong quá trình mở rộng các đỉnh của thuật toán BFS luôn lựa chọn duyệt các đỉnh có thứ tự nhỏ hơn trước.

Ví dụ :
Input 01
Copy
5 9 4
5 1
4 5
2 5
4 3
1 4
2 4
5 3
1 5
1 2
Output 01
Copy
4 3 5 1 2
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}