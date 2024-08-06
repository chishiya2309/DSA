/*
Giả sử bạn là một người nghèo trong địa phương của bạn. Địa phương của bạn có duy nhất một cửa hàng bán lương thực. Cửa hàng của bạn mở cửa tất cả các ngày trong tuần ngoại trừ chủ nhật. Cho bộ ba số N, S, M thỏa mãn ràng buộc sau:

N : số đơn vị lương thực nhiều nhất bạn có thể mua trong ngày.

S : số lượng ngày bạn cần được sử dụng lương thực để tồn tại.

M : số đơn vị lương thực cần có mỗi ngày để bạn tồn tại.

Giả sử bạn đang ở ngày thứ 2 trong tuần và cần tồn tại trong S ngày tới. Hãy cho biết số lượng ngày ít nhất bạn cần phải mua lương thực từ của hàng để tồn tại hoặc bạn sẽ bị chết đói trong S ngày tới.

Đầu vào
1 dòng chứa 3 số N, S, M

Giới hạn
1<=S,N,M<=1000

Đầu ra
In ra số ngày ít nhất cần mua lương thực, nếu không thể mua đủ lương thực để tồn tại thì in ra -1

Ví dụ :
Input 01
7 5 7
Output 01
5
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, m;
    cin >> n >> s >> m;
    int nhuCau = s * m;
    int muaDuoc = (s - s/7)*n;
    if(muaDuoc < nhuCau)
    {
        cout << -1;
    }else 
    {
        int soNgay = nhuCau / n;
        if(nhuCau % n != 0)
        {
            soNgay++;
        }
        cout << soNgay;
    }
    return 0;
}