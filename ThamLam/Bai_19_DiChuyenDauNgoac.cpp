/*
Cho một xâu kí tự S chỉ bao gồm các kí tự '(' hoặc kí tự ')'. S có độ dài là số chẵn có giá trị N. Xâu S gồm N / 2 kí tự mở ngoặc và N / 2 kí tự đóng ngoặc. Ở mỗi thao tác các bạn được lựa chọn 1 kí tự bất kì của S để đưa về vị trí đầu tiên hoặc vị trí cuối cùng của dãy. Các bạn hãy xác định số thao tác tối thiểu cần thực hiện để tạo được 1 xâu dấu ngoặc hợp lệ. Một số ví dụ về xâu hợp lệ : (), (((()))), ()((()))...

Đầu vào
Một dòng duy nhất chứa xâu S

Giới hạn
1<=N<=10^6

Đầu ra
In ra số thao tác tối thiểu cần thực hiện

Ví dụ :
Input 01
)))((((())
Output 01
3
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    int dem = 0, soThaoTac = 0;
    for(char c : s)
    {
        if(c == '(')
        {
            dem++;
        }else {
            dem--;
        }

        if(dem < 0)
        {
            soThaoTac++;
            dem = 0;
        }
    }

    cout << soThaoTac;
    return 0;
}